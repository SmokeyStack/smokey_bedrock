import {
    Entity,
    EntityDamageCause,
    EntityEquippableComponent,
    EntityUnderwaterMovementComponent,
    EquipmentSlot,
    ItemStack,
    Player,
    system,
    world
} from '@minecraft/server';
import {
    BUCKETABLE_ENTITIES,
    BUCKET_ENTITIES,
    pickupBucketEntity,
    placeBucketEntity,
    placeScentedCandle
} from 'item_use_on';

const cooldown = {};

world.afterEvents.entityDie.subscribe((eventData) => {
    const ENTITY: Entity = eventData.deadEntity;

    if (
        (ENTITY.typeId == 'minecraft:bat' ||
            ENTITY.typeId == 'minecraft:dolphin') &&
        eventData.damageSource.cause == EntityDamageCause.sonicBoom
    ) {
        ENTITY.dimension.spawnItem(
            new ItemStack('minecraft:echo_shard', 1),
            ENTITY.location
        );
    }
});

system.runInterval(() => {
    const PLAYERS: Player[] = world.getAllPlayers();

    PLAYERS.forEach((player) => {
        const EQUIPMENT: EntityEquippableComponent = player.getComponent(
            'minecraft:equippable'
        ) as any;

        let condition: boolean =
            EQUIPMENT.getEquipment(EquipmentSlot.Head).typeId ==
                'minecraft:turtle_helmet' &&
            EQUIPMENT.getEquipment(EquipmentSlot.Chest).typeId ==
                'smokey_bedrock:scute_chestplate' &&
            EQUIPMENT.getEquipment(EquipmentSlot.Legs).typeId ==
                'smokey_bedrock:scute_leggings' &&
            EQUIPMENT.getEquipment(EquipmentSlot.Feet).typeId ==
                'smokey_bedrock:scute_boots';

        if (condition)
            player.addEffect('resistance', 220, {
                amplifier: 3,
                showParticles: false
            });

        let underwater_component: EntityUnderwaterMovementComponent =
            player.getComponent('underwater_movement') as any;

        if (
            EQUIPMENT.getEquipment(EquipmentSlot.Legs).typeId ==
            'smokey_bedrock:scute_leggings'
        )
            underwater_component.setCurrentValue(0.032);
        else underwater_component.resetToDefaultValue();
    });

    Object.keys(cooldown).forEach((key) => {
        if (cooldown[key] < Date.now()) delete cooldown[key];
    });
}, 20);

world.afterEvents.playerInteractWithBlock.subscribe((eventData) => {
    const ITEM: ItemStack = eventData.itemStack;

    if (cooldown.hasOwnProperty(eventData.player.name)) return;

    cooldown[eventData.player.name] = Date.now() + 500;

    if (BUCKET_ENTITIES.has(ITEM.typeId))
        placeBucketEntity(eventData, BUCKET_ENTITIES.get(ITEM.typeId));

    switch (ITEM.typeId) {
        case 'minecraft:candle':
            placeScentedCandle(eventData);
            break;

        default:
            break;
    }
});

world.afterEvents.entityHurt.subscribe((eventData) => {
    let entity: Entity = eventData.hurtEntity;

    if (
        entity.typeId == 'minecraft:axolotl' &&
        eventData.damageSource.cause == EntityDamageCause.sonicBoom
    ) {
        entity.dimension.spawnEntity(
            'minecraft:warden<minecraft:spawn_emerging>',
            entity.location
        );
        entity.remove();
    }
});

world.afterEvents.playerInteractWithEntity.subscribe((eventData) => {
    const ITEM: ItemStack = eventData.itemStack;

    if (
        ITEM.typeId == 'minecraft:water_bucket' &&
        BUCKETABLE_ENTITIES.has(eventData.target.typeId)
    ) {
        pickupBucketEntity(
            eventData,
            BUCKETABLE_ENTITIES.get(eventData.target.typeId)
        );
        eventData.target.remove();
    }
});
