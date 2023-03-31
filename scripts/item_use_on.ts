import {
    BlockPermutation,
    Dimension,
    Effect,
    EffectType,
    EntityInventoryComponent,
    EntityType,
    EntityTypes,
    Items,
    ItemStack,
    ItemType,
    ItemUseOnEvent,
    MinecraftBlockTypes,
    MinecraftEffectTypes,
    MinecraftItemTypes,
    Player,
    Vector,
    Vector3
} from '@minecraft/server';
import { getDirectionOffset } from 'direction_offset';

function updateLiquid(
    liquid_dimension: Dimension,
    block_location: Vector3
): void {
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

export const BUCKET_ENTITIES = new Map<ItemType, EntityType>([
    [
        Items.get('smokey_bedrock:bucket_nautilus'),
        EntityTypes.get('smokey_bedrock:nautilus')
    ],
    [
        Items.get('smokey_bedrock:bucket_squid'),
        EntityTypes.get('minecraft:squid')
    ],
    [
        Items.get('smokey_bedrock:bucket_squid_glow'),
        EntityTypes.get('minecraft:glow_squid')
    ],
    [
        Items.get('smokey_bedrock:bucket_jellyfish'),
        EntityTypes.get('smokey_bedrock:jellyfish')
    ]
]);

export function placeScentedCandle(eventData: ItemUseOnEvent): void {
    const PLAYER: Player = eventData.source as any;
    let effects: EffectType[] = [];

    for (const EFF of Object.values(MinecraftEffectTypes)) {
        const EFFECT: Effect = PLAYER.getEffect(EFF);
        if (!EFFECT) continue;

        effects.push(EFF);
    }

    let effect: string = effects[0].getName();

    PLAYER.dimension
        .getBlock(
            Vector.add(
                eventData.getBlockLocation(),
                getDirectionOffset(eventData.blockFace)
            )
        )
        .setType(MinecraftBlockTypes.get(`smokey_bedrock:candle_${effect}`));
}

export function placeBucketEntity(
    eventData: ItemUseOnEvent,
    entity: string
): void {
    let PLAYER: Player = eventData.source as any;

    const SOURCE_DIMENSION: Dimension = eventData.source.dimension;
    SOURCE_DIMENSION.getBlock(
        Vector.add(
            eventData.getBlockLocation(),
            getDirectionOffset(eventData.blockFace)
        )
    ).setType(MinecraftBlockTypes.water);

    updateLiquid(
        SOURCE_DIMENSION,
        Vector.add(
            eventData.getBlockLocation(),
            getDirectionOffset(eventData.blockFace)
        )
    );

    SOURCE_DIMENSION.spawnEntity(
        entity,
        Vector.add(
            eventData.getBlockLocation(),
            getDirectionOffset(eventData.blockFace)
        )
    );

    let item: ItemStack = new ItemStack(MinecraftItemTypes.bucket, 1);
    let inventory_component: EntityInventoryComponent =
        eventData.source.getComponent('minecraft:inventory') as any;
    inventory_component.container.setItem(PLAYER.selectedSlot, item);
}
