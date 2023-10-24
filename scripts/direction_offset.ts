import { Direction, Vector3 } from '@minecraft/server';

export function getDirectionOffset(block_face: Direction): Vector3 {
    switch (block_face) {
        case Direction.Down:
            return { x: 0, y: -1, z: 0 };
        case Direction.East:
            return { x: 1, y: 0, z: 0 };
        case Direction.North:
            return { x: 0, y: 0, z: -1 };
        case Direction.South:
            return { x: 0, y: 0, z: 1 };
        case Direction.Up:
            return { x: 0, y: 1, z: 0 };
        case Direction.West:
            return { x: -1, y: 0, z: 0 };
    }
}
