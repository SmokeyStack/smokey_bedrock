import { world, ItemStack, MinecraftItemTypes, BlockLocation, system, MinecraftEffectTypes } from "@minecraft/server";

world.events.entityHurt.subscribe((eventData) => {
    if (eventData.damageSource.damagingEntity == null)
        return;

    if (eventData.damageSource.cause != 'entityAttack' && (eventData.damageSource.damagingEntity.typeId == "minecraft:warden") && (eventData.damage >= eventData.hurtEntity.getComponent("minecraft:health").current) && (eventData.hurtEntity.typeId == "minecraft:dolphin" || eventData.hurtEntity.typeId == "minecraft:bat"))
        world.getDimension("overworld").spawnItem(new ItemStack(MinecraftItemTypes.echoShard), new BlockLocation(Math.floor(eventData.hurtEntity.location.x), Math.floor(eventData.hurtEntity.location.y + 1), Math.floor(eventData.hurtEntity.location.z)));
});

async function detectHead(player) {
    let result = await player.runCommandAsync("execute if entity @s[hasitem=[{item=turtle_helmet,location=slot.armor.head}]]");
    return result.successCount;
}

async function detectChest(player) {
    let result = await player.runCommandAsync("execute if entity @s[hasitem=[{item=smokey_bedrock:scute_chestplate,location=slot.armor.chest}]]");
    return result.successCount;
}

async function detectPants(player) {
    let result = await player.runCommandAsync("execute if entity @s[hasitem=[{item=smokey_bedrock:scute_leggings,location=slot.armor.legs}]]");

    return result.successCount;
}

async function detectBoots(player) {
    let result = await player.runCommandAsync("execute if entity @s[hasitem=[{item=smokey_bedrock:scute_boots,location=slot.armor.feet}]]");
    return result.successCount;
}

system.runSchedule(() => {
    let players = world.getAllPlayers();

    players.forEach(player => {
        let condition = player.hasTag('smokey_bedrock:has_head') && player.hasTag('smokey_bedrock:has_chest') && player.hasTag('smokey_bedrock:has_legs') && player.hasTag('smokey_bedrock:has_boots');
        if (condition) player.addEffect(MinecraftEffectTypes.resistance, 220, 3, false);

        let head_success = false;
        let head = detectHead(player);
        head.then(() => { head_success = true; },
            () => { })
            .finally(() => {
                if (head_success) {
                    player.addTag('smokey_bedrock:has_head');
                } else player.removeTag('smokey_bedrock:has_head')
            })

        let chest_success = false;
        let chest = detectChest(player);
        chest.then(() => { chest_success = true; },
            () => { })
            .finally(() => {
                if (chest_success) {
                    player.addTag('smokey_bedrock:has_chest');
                } else player.removeTag('smokey_bedrock:has_chest')
            })

        let pants_success = false;
        let pants = detectPants(player);
        pants.then(() => { player.getComponent('underwater_movement').setCurrent(0.032); pants_success = true; },
            () => { player.getComponent('underwater_movement').resetToDefaultValue(); })
            .finally(() => {
                if (pants_success) {
                    player.addTag('smokey_bedrock:has_legs');
                } else player.removeTag('smokey_bedrock:has_legs')
            })

        let boots_success = false;
        let boots = detectBoots(player);
        boots.then(() => { boots_success = true; },
            () => { })
            .finally(() => {
                if (boots_success) {
                    player.addTag('smokey_bedrock:has_boots');
                } else player.removeTag('smokey_bedrock:has_boots')
            })
    });

}, 20);