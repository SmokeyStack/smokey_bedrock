import {
    CommandResult,
    Entity,
    EntityUnderwaterMovementComponent,
    Items,
    ItemStack,
    MinecraftEffectTypes,
    MinecraftItemTypes,
    Player,
    system,
    world
} from '@minecraft/server';
import {
    BUCKET_ENTITIES,
    placeBucketEntity,
    placeScentedCandle
} from 'item_use_on';

async function detectHead(player: Player): Promise<number> {
    let result: Promise<CommandResult> = (await player.runCommandAsync(
        'execute if entity @s[hasitem=[{item=turtle_helmet,location=slot.armor.head}]]'
    )) as any;
    return (await result).successCount;
}

async function detectChest(player: Player): Promise<number> {
    let result: Promise<CommandResult> = (await player.runCommandAsync(
        'execute if entity @s[hasitem=[{item=smokey_bedrock:scute_chestplate,location=slot.armor.chest}]]'
    )) as any;
    return (await result).successCount;
}

async function detectPants(player: Player): Promise<number> {
    let result: Promise<CommandResult> = (await player.runCommandAsync(
        'execute if entity @s[hasitem=[{item=smokey_bedrock:scute_leggings,location=slot.armor.legs}]]'
    )) as any;
    return (await result).successCount;
}

async function detectBoots(player: Player): Promise<number> {
    let result: Promise<CommandResult> = (await player.runCommandAsync(
        'execute if entity @s[hasitem=[{item=smokey_bedrock:scute_boots,location=slot.armor.feet}]]'
    )) as any;
    return (await result).successCount;
}

world.events.entityDie.subscribe((eventData) => {
    const ENTITY: Entity = eventData.deadEntity;

    if (
        ENTITY.typeId == ('minecraft:dolphin' || 'minecraft:bat') &&
        eventData.damageSource.cause != 'entityAttack' &&
        eventData.damageSource.damagingEntity.typeId == 'minecraft:warden'
    ) {
        ENTITY.dimension.spawnItem(
            new ItemStack(MinecraftItemTypes.echoShard),
            ENTITY.location
        );
    }
});

system.runInterval(() => {
    const PLAYERS: Player[] = world.getAllPlayers();

    PLAYERS.forEach((player) => {
        let condition: boolean =
            player.hasTag('smokey_bedrock:has_head') &&
            player.hasTag('smokey_bedrock:has_chest') &&
            player.hasTag('smokey_bedrock:has_legs') &&
            player.hasTag('smokey_bedrock:has_boots');
        if (condition)
            player.addEffect(MinecraftEffectTypes.resistance, 220, 3, false);

        let underwater_component: EntityUnderwaterMovementComponent =
            player.getComponent('underwater_movement') as any;

        let head_success: boolean = false;
        let head: Promise<number> = detectHead(player);
        head.then(
            () => {
                head_success = true;
            },
            () => {}
        ).finally(() => {
            if (head_success) player.addTag('smokey_bedrock:has_head');
            else player.removeTag('smokey_bedrock:has_head');
        });

        let chest_success: boolean = false;
        let chest: Promise<number> = detectChest(player);
        chest
            .then(
                () => {
                    chest_success = true;
                },
                () => {}
            )
            .finally(() => {
                if (chest_success) player.addTag('smokey_bedrock:has_chest');
                else player.removeTag('smokey_bedrock:has_chest');
            });

        let pants_success: boolean = false;
        let pants: Promise<number> = detectPants(player);
        pants
            .then(
                () => {
                    underwater_component.setCurrent(0.032);
                    pants_success = true;
                },
                () => {
                    underwater_component.resetToDefaultValue();
                }
            )
            .finally(() => {
                if (pants_success) player.addTag('smokey_bedrock:has_pants');
                else player.removeTag('smokey_bedrock:has_pants');
            });

        let boots_success: boolean = false;
        let boots: Promise<number> = detectBoots(player);
        boots
            .then(
                () => {
                    boots_success = true;
                },
                () => {}
            )
            .finally(() => {
                if (boots_success) player.addTag('smokey_bedrock:has_boots');
                else player.removeTag('smokey_bedrock:has_boots');
            });
    });
}, 20);

world.events.itemUseOn.subscribe((eventData) => {
    const ITEM: ItemStack = eventData.item;

    if (BUCKET_ENTITIES.has(Items.get(ITEM.typeId)))
        placeBucketEntity(
            eventData,
            BUCKET_ENTITIES.get(Items.get(ITEM.typeId)).id
        );

    switch (ITEM.typeId) {
        case 'minecraft:candle':
            placeScentedCandle(eventData);
            break;
        default:
            break;
    }
});
