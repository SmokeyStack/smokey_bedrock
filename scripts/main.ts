import { BlockLocation, CommandResult, Dimension, Direction, EntityHealthComponent, EntityInventoryComponent, EntityType, EntityTypes, EntityUnderwaterMovementComponent, Items, ItemStack, ItemType, ItemUseOnEvent, MinecraftBlockTypes, MinecraftEffectTypes, MinecraftItemTypes, Player, system, world } from "@minecraft/server";

world.events.entityHurt.subscribe((eventData) => {
    if (eventData.damageSource.damagingEntity == null)
        return;

    let entity_health: EntityHealthComponent = eventData.hurtEntity.getComponent("minecraft:health") as any;
    let entity_dimension: Dimension = eventData.hurtEntity.dimension;

    if (eventData.damageSource.cause != "entityAttack" && (eventData.damageSource.damagingEntity.typeId == "minecraft:warden") && (eventData.damage >= entity_health.current) && (eventData.hurtEntity.typeId == "minecraft:dolphin" || eventData.hurtEntity.typeId == "minecraft:bat"))
        entity_dimension.spawnItem(new ItemStack(MinecraftItemTypes.echoShard), new BlockLocation(Math.floor(eventData.hurtEntity.location.x), Math.floor(eventData.hurtEntity.location.y + 1), Math.floor(eventData.hurtEntity.location.z)));
});

async function detectHead(player: Player) {
    let result: Promise<CommandResult> = await player.runCommandAsync("execute if entity @s[hasitem=[{item=turtle_helmet,location=slot.armor.head}]]") as any;
    return (await result).successCount;
}

async function detectChest(player: Player) {
    let result: Promise<CommandResult> = await player.runCommandAsync("execute if entity @s[hasitem=[{item=smokey_bedrock:scute_chestplate,location=slot.armor.chest}]]") as any;
    return (await result).successCount;
}

async function detectPants(player: Player) {
    let result: Promise<CommandResult> = await player.runCommandAsync("execute if entity @s[hasitem=[{item=smokey_bedrock:scute_leggings,location=slot.armor.legs}]]") as any;
    return (await result).successCount;
}

async function detectBoots(player: Player) {
    let result: Promise<CommandResult> = await player.runCommandAsync("execute if entity @s[hasitem=[{item=smokey_bedrock:scute_boots,location=slot.armor.feet}]]") as any;
    return (await result).successCount;
}

system.runSchedule(() => {
    let players: Player[] = world.getAllPlayers();

    players.forEach(player => {
        let condition: boolean = player.hasTag('smokey_bedrock:has_head') && player.hasTag('smokey_bedrock:has_chest') && player.hasTag('smokey_bedrock:has_legs') && player.hasTag('smokey_bedrock:has_boots');
        if (condition) player.addEffect(MinecraftEffectTypes.resistance, 220, 3, false);

        let underwater_component: EntityUnderwaterMovementComponent = player.getComponent("underwater_movement") as any;

        let head_success: boolean = false;
        let head: Promise<number> = detectHead(player);
        head.then(() => { head_success = true; }, () => { })
            .finally(() => { if (head_success) player.addTag("smokey_bedrock:has_head"); else player.removeTag("smokey_bedrock:has_head") })

        let chest_success: boolean = false;
        let chest: Promise<number> = detectChest(player);
        chest.then(() => { chest_success = true; }, () => { })
            .finally(() => { if (chest_success) player.addTag("smokey_bedrock:has_chest"); else player.removeTag("smokey_bedrock:has_chest") })

        let pants_success: boolean = false;
        let pants: Promise<number> = detectPants(player);
        pants.then(() => { underwater_component.setCurrent(0.032); pants_success = true; }, () => { underwater_component.resetToDefaultValue(); })
            .finally(() => { if (pants_success) player.addTag("smokey_bedrock:has_pants"); else player.removeTag("smokey_bedrock:has_pants") })

        let boots_success: boolean = false;
        let boots: Promise<number> = detectBoots(player);
        boots.then(() => { boots_success = true; }, () => { })
            .finally(() => { if (boots_success) player.addTag("smokey_bedrock:has_boots"); else player.removeTag("smokey_bedrock:has_boots") })
    });
}, 20)

function updateLiquid(liquid_dimension: Dimension, block_location: BlockLocation) {
    liquid_dimension.fillBlocks(block_location.offset(0, -1, 0), block_location.offset(0, -1, 0), MinecraftBlockTypes.water, { matchingBlock: MinecraftBlockTypes.air.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(1, 0, 0), block_location.offset(1, 0, 0), MinecraftBlockTypes.water, { matchingBlock: MinecraftBlockTypes.air.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(0, 0, -1), block_location.offset(0, 0, -1), MinecraftBlockTypes.water, { matchingBlock: MinecraftBlockTypes.air.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(0, 0, 1), block_location.offset(0, 0, 1), MinecraftBlockTypes.water, { matchingBlock: MinecraftBlockTypes.air.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(0, 1, 0), block_location.offset(0, 1, 0), MinecraftBlockTypes.water, { matchingBlock: MinecraftBlockTypes.air.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(-1, 0, 0), block_location.offset(-1, 0, 0), MinecraftBlockTypes.water, { matchingBlock: MinecraftBlockTypes.air.createDefaultBlockPermutation() });

    liquid_dimension.fillBlocks(block_location.offset(0, -1, 0), block_location.offset(0, -1, 0), MinecraftBlockTypes.air, { matchingBlock: MinecraftBlockTypes.water.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(1, 0, 0), block_location.offset(1, 0, 0), MinecraftBlockTypes.air, { matchingBlock: MinecraftBlockTypes.water.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(0, 0, -1), block_location.offset(0, 0, -1), MinecraftBlockTypes.air, { matchingBlock: MinecraftBlockTypes.water.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(0, 0, 1), block_location.offset(0, 0, 1), MinecraftBlockTypes.air, { matchingBlock: MinecraftBlockTypes.water.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(0, 1, 0), block_location.offset(0, 1, 0), MinecraftBlockTypes.air, { matchingBlock: MinecraftBlockTypes.water.createDefaultBlockPermutation() });
    liquid_dimension.fillBlocks(block_location.offset(-1, 0, 0), block_location.offset(-1, 0, 0), MinecraftBlockTypes.air, { matchingBlock: MinecraftBlockTypes.water.createDefaultBlockPermutation() });
}

function bucketNautilus(eventData: ItemUseOnEvent, entity: string) {
    let player: Player = eventData.source as any;

    if (player.typeId != "minecraft:player") return;

    let offset: number[];

    switch (eventData.blockFace) {
        case Direction.down: offset = [0, -1, 0]; break;
        case Direction.east: offset = [1, 0, 0]; break;
        case Direction.north: offset = [0, 0, -1]; break;
        case Direction.south: offset = [0, 0, 1]; break;
        case Direction.up: offset = [0, 1, 0]; break;
        case Direction.west: offset = [-1, 0, 0]; break;
        default: break;
    }

    let item_dimension = eventData.source.dimension;
    item_dimension.getBlock(eventData.blockLocation.offset(offset[0], offset[1], offset[2])).setType(MinecraftBlockTypes.water);

    updateLiquid(item_dimension, eventData.blockLocation.offset(offset[0], offset[1], offset[2]));

    item_dimension.spawnEntity(entity, eventData.blockLocation.offset(offset[0], offset[1], offset[2]));

    let item: ItemStack = new ItemStack(MinecraftItemTypes.bucket, 1);
    let inventory_component: EntityInventoryComponent = eventData.source.getComponent("minecraft:inventory") as any;
    inventory_component.container.setItem(player.selectedSlot, item);
}

world.events.itemUseOn.subscribe((eventData) => {
    let item = eventData.item;

    let bucket_entities = new Map<ItemType, EntityType>();
    bucket_entities.set(Items.get("smokey_bedrock:bucket_nautilus"), EntityTypes.get("smokey_bedrock:nautilus"));
    bucket_entities.set(Items.get("smokey_bedrock:bucket_squid"), EntityTypes.get("minecraft:squid"));
    bucket_entities.set(Items.get("smokey_bedrock:bucket_squid_glow"), EntityTypes.get("minecraft:glow_squid"));


    if (!bucket_entities.has(Items.get(item.typeId))) return;

    bucketNautilus(eventData, bucket_entities.get(Items.get(item.typeId)).id);

});