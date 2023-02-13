#include <fstream>
#include <iostream>
#include <vector>

#include "Block.h"
#include "BlockProperty.h"
#include "HeadBlock.h"
#include "Registry.h"
#include "SlabBlock.h"
#include "SmokeyBedrock/ScentedCandleBlock.h"

int main() {
    const std::string MODID = "smokey_bedrock";
    Registry<Block> blocks(MODID);

    std::ifstream file("./data/adk/blocks.txt");
    std::string str;
    std::vector<std::string> block_list;
    while (std::getline(file, str)) block_list.push_back(str);

    for (const std::string& a : block_list)
        blocks.subscribe(a, new HeadBlock(BlockProperty::Property()));

    std::vector<std::string> effect_list = {
        "absorption",   "bad_omen",     "blindness",       "conduit_power",
        "darkness",     "fatal_poison", "fire_resistance", "haste",
        "health_boost", "hunger",       "instant_damage",  "instant_health",
        "invisibility", "jump_boost",   "levitation",      "mining_fatigue",
        "nausea",       "night_vision", "poison",          "regeneration",
        "resistance",   "saturation",   "slow_falling",    "slowness",
        "speed",        "strength",     "village_hero",    "water_breathing",
        "weakness",     "wither"};

    for (const std::string& a : effect_list)
        blocks.subscribe("candle_" + a,
                         new ScentedCandleBlock(BlockProperty::Property(), a));

    blocks.subscribe(
        "honeycomb_bricks",
        new Block(BlockProperty::Property().setMining(1).setExplosion(3)));
    blocks.subscribe(
        "honeycomb_tiles",
        new Block(BlockProperty::Property().setMining(1).setExplosion(3)));
    blocks.subscribe(
        "solidified_honey",
        new Block(BlockProperty::Property().setMining(1).setExplosion(3)));
    blocks.subscribe(
        "smooth_honeycomb",
        new Block(BlockProperty::Property().setMining(1).setExplosion(3)));
    blocks.subscribe(
        "honeycomb_bricks_slab",
        new SlabBlock(BlockProperty::Property().setMining(1).setExplosion(3)));
    blocks.subscribe(
        "honeycomb_tiles_slab",
        new SlabBlock(BlockProperty::Property().setMining(1).setExplosion(3)));
    blocks.subscribe(
        "solidified_honey_slab",
        new SlabBlock(BlockProperty::Property().setMining(1).setExplosion(3)));
    blocks.subscribe(
        "smooth_honeycomb_slab",
        new SlabBlock(BlockProperty::Property().setMining(1).setExplosion(3)));

    return 0;
}