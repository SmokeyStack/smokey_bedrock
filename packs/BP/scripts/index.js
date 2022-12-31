import { world, ItemStack, MinecraftItemTypes, BlockLocation } from "@minecraft/server";

world.events.entityHurt.subscribe((eventData) => {
    if (eventData.cause != 'entityAttack' && (eventData.damagingEntity.typeId == "minecraft:warden") && (eventData.damage >= eventData.hurtEntity.getComponent("minecraft:health").current) && (eventData.hurtEntity.typeId == "minecraft:dolphin" || eventData.hurtEntity.typeId == "minecraft:bat"))
        world.getDimension("overworld").spawnItem(new ItemStack(MinecraftItemTypes.echoShard), new BlockLocation(Math.floor(eventData.hurtEntity.location.x), Math.floor(eventData.hurtEntity.location.y + 1), Math.floor(eventData.hurtEntity.location.z)));
});