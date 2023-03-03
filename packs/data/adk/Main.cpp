#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>

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
    auto logger = spdlog::basic_logger_mt<spdlog::async_factory>(
        "adk", "logs/async_log.txt");

    logger->info("");

    const std::string MODID = "smokey_bedrock";
    Registry<Block> blocks(MODID);
    Registry<Item> items(MODID);

    std::ifstream file("./data/adk/blocks.txt");
    std::string str;
    std::vector<std::string> block_list;
    while (std::getline(file, str)) block_list.push_back(str);

    for (const std::string& a : block_list)
        blocks.subscribe(
            a, new HeadBlock(BlockProperty().setCreativeCategory(
                   adk::CreativeTab::ITEMS, adk::CreativeCategory::SKULL)));

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
                         new ScentedCandleBlock(BlockProperty(), a));

    blocks.subscribe(
        "honeycomb_bricks",
        new Block(BlockProperty()
                      .setMining(1.0)
                      .setExplosion(3.0)
                      .setCreativeCategory(adk::CreativeTab::CONSTRUCTION,
                                           adk::CreativeCategory::STONEBRICK)));
    blocks.subscribe(
        "honeycomb_tiles",
        new Block(BlockProperty().setMining(1.0).setExplosion(3.0)));
    blocks.subscribe(
        "solidified_honey",
        new Block(BlockProperty().setMining(1.0).setExplosion(3.0)));
    blocks.subscribe(
        "smooth_honeycomb",
        new Block(BlockProperty().setMining(1.0).setExplosion(3.0)));
    blocks.subscribe(
        "honeycomb_bricks_slab",
        new SlabBlock(BlockProperty().setMining(1.0).setExplosion(3.0)));
    blocks.subscribe(
        "honeycomb_tiles_slab",
        new SlabBlock(BlockProperty().setMining(1.0).setExplosion(3.0)));
    blocks.subscribe(
        "solidified_honey_slab",
        new SlabBlock(BlockProperty().setMining(1.0).setExplosion(3.0)));
    blocks.subscribe(
        "smooth_honeycomb_slab",
        new SlabBlock(BlockProperty().setMining(1.0).setExplosion(3.0)));

    blocks.subscribe("fossilized_shell", new Block(BlockProperty()));

    blocks.subscribe("searocket_white",
                     new Block(BlockProperty().setCollision(false).setSelection(
                         std::make_pair(std::vector<int>{-6, 0, -6},
                                        std::vector<int>{12, 13, 12}))));
    blocks.subscribe("searocket_pink",
                     new Block(BlockProperty().setCollision(false).setSelection(
                         std::make_pair(std::vector<int>{-6, 0, -6},
                                        std::vector<int>{12, 13, 12}))));

    blocks.subscribe("seagrass_blue",
                     new Block(BlockProperty().setCollision(false).setSelection(
                         std::make_pair(std::vector<int>{-6, 0, -6},
                                        std::vector<int>{12, 13, 12}))));
    blocks.subscribe("seagrass_purple",
                     new Block(BlockProperty().setCollision(false).setSelection(
                         std::make_pair(std::vector<int>{-6, 0, -6},
                                        std::vector<int>{12, 13, 12}))));

    blocks.subscribe("seagrass_block_blue", new Block(BlockProperty()));
    blocks.subscribe("seagrass_block_dried_blue", new Block(BlockProperty()));
    blocks.subscribe("seagrass_block_purple", new Block(BlockProperty()));
    blocks.subscribe("seagrass_block_dried_purple", new Block(BlockProperty()));

    blocks.subscribe("scute_block", new Block(BlockProperty()));
    blocks.subscribe("scute_block_tile", new Block(BlockProperty()));
    blocks.subscribe("scute_block_shingles", new Block(BlockProperty()));
    blocks.subscribe(
        "scute_block_slab",
        new SlabBlock(BlockProperty().setCreativeCategory(
            adk::CreativeTab::CONSTRUCTION, adk::CreativeCategory::SLAB)));
    blocks.subscribe(
        "scute_block_tile_slab",
        new SlabBlock(BlockProperty().setCreativeCategory(
            adk::CreativeTab::CONSTRUCTION, adk::CreativeCategory::SLAB)));
    blocks.subscribe(
        "scute_block_shingles_slab",
        new SlabBlock(BlockProperty().setCreativeCategory(
            adk::CreativeTab::CONSTRUCTION, adk::CreativeCategory::SLAB)));

    items.subscribe("scute_chestplate",
                    new ArmorItem(ItemProperty(), 6, adk::ArmorSlot::CHEST, 100,
                                  true, 1, 1));
    items.subscribe("scute_leggings",
                    new ArmorItem(ItemProperty(), 5, adk::ArmorSlot::LEGS, 100,
                                  true, 1, 1));
    items.subscribe("scute_boots",
                    new ArmorItem(ItemProperty(), 2, adk::ArmorSlot::FEET, 100,
                                  true, 1, 1));

    items.subscribe(
        "bucket_nautilus",
        new Item(ItemProperty().setIcon("bucket_nautilus").setStack(1)));
    items.subscribe(
        "bucket_squid",
        new Item(ItemProperty().setIcon("bucket_squid").setStack(1)));
    items.subscribe(
        "bucket_squid_glow",
        new Item(ItemProperty().setIcon("bucket_squid_glow").setStack(1)));
    items.subscribe(
        "bucket_jellyfish",
        new Item(ItemProperty().setIcon("bucket_jellyfish").setStack(1)));

    return 0;
}