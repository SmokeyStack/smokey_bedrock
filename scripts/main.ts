import {
    BlockPermutation,
    CommandResult,
    Dimension,
    Direction,
    Effect,
    Entity,
    EntityInventoryComponent,
    EntityType,
    EntityTypes,
    EntityUnderwaterMovementComponent,
    Items,
    ItemStack,
    ItemType,
    ItemUseOnEvent,
    MinecraftBlockTypes,
    MinecraftEffectTypes,
    MinecraftItemTypes,
    Player,
    system,
    Vector,
    Vector3,
    world
} from '@minecraft/server';

function getDirectionOffset(block_face: Direction): Vector3 {
    switch (block_face) {
        case Direction.down:
            return { x: 0, y: -1, z: 0 };
        case Direction.east:
            return { x: 1, y: 0, z: 0 };
        case Direction.north:
            return { x: 0, y: 0, z: -1 };
        case Direction.south:
            return { x: 0, y: 0, z: 1 };
        case Direction.up:
            return { x: 0, y: 1, z: 0 };
        case Direction.west:
            return { x: -1, y: 0, z: 0 };
        default:
            break;
    }
}

world.events.entityDie.subscribe((eventData) => {
    const entity: Entity = eventData.deadEntity;

    if (
        entity.typeId == ('minecraft:dolphin' || 'minecraft:bat') &&
        eventData.damageSource.cause != 'entityAttack' &&
        eventData.damageSource.damagingEntity.typeId == 'minecraft:warden'
    ) {
        entity.dimension.spawnItem(
            new ItemStack(MinecraftItemTypes.echoShard),
            entity.location
        );
    }
});

async function detectHead(player: Player) {
    let result: Promise<CommandResult> = (await player.runCommandAsync(
        'execute if entity @s[hasitem=[{item=turtle_helmet,location=slot.armor.head}]]'
    )) as any;
    return (await result).successCount;
}

async function detectChest(player: Player) {
    let result: Promise<CommandResult> = (await player.runCommandAsync(
        'execute if entity @s[hasitem=[{item=smokey_bedrock:scute_chestplate,location=slot.armor.chest}]]'
    )) as any;
    return (await result).successCount;
}

async function detectPants(player: Player) {
    let result: Promise<CommandResult> = (await player.runCommandAsync(
        'execute if entity @s[hasitem=[{item=smokey_bedrock:scute_leggings,location=slot.armor.legs}]]'
    )) as any;
    return (await result).successCount;
}

async function detectBoots(player: Player) {
    let result: Promise<CommandResult> = (await player.runCommandAsync(
        'execute if entity @s[hasitem=[{item=smokey_bedrock:scute_boots,location=slot.armor.feet}]]'
    )) as any;
    return (await result).successCount;
}

system.runInterval(() => {
    let players: Player[] = world.getAllPlayers();

    players.forEach((player) => {
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

function updateLiquid(liquid_dimension: Dimension, block_location: Vector3) {
    liquid_dimension.fillBlocks(
        Vector.add(block_location, { x: 0, y: -1, z: 0 }),
        Vector.add(block_location, { x: 0, y: -1, z: 0 }),
        MinecraftBlockTypes.water,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x + 1, y: block_location.y, z: block_location.z },
        { x: block_location.x + 1, y: block_location.y, z: block_location.z },
        MinecraftBlockTypes.water,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y, z: block_location.z - 1 },
        { x: block_location.x, y: block_location.y, z: block_location.z - 1 },
        MinecraftBlockTypes.water,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y, z: block_location.z + 1 },
        { x: block_location.x, y: block_location.y, z: block_location.z + 1 },
        MinecraftBlockTypes.water,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y + 1, z: block_location.z },
        { x: block_location.x, y: block_location.y + 1, z: block_location.z },
        MinecraftBlockTypes.water,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x - 1, y: block_location.y, z: block_location.z },
        { x: block_location.x - 1, y: block_location.y, z: block_location.z },
        MinecraftBlockTypes.water,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );

    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y - 1, z: block_location.z },
        { x: block_location.x, y: block_location.y - 1, z: block_location.z },
        MinecraftBlockTypes.air,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x + 1, y: block_location.y, z: block_location.z },
        { x: block_location.x + 1, y: block_location.y, z: block_location.z },
        MinecraftBlockTypes.air,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y, z: block_location.z - 1 },
        { x: block_location.x, y: block_location.y, z: block_location.z - 1 },
        MinecraftBlockTypes.air,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y, z: block_location.z + 1 },
        { x: block_location.x, y: block_location.y, z: block_location.z + 1 },
        MinecraftBlockTypes.air,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y + 1, z: block_location.z },
        { x: block_location.x, y: block_location.y + 1, z: block_location.z },
        MinecraftBlockTypes.air,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x - 1, y: block_location.y, z: block_location.z },
        { x: block_location.x - 1, y: block_location.y, z: block_location.z },
        MinecraftBlockTypes.air,
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
}

function bucketEntity(eventData: ItemUseOnEvent, entity: string) {
    let player: Player = eventData.source as any;

    if (player.typeId != 'minecraft:player') return;

    let item_dimension = eventData.source.dimension;
    item_dimension
        .getBlock(
            Vector.add(
                eventData.getBlockLocation(),
                getDirectionOffset(eventData.blockFace)
            )
        )
        .setType(MinecraftBlockTypes.water);

    updateLiquid(
        item_dimension,
        Vector.add(
            eventData.getBlockLocation(),
            getDirectionOffset(eventData.blockFace)
        )
    );

    item_dimension.spawnEntity(
        entity,
        Vector.add(
            eventData.getBlockLocation(),
            getDirectionOffset(eventData.blockFace)
        )
    );

    let item: ItemStack = new ItemStack(MinecraftItemTypes.bucket, 1);
    let inventory_component: EntityInventoryComponent =
        eventData.source.getComponent('minecraft:inventory') as any;
    inventory_component.container.setItem(player.selectedSlot, item);
}

world.events.itemUseOn.subscribe((eventData) => {
    let item = eventData.item;

    let bucket_entities = new Map<ItemType, EntityType>();
    bucket_entities.set(
        Items.get('smokey_bedrock:bucket_nautilus'),
        EntityTypes.get('smokey_bedrock:nautilus')
    );
    bucket_entities.set(
        Items.get('smokey_bedrock:bucket_squid'),
        EntityTypes.get('minecraft:squid')
    );
    bucket_entities.set(
        Items.get('smokey_bedrock:bucket_squid_glow'),
        EntityTypes.get('minecraft:glow_squid')
    );
    bucket_entities.set(
        Items.get('smokey_bedrock:bucket_jellyfish'),
        EntityTypes.get('smokey_bedrock:jellyfish')
    );

    if (!bucket_entities.has(Items.get(item.typeId))) return;

    bucketEntity(eventData, bucket_entities.get(Items.get(item.typeId)).id);
});

world.events.itemUseOn.subscribe((eventData) => {
    if (eventData.item.typeId != 'minecraft:candle') return;

    let player = eventData.source;
    let effects = player.getEffects();

    if (effects.length == 0) return;

    let effect = effects[0];
    console.log(effect.displayName);

    // let perm: any = MinecraftBlockTypes.get(
    //     'smokey_bedrock:candle_darkness'
    // ).createDefaultBlockPermutation();

    eventData.source.dimension
        .getBlock(
            Vector.add(
                eventData.getBlockLocation(),
                getDirectionOffset(eventData.blockFace)
            )
        )
        .setType(MinecraftBlockTypes.get('smokey_bedrock:candle_darkness'));

    // switch (effect.displayName) {
    //     case 'absorption':
    //         break;
    //     default:
    //         break;
    // }
});

// function compareMaps(
//     map1: Map<string, number>,
//     map2: Map<string, number>
// ): boolean {
//     let testVal: any;
//     if (map1.size !== map2.size) return false;

//     for (let [key, val] of map1) {
//         testVal = map2.get(key);
//         if (testVal !== val || (testVal === undefined && !map2.has(key)))
//             return false;
//     }

//     return true;
// }

// world.events.itemUseOn.subscribe((eventData) => {
//     if (eventData.item.typeId != 'minecraft:stick') return;

//     let block_location: number[] = [
//         eventData.getBlockLocation().x + offset[0],
//         eventData.getBlockLocation().y + offset[1],
//         eventData.getBlockLocation().z + offset[2]
//     ];

//     let player: Player = eventData.source as any;

//     let requirements = new Map<string, number>();
//     requirements.set('minecraft:emerald', 16);
//     requirements.set('minecraft:bread', 16);

//     let keys = [...requirements.keys()];

//     let temp = new Map<string, number>();

//     let inv: EntityInventoryComponent = player.getComponent(
//         'minecraft:inventory'
//     ) as any;

//     for (var a = 0; a < inv.container.size; a++) {
//         try {
//             let item: string = inv.container.getItem(a).typeId;
//             let amount: number = inv.container.getItem(a).amount;
//             if (keys.includes(item)) {
//                 temp.set(item, amount);
//             }
//         } catch (error) {}
//     }

//     if (compareMaps(temp, requirements)) {
//         player.runCommandAsync(
//             `structure load mystructure:test ${block_location[0]} ${block_location[1]} ${block_location[2]}`
//         );
//         player.runCommandAsync(`clear @s ${eventData.item.typeId} 0 1`);
//         requirements.forEach((val, key) => {
//             player.runCommandAsync(`clear @s ${key} 0 ${val}`);
//         });
//     }
// });
