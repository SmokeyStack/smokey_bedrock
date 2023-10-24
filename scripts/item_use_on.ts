import {
    BlockPermutation,
    Dimension,
    Effect,
    EntityInventoryComponent,
    ItemStack,
    Player,
    PlayerInteractWithBlockAfterEvent,
    PlayerInteractWithEntityAfterEvent,
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
        'minecraft:water',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x + 1, y: block_location.y, z: block_location.z },
        { x: block_location.x + 1, y: block_location.y, z: block_location.z },
        'minecraft:water',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y, z: block_location.z - 1 },
        { x: block_location.x, y: block_location.y, z: block_location.z - 1 },
        'minecraft:water',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y, z: block_location.z + 1 },
        { x: block_location.x, y: block_location.y, z: block_location.z + 1 },
        'minecraft:water',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y + 1, z: block_location.z },
        { x: block_location.x, y: block_location.y + 1, z: block_location.z },
        'minecraft:water',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x - 1, y: block_location.y, z: block_location.z },
        { x: block_location.x - 1, y: block_location.y, z: block_location.z },
        'minecraft:water',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:air')
        }
    );

    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y - 1, z: block_location.z },
        { x: block_location.x, y: block_location.y - 1, z: block_location.z },
        'minecraft:air',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x + 1, y: block_location.y, z: block_location.z },
        { x: block_location.x + 1, y: block_location.y, z: block_location.z },
        'minecraft:air',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y, z: block_location.z - 1 },
        { x: block_location.x, y: block_location.y, z: block_location.z - 1 },
        'minecraft:air',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y, z: block_location.z + 1 },
        { x: block_location.x, y: block_location.y, z: block_location.z + 1 },
        'minecraft:air',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x, y: block_location.y + 1, z: block_location.z },
        { x: block_location.x, y: block_location.y + 1, z: block_location.z },
        'minecraft:air',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
    liquid_dimension.fillBlocks(
        { x: block_location.x - 1, y: block_location.y, z: block_location.z },
        { x: block_location.x - 1, y: block_location.y, z: block_location.z },
        'minecraft:air',
        {
            matchingBlock: BlockPermutation.resolve('minecraft:water')
        }
    );
}

export const BUCKET_ENTITIES = new Map<string, string>([
    ['smokey_bedrock:bucket_nautilus', 'smokey_bedrock:nautilus'],
    ['smokey_bedrock:bucket_squid', 'minecraft:squid'],
    ['smokey_bedrock:bucket_squid_glow', 'minecraft:glow_squid'],
    ['smokey_bedrock:bucket_jellyfish', 'smokey_bedrock:jellyfish']
]);

export const BUCKETABLE_ENTITIES = new Map<string, string>([
    ['minecraft:nautilus', 'smokey_bedrock:bucket_nautilus'],
    ['minecraft:squid', 'smokey_bedrock:bucket_squid'],
    ['minecraft:glow_squid', 'smokey_bedrock:bucket_squid_glow'],
    ['smokey_bedrock:jellyfish', 'smokey_bedrock:bucket_jellyfish']
]);

export function placeScentedCandle(
    eventData: PlayerInteractWithBlockAfterEvent
): void {
    const PLAYER: Player = eventData.player as any;
    let effects: Effect[] = PLAYER.getEffects();

    PLAYER.dimension
        .getBlock(
            Vector.add(
                eventData.block.location,
                getDirectionOffset(eventData.blockFace)
            )
        )
        .setType(`smokey_bedrock:candle_${effects[0].typeId}`);
}

export function placeBucketEntity(
    eventData: PlayerInteractWithBlockAfterEvent,
    entity: string
): void {
    let PLAYER: Player = eventData.player as any;

    const SOURCE_DIMENSION: Dimension = PLAYER.dimension;

    let item: ItemStack = new ItemStack('minecraft:bucket', 1);
    let inventory_component: EntityInventoryComponent = PLAYER.getComponent(
        'minecraft:inventory'
    ) as any;
    inventory_component.container.setItem(PLAYER.selectedSlot, item);

    SOURCE_DIMENSION.getBlock(
        Vector.add(
            eventData.block.location,
            getDirectionOffset(eventData.blockFace)
        )
    ).setType('minecraft:water');

    updateLiquid(
        SOURCE_DIMENSION,
        Vector.add(
            eventData.block.location,
            getDirectionOffset(eventData.blockFace)
        )
    );

    SOURCE_DIMENSION.spawnEntity(
        entity,
        Vector.add(
            eventData.block.location,
            getDirectionOffset(eventData.blockFace)
        )
    );
}

export function pickupBucketEntity(
    eventData: PlayerInteractWithEntityAfterEvent,
    entity: string
): void {
    let PLAYER: Player = eventData.player as any;

    let item: ItemStack = new ItemStack(entity, 1);
    let inventory_component: EntityInventoryComponent = PLAYER.getComponent(
        'minecraft:inventory'
    ) as any;
    inventory_component.container.setItem(PLAYER.selectedSlot, item);
}
