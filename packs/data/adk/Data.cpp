#include "Data.h"

#include <string>

#include "GlobalRegistry.h"
#include "generator/BlockState.h"
#include "generator/ItemState.h"

Data::Data() {}

void Data::init() {
    headBlock("lime_glazed_terracotta", "lime_glazed_terracotta");
    headBlock("lime_wool", "wool_colored_lime");
    headBlock("lodestone", "lodestone_side", "lodestone_top");
    headBlock("log", "log_side", "log_top");
    headBlock("log2", "log_side2", "log_top2");
    headBlock("loom", "loom_front", "loom_side", "loom_side", "loom_side",
              "loom_top", "loom_bottom");
    headBlock("magenta_glazed_terracotta", "magenta_glazed_terracotta");
    headBlock("magenta_wool", "wool_colored_magenta");
    headBlock("magma", "magma");
    headBlock("mangrove_leaves", "mangrove_leaves");
    headBlock("mangrove_log", "mangrove_log_side", "mangrove_log_top");
    headBlock("mangrove_planks", "mangrove_planks");
    headBlock("mangrove_roots", "mangrove_roots_side", "mangrove_roots_top");
    headBlock("mangrove_wood", "mangrove_log_side");
    headBlock("melon_block", "melon_side", "melon_top");
    headBlock("moss_block", "moss_block");
    headBlock("mossy_cobblestone", "cobblestone_mossy");
    headBlock("mud", "mud");
    headBlock("mud_bricks", "mud_bricks");
    headBlock("muddy_mangrove_roots", "muddy_mangrove_roots_side",
              "muddy_mangrove_roots_top");
    headBlock("mycelium", "mycelium_side", "mycelium_side", "mycelium_side",
              "mycelium_side", "mycelium_top", "mycelium_bottom");
    headBlock("nether_brick", "nether_brick");
    headBlock("nether_gold_ore", "nether_gold_ore");
    headBlock("nether_wart_block", "nether_wart_block");
    headBlock("netherite_block", "netherite_block");
    headBlock("netherrack", "netherrack");
    headBlock("noteblock", "noteblock");
    headBlock("observer", "observer_north", "observer_east", "observer_south",
              "observer_west", "observer_top", "observer_bottom");
    headBlock("obsidian", "obsidian");
    headBlock("ochre_froglight", "ochre_froglight_side", "ochre_froglight_top");
    headBlock("orange_glazed_terracotta", "orange_glazed_terracotta");
    headBlock("orange_wool", "wool_colored_orange");
    headBlock("oxidized_copper", "oxidized_copper");
    headBlock("oxidized_cut_copper", "oxidized_cut_copper");
    headBlock("packed_ice", "ice_packed");
    headBlock("packed_mud", "packed_mud");
    headBlock("pearlescent_froglight", "pearlescent_froglight_side",
              "pearlescent_froglight_top");
    headBlock("pink_glazed_terracotta", "pink_glazed_terracotta");
    headBlock("pink_wool", "wool_colored_pink");
    headBlock("piston", "piston_side", "piston_side", "piston_side",
              "piston_side", "piston_top_normal", "piston_bottom");
    headBlock("planks", "planks");
    headBlock("podzol", "dirt_podzol_side", "dirt_podzol_side",
              "dirt_podzol_side", "dirt_podzol_side", "dirt_podzol_top",
              "dirt_podzol_bottom");
    headBlock("polished_basalt", "polished_basalt_side", "polished_basalt_top");
    headBlock("polished_blackstone", "polished_blackstone");
    headBlock("polished_blackstone_bricks", "polished_blackstone_bricks");
    headBlock("polished_deepslate", "polished_deepslate");
    headBlock("powder_snow", "powder_snow");
    headBlock("prismarine", "prismarine");
    headBlock("pumpkin", "pumpkin_side", "pumpkin_side", "pumpkin_face",
              "pumpkin_side", "pumpkin_top", "pumpkin_top");
    headBlock("purple_glazed_terracotta", "purple_glazed_terracotta");
    headBlock("purple_wool", "wool_colored_purple");
    headBlock("purpur_block", "purpur_block_side", "purpur_block_side",
              "purpur_block_side", "purpur_block_side", "purpur_block_top",
              "purpur_block_bottom");
    headBlock("quartz_block", "quartz_block_side", "quartz_block_side",
              "quartz_block_side", "quartz_block_side", "quartz_block_top",
              "quartz_block_bottom");
    headBlock("quartz_bricks", "quartz_bricks");
    headBlock("quartz_ore", "quartz_ore");
    headBlock("raw_copper_block", "raw_copper_block");
    headBlock("raw_gold_block", "raw_gold_block");
    headBlock("raw_iron_block", "raw_iron_block");
    headBlock("red_glazed_terracotta", "red_glazed_terracotta");
    headBlock("red_mushroom_block", "mushroom_red_north", "mushroom_red_east",
              "mushroom_red_south", "mushroom_red_west", "mushroom_red_top",
              "mushroom_red_bottom");
    headBlock("red_nether_brick", "red_nether_brick");
    headBlock("red_sandstone", "redsandstone_side", "redsandstone_side",
              "redsandstone_side", "redsandstone_side", "redsandstone_top",
              "redsandstone_bottom");
    headBlock("red_wool", "wool_colored_red");
    headBlock("redstone_block", "redstone_block");
    headBlock("redstone_lamp", "redstone_lamp_off");
    headBlock("redstone_ore", "redstone_ore");
    headBlock("reinforced_deepslate", "reinforced_deepslate_side",
              "reinforced_deepslate_side", "reinforced_deepslate_side",
              "reinforced_deepslate_side", "reinforced_deepslate_top",
              "reinforced_deepslate_bottom");
    headBlock("respawn_anchor", "respawn_anchor_side", "respawn_anchor_side",
              "respawn_anchor_side", "respawn_anchor_side",
              "respawn_anchor_top", "respawn_anchor_bottom");
    headBlock("sand", "sand");
    headBlock("sandstone", "sandstone_side", "sandstone_side", "sandstone_side",
              "sandstone_side", "sandstone_top", "sandstone_bottom");
    headBlock("scaffolding", "scaffolding_side", "scaffolding_side",
              "scaffolding_side", "scaffolding_side", "scaffolding_top",
              "scaffolding_bottom");
    headBlock("sculk", "sculk");
    headBlock("sculk_catalyst", "sculk_catalyst_side", "sculk_catalyst_side",
              "sculk_catalyst_side", "sculk_catalyst_side",
              "sculk_catalyst_top", "sculk_catalyst_bottom");
    headBlock("sea_lantern", "sea_lantern");
    headBlock("shroomlight", "shroomlight");
    headBlock("shulker_box", "shulker_box_top");
    headBlock("silver_glazed_terracotta", "silver_glazed_terracotta");
    headBlock("slime", "slime_block");
    headBlock("smithing_table", "smithing_table_front", "smithing_table_side",
              "smithing_table_front", "smithing_table_side",
              "smithing_table_top", "smithing_table_bottom");
    headBlock("smoker", "smoker_side", "smoker_side", "smoker_front_off",
              "smoker_side", "smoker_bottom", "smoker_top");
    headBlock("smooth_basalt", "smooth_basalt");
    headBlock("smooth_stone", "smooth_stone");
    headBlock("snow", "snow");
    headBlock("soul_sand", "soul_sand");
    headBlock("soul_soil", "soul_soil");
    headBlock("sponge", "sponge");
    headBlock("stained_glass", "stained_glass");
    headBlock("stained_hardened_clay", "stained_clay");
    headBlock("sticky_piston", "piston_side", "piston_side", "piston_side",
              "piston_side", "piston_top_sticky", "piston_bottom");
    headBlock("stone", "stone");
    headBlock("stonebrick", "stonebrick");
    headBlock("stripped_acacia_log", "stripped_acacia_log_side",
              "stripped_acacia_log_top");
    // headBlock("stripped_bamboo_block");
    headBlock("stripped_birch_log", "stripped_birch_log_side",
              "stripped_birch_log_top");
    headBlock("stripped_crimson_hyphae", "stripped_crimson_stem_side");
    headBlock("stripped_crimson_stem", "stripped_crimson_stem_side",
              "stripped_crimson_stem_top");
    headBlock("stripped_dark_oak_log", "stripped_dark_oak_log_side",
              "stripped_dark_oak_log_top");
    headBlock("stripped_jungle_log", "stripped_jungle_log_side",
              "stripped_jungle_log_top");
    headBlock("stripped_mangrove_log", "stripped_mangrove_log_side",
              "stripped_mangrove_log_top");
    headBlock("stripped_mangrove_wood", "stripped_mangrove_log_side");
    headBlock("stripped_oak_log", "stripped_oak_log_side",
              "stripped_oak_log_top");
    headBlock("stripped_spruce_log", "stripped_spruce_log_side",
              "stripped_spruce_log_top");
    headBlock("stripped_warped_hyphae", "stripped_warped_stem_side");
    headBlock("stripped_warped_stem", "stripped_warped_stem_side",
              "stripped_warped_stem_top");
    headBlock("target", "target_side", "target_top");
    headBlock("tinted_glass", "tinted_glass");
    headBlock("tnt", "tnt_side", "tnt_side", "tnt_side", "tnt_side", "tnt_top",
              "tnt_bottom");
    headBlock("trapped_chest", "chest_inventory_side", "chest_inventory_side",
              "trapped_chest_inventory_front", "chest_inventory_side",
              "chest_inventory_top", "chest_inventory_top");
    headBlock("tuff", "tuff");
    headBlock("undyed_shulker_box", "undyed_shulker_box_top");
    headBlock("verdant_froglight", "verdant_froglight_side",
              "verdant_froglight_top");
    headBlock("warped_hyphae", "warped_stem_side");
    headBlock("warped_nylium", "warped_nylium_side", "warped_nylium_side",
              "warped_nylium_side", "warped_nylium_side", "warped_nylium_top",
              "netherrack");
    headBlock("warped_planks", "warped_planks");
    headBlock("warped_stem", "warped_stem_side", "warped_stem_top");
    headBlock("warped_wart_block", "warped_wart_block");
    headBlock("waxed_copper", "copper_block");
    headBlock("waxed_cut_copper", "cut_copper");
    headBlock("waxed_exposed_copper", "exposed_copper");
    headBlock("waxed_exposed_cut_copper", "exposed_cut_copper");
    headBlock("waxed_oxidized_copper", "oxidized_copper");
    headBlock("waxed_oxidized_cut_copper", "oxidized_cut_copper");
    headBlock("waxed_weathered_copper", "weathered_copper");
    headBlock("waxed_weathered_cut_copper", "weathered_cut_copper");
    headBlock("weathered_copper", "weathered_copper");
    headBlock("weathered_cut_copper", "weathered_cut_copper");
    headBlock("white_glazed_terracotta", "white_glazed_terracotta");
    headBlock("wood", "wood");
    headBlock("white_wool", "wool_colored_white");
    headBlock("yellow_glazed_terracotta", "yellow_glazed_terracotta");
    headBlock("yellow_wool", "wool_colored_yellow");

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
        candleBlock("candle_" + a, "sculk");

    simpleBlock("honeycomb_bricks", "honeycomb_bricks");
    simpleBlock("honeycomb_tiles", "honeycomb_tiles");
    simpleBlock("solidified_honey", "solidified_honey");
    simpleBlock("smooth_honeycomb", "smooth_honeycomb");
    slabBlock("honeycomb_bricks_slab", "honeycomb_bricks");
    slabBlock("honeycomb_tiles_slab", "honeycomb_tiles");
    slabBlock("solidified_honey_slab", "solidified_honey");
    slabBlock("smooth_honeycomb_slab", "smooth_honeycomb");

    simpleBlock("fossilized_shell", "fossilized_shell_sides",
                "fossilized_shell_sides", "fossilized_shell_sides",
                "fossilized_shell_sides", "fossilized_shell",
                "fossilized_shell_sides");

    crossBlock("searocket_white", "white_searocket");
    crossBlock("searocket_pink", "pink_searocket");
    crossBlock("seagrass_blue", "blue_seagrass");
    crossBlock("seagrass_purple", "purple_seagrass");

    simpleBlock("seagrass_block_blue", "blue_seagrass_block_side",
                "blue_seagrass_block_side", "blue_seagrass_block_side",
                "blue_seagrass_block_side", "blue_seagrass_block_top",
                "seagrass_block_bottom");
    simpleBlock("seagrass_block_dried_blue", "dried_blue_seagrass_block_side",
                "dried_blue_seagrass_block_side",
                "dried_blue_seagrass_block_side",
                "dried_blue_seagrass_block_side",
                "dried_blue_seagrass_block_top", "dried_seagrass_block_bottom");
    simpleBlock("seagrass_block_purple", "purple_seagrass_block_side",
                "purple_seagrass_block_side", "purple_seagrass_block_side",
                "purple_seagrass_block_side", "purple_seagrass_block_top",
                "seagrass_block_bottom");
    simpleBlock(
        "seagrass_block_dried_purple", "dried_purple_seagrass_block_side",
        "dried_purple_seagrass_block_side", "dried_purple_seagrass_block_side",
        "dried_purple_seagrass_block_side", "dried_purple_seagrass_block_top",
        "dried_seagrass_block_bottom");

    simpleBlock("scute_block", "scute_block");
    simpleBlock("scute_block_tile", "scute_block_tile");
    simpleBlock("scute_block_shingles", "scute_block_shingles");
    slabBlock("scute_block_slab", "scute_block");
    slabBlock("scute_block_tile_slab", "scute_block_tile");
    slabBlock("scute_block_shingles_slab", "scute_block_shingles");

    simpleItem("scute_chestplate", "scute_chestplate");
    armorModel("smokey_bedrock", "scute_chestplate",
               "textures/armour/scute_upper", CHEST);
    simpleItem("scute_leggings", "scute_leggings");
    armorModel("smokey_bedrock", "scute_leggings",
               "textures/armour/scute_lower", LEGS);
    simpleItem("scute_boots", "scute_boots");
    armorModel("smokey_bedrock", "scute_boots", "textures/armour/scute_upper",
               FEET);
}