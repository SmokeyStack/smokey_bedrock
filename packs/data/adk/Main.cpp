#include <fstream>

#include "ArmorItem.h"
#include "ArmorType.h"
#include "Block.h"
#include "BlockCategory.h"
#include "BlockProperty.h"
#include "HeadBlock.h"
#include "Item.h"
#include "Registry.h"
#include "SlabBlock.h"
#include "SmokeyBedrock/ScentedCandleBlock.h"

int main() {
    const std::string MODID = "smokey_bedrock";
    Registry<Block> blocks(MODID);
    Registry<Item> items(MODID);

    std::ifstream file("./data/adk/blocks.txt");
    std::string str;
    std::vector<std::string> block_list;
    while (std::getline(file, str)) block_list.push_back(str);

    for (const std::string& a : block_list)
        blocks.subscribe(
            a, new HeadBlock(BlockProperty::Property()
                                 .setCategory(adk::CreativeCategory::SKULL)
                                 .setTab(adk::CreativeTab::ITEMS)));

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

    blocks.subscribe("fossilized_shell", new Block(BlockProperty::Property()));

    blocks.subscribe(
        "searocket_white",
        new Block(BlockProperty::Property().setCollision(false).setSelection(
            {-6, 0, -6}, {12, 13, 12})));
    blocks.subscribe(
        "searocket_pink",
        new Block(BlockProperty::Property().setCollision(false).setSelection(
            {-6, 0, -6}, {12, 13, 12})));

    blocks.subscribe(
        "seagrass_blue",
        new Block(BlockProperty::Property().setCollision(false).setSelection(
            {-6, 0, -6}, {12, 13, 12})));
    blocks.subscribe(
        "seagrass_purple",
        new Block(BlockProperty::Property().setCollision(false).setSelection(
            {-6, 0, -6}, {12, 13, 12})));

    blocks.subscribe("seagrass_block_blue",
                     new Block(BlockProperty::Property()));
    blocks.subscribe("seagrass_block_dried_blue",
                     new Block(BlockProperty::Property()));
    blocks.subscribe("seagrass_block_purple",
                     new Block(BlockProperty::Property()));
    blocks.subscribe("seagrass_block_dried_purple",
                     new Block(BlockProperty::Property()));

    blocks.subscribe("scute_block", new Block(BlockProperty::Property()));
    blocks.subscribe("scute_block_tile", new Block(BlockProperty::Property()));
    blocks.subscribe("scute_block_shingles",
                     new Block(BlockProperty::Property()));
    blocks.subscribe(
        "scute_block_slab",
        new SlabBlock(BlockProperty::Property()
                          .setCategory(adk::CreativeCategory::SLAB)
                          .setTab(adk::CreativeTab::CONSTRUCTION)));
    blocks.subscribe(
        "scute_block_tile_slab",
        new SlabBlock(BlockProperty::Property()
                          .setCategory(adk::CreativeCategory::SLAB)
                          .setTab(adk::CreativeTab::CONSTRUCTION)));
    blocks.subscribe(
        "scute_block_shingles_slab",
        new SlabBlock(BlockProperty::Property()
                          .setCategory(adk::CreativeCategory::SLAB)
                          .setTab(adk::CreativeTab::CONSTRUCTION)));

    items.subscribe("scute_chestplate",
                    new ArmorItem(ItemProperty::Property(), 6,
                                  adk::ArmorSlot::CHEST, 100, true, 1, 1));
    items.subscribe("scute_leggings",
                    new ArmorItem(ItemProperty::Property(), 5,
                                  adk::ArmorSlot::LEGS, 100, true, 1, 1));
    items.subscribe("scute_boots",
                    new ArmorItem(ItemProperty::Property(), 2,
                                  adk::ArmorSlot::FEET, 100, true, 1, 1));

    items.subscribe(
        "bucket_nautilus",
        new Item(
            ItemProperty::Property().setIcon("bucket_nautilus").setStack(1)));

    return 0;
}