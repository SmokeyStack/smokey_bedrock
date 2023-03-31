import { Direction, Vector3 } from '@minecraft/server';

export function getDirectionOffset(block_face: Direction): Vector3 {
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
    }
}
