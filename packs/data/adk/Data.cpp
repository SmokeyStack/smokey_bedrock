#include "Data.h"

#include <string>

#include "GlobalRegistry.h"
#include "generator/BlockState.h"
#include "generator/ItemState.h"

Data::Data() {}

void Data::init() {
    headBlock("mini_amethyst_block", "amethyst_block");

    headBlock("mini_ancient_debris", "ancient_debris_side",
              "ancient_debris_side", "ancient_debris_side",
              "ancient_debris_side", "ancient_debris_top",
              "ancient_debris_top");
    headBlock("mini_azalea_leaves", "azalea_leaves");
    headBlock("mini_azalea_leaves_flowered", "azalea_leaves_flowered");
    headBlock("mini_bamboo_block", "bamboo_block", "bamboo_block",
              "bamboo_block", "bamboo_block", "bamboo_block_top",
              "bamboo_block_top");
    headBlock("mini_bamboo_mosaic", "bamboo_mosaic");
    headBlock("mini_bamboo_planks", "bamboo_planks");
    headBlock("mini_barrel", "barrel_top", "barrel_side", "barrel_bottom",
              "barrel_side", "barrel_side", "barrel_side");
    headBlock("mini_basalt", "basalt_side", "basalt_top");
    headBlock("mini_bee_nest", "bee_nest_side", "bee_nest_side",
              "bee_nest_front", "bee_nest_side", "bee_nest_top",
              "bee_nest_bottom");
    headBlock("mini_beehive", "beehive_side", "beehive_side", "beehive_front",
              "beehive_side", "beehive_top", "beehive_top");
    headBlock("mini_black_glazed_terracotta", "black_glazed_terracotta");
    headBlock("mini_blackstone", "blackstone", "blackstone_top");
    headBlock("mini_blast_furnace", "blast_furnace_side", "blast_furnace_side",
              "blast_furnace_front_off", "blast_furnace_side",
              "blast_furnace_top", "blast_furnace_top");
    headBlock("mini_blue_glazed_terracotta", "blue_glazed_terracotta");
    headBlock("mini_blue_ice", "blue_ice");
    headBlock("mini_bone_block", "bone_block_side", "bone_block_top");
    headBlock("mini_bookshelf", "bookshelf", "bookshelf_top");
    headBlock("mini_brick_block", "brick");
    headBlock("mini_brown_glazed_terracotta", "brown_glazed_terracotta");
    headBlock("mini_brown_mushroom_block", "mushroom_brown_top");
    headBlock("mini_calcite", "calcite");
    headBlock("mini_cartography_table", "cartography_table_side3",
              "cartography_table_side3", "cartography_table_side1",
              "cartography_table_side2", "cartography_table_top",
              "cartography_table_bottom");
    headBlock("mini_carved_pumpkin", "pumpkin_side", "pumpkin_side",
              "pumpkin_face", "pumpkin_side", "pumpkin_top", "pumpkin_top");
    headBlock("mini_chest", "chest_inventory_side", "chest_inventory_side",
              "chest_inventory_front", "chest_inventory_side",
              "chest_inventory_top", "chest_inventory_top");
    headBlock("mini_chiseled_bookshelf", "chiseled_bookshelf_front",
              "chiseled_bookshelf_side", "chiseled_bookshelf_side",
              "chiseled_bookshelf_side", "chiseled_bookshelf_top",
              "chiseled_bookshelf_top");
    headBlock("mini_chiseled_deepslate", "chiseled_deepslate");
    headBlock("mini_chiseled_nether_bricks", "chiseled_nether_bricks");
    headBlock("mini_chiseled_polished_blackstone",
              "chiseled_polished_blackstone");
    headBlock("mini_chorus_flower", "chorus_flower");
    headBlock("mini_chorus_plant", "chorus_plant");
    headBlock("mini_clay", "clay");
    headBlock("mini_coal_block", "coal_block");
    headBlock("mini_coal_ore", "coal_ore");
    headBlock("mini_cobbled_deepslate", "cobbled_deepslate");
    headBlock("mini_cobblestone", "cobblestone");
    headBlock("mini_concrete", "concrete");
    headBlock("mini_concrete_powder", "concrete_powder");
    headBlock("mini_copper_block", "copper_block");
    headBlock("mini_copper_ore", "copper_ore");
    headBlock("mini_coral_block", "coral_block");
    headBlock("mini_cracked_deepslate_bricks", "cracked_deepslate_bricks");
    headBlock("mini_cracked_deepslate_tiles", "cracked_deepslate_tiles");
    headBlock("mini_cracked_nether_bricks", "cracked_nether_bricks");
    headBlock("mini_cracked_polished_blackstone_bricks",
              "cracked_polished_blackstone_bricks");
    headBlock("mini_crafting_table", "crafting_table_front",
              "crafting_table_side", "crafting_table_front",
              "crafting_table_side", "crafting_table_top",
              "crafting_table_bottom");
    headBlock("mini_crimson_hyphae", "crimson_log_side");
    headBlock("mini_crimson_nylium", "crimson_nylium_side",
              "crimson_nylium_side", "crimson_nylium_side",
              "crimson_nylium_side", "crimson_nylium_top", "netherrack");
    headBlock("mini_crimson_planks", "crimson_planks");
    headBlock("mini_crimson_stem", "crimson_log_side", "crimson_log_top");
    headBlock("mini_crying_obsidian", "crying_obsidian");
    headBlock("mini_cut_copper", "cut_copper");
    headBlock("mini_cyan_glazed_terracotta", "cyan_glazed_terracotta");
    headBlock("mini_deepslate", "deepslate", "deepslate_top");
    headBlock("mini_deepslate_bricks", "deepslate_bricks");
    headBlock("mini_deepslate_coal_ore", "deepslate_coal_ore");
    headBlock("mini_deepslate_copper_ore", "deepslate_copper_ore");
    headBlock("mini_deepslate_diamond_ore", "deepslate_diamond_ore");
    headBlock("mini_deepslate_emerald_ore", "deepslate_emerald_ore");
    headBlock("mini_deepslate_gold_ore", "deepslate_gold_ore");
    headBlock("mini_deepslate_iron_ore", "deepslate_iron_ore");
    headBlock("mini_deepslate_lapis_ore", "deepslate_lapis_ore");
    headBlock("mini_deepslate_redstone_ore", "deepslate_redstone_ore");
    headBlock("mini_deepslate_tiles", "deepslate_tiles");
    headBlock("mini_diamond_block", "diamond_block");
    headBlock("mini_diamond_ore", "diamond_ore");
    headBlock("mini_dirt", "dirt");
    headBlock("mini_dirt_with_roots", "dirt_with_roots");
    headBlock("mini_dispenser", "dispenser_side", "dispenser_side",
              "dispenser_front_horizontal", "dispenser_side", "dispenser_top",
              "dispenser_top");
    headBlock("mini_dried_kelp_block", "dried_kelp_block_side_a",
              "dried_kelp_block_side_b", "dried_kelp_block_side_b",
              "dried_kelp_block_side_a", "dried_kelp_block_top",
              "dried_kelp_block_top");
    headBlock("mini_dripstone_block", "dripstone_block");
    headBlock("mini_dropper", "dropper_side", "dropper_front_vertical",
              "dropper_front_horizontal", "dropper_side", "dropper_top",
              "dropper_top");
    headBlock("mini_emerald_block", "emerald_block");
    headBlock("mini_emerald_ore", "emerald_ore");
    headBlock("mini_end_bricks", "end_bricks");
    headBlock("mini_end_stone", "end_stone");
    headBlock("mini_ender_chest", "ender_chest_inventory_side",
              "ender_chest_inventory_side", "ender_chest_inventory_front",
              "ender_chest_inventory_side", "ender_chest_inventory_top",
              "ender_chest_inventory_top");
    headBlock("mini_exposed_copper", "exposed_copper");
    headBlock("mini_exposed_cut_copper", "exposed_cut_copper");
    headBlock("mini_farmland", "farmland_side", "farmland_side",
              "farmland_side", "farmland_side", "farmland", "farmland_side");
    headBlock("mini_fletching_table", "fletching_table_side1",
              "fletching_table_side2", "fletching_table_side1",
              "fletching_table_side2", "fletching_table_top", "birch_planks");
    headBlock("mini_furnace", "furnace_side", "furnace_side",
              "furnace_front_off", "furnace_side", "furnace_top",
              "furnace_top");
    headBlock("mini_gilded_blackstone", "gilded_blackstone");
    headBlock("mini_glass", "glass");
    headBlock("mini_glowstone", "glowstone");
    headBlock("mini_gold_block", "gold_block");
    headBlock("mini_gold_ore", "gold_ore");
    headBlock("mini_grass", "grass_side", "grass_side", "grass_side",
              "grass_side", "grass_top", "grass_bottom");
    headBlock("mini_grass_path", "grass_path_side", "grass_path_side",
              "grass_path_side", "grass_path_side", "grass_path_top", "dirt");
    headBlock("mini_gravel", "gravel");
    headBlock("mini_gray_glazed_terracotta", "gray_glazed_terracotta");
    headBlock("mini_green_glazed_terracotta", "green_glazed_terracotta");
    headBlock("mini_hardened_clay", "hardened_clay");
    headBlock("mini_hay_block", "hayblock_side", "hayblock_top");
    headBlock("mini_honey_block", "honey_side", "honey_side", "honey_side",
              "honey_side", "honey_top", "honey_bottom");
    headBlock("mini_honeycomb_block", "honeycomb_block");
    headBlock("mini_ice", "ice");
    headBlock("mini_iron_block", "iron_block");
    headBlock("mini_iron_ore", "iron_ore");
    headBlock("mini_jukebox", "jukebox_side", "jukebox_side", "jukebox_side",
              "jukebox_side", "jukebox_top", "jukebox_side");
    headBlock("mini_lapis_block", "lapis_block");
    headBlock("mini_lapis_ore", "lapis_ore");
    headBlock("mini_leaves", "leaves");
    headBlock("mini_leaves2", "leaves2");
    headBlock("mini_light_blue_glazed_terracotta",
              "light_blue_glazed_terracotta");
    headBlock("mini_light_blue_wool", "wool_colored_light_blue");
    headBlock("mini_light_gray_wool", "wool_colored_silver");
    headBlock("mini_lime_glazed_terracotta", "lime_glazed_terracotta");
    headBlock("mini_lime_wool", "wool_colored_lime");
    headBlock("mini_lodestone", "lodestone_side", "lodestone_top");
    headBlock("mini_log", "log_side", "log_top");
    headBlock("mini_log2", "log_side2", "log_top2");
    headBlock("mini_loom", "loom_front", "loom_side", "loom_side", "loom_side",
              "loom_top", "loom_bottom");
    headBlock("mini_magenta_glazed_terracotta", "magenta_glazed_terracotta");
    headBlock("mini_magenta_wool", "wool_colored_magenta");
    headBlock("mini_magma", "magma");
    headBlock("mini_mangrove_leaves", "mangrove_leaves");
    headBlock("mini_mangrove_log", "mangrove_log_side", "mangrove_log_top");
    headBlock("mini_mangrove_planks", "mangrove_planks");
    headBlock("mini_mangrove_roots", "mangrove_roots_side",
              "mangrove_roots_top");
    headBlock("mini_mangrove_wood", "mangrove_log_side");
    headBlock("mini_melon_block", "melon_side", "melon_top");
    headBlock("mini_moss_block", "moss_block");
    headBlock("mini_mossy_cobblestone", "cobblestone_mossy");
    headBlock("mini_mud", "mud");
    headBlock("mini_mud_bricks", "mud_bricks");
    headBlock("mini_muddy_mangrove_roots", "muddy_mangrove_roots_side",
              "muddy_mangrove_roots_top");
    headBlock("mini_mycelium", "mycelium_side", "mycelium_side",
              "mycelium_side", "mycelium_side", "mycelium_top",
              "mycelium_bottom");
    headBlock("mini_nether_brick", "nether_brick");
    headBlock("mini_nether_gold_ore", "nether_gold_ore");
    headBlock("mini_nether_wart_block", "nether_wart_block");
    headBlock("mini_netherite_block", "netherite_block");
    headBlock("mini_netherrack", "netherrack");
    headBlock("mini_noteblock", "noteblock");
    headBlock("mini_observer", "observer_north", "observer_east",
              "observer_south", "observer_west", "observer_top",
              "observer_bottom");
    headBlock("mini_obsidian", "obsidian");
    headBlock("mini_ochre_froglight", "ochre_froglight_side",
              "ochre_froglight_top");
    headBlock("mini_orange_glazed_terracotta", "orange_glazed_terracotta");
    headBlock("mini_orange_wool", "wool_colored_orange");
    headBlock("mini_oxidized_copper", "oxidized_copper");
    headBlock("mini_oxidized_cut_copper", "oxidized_cut_copper");
    headBlock("mini_packed_ice", "ice_packed");
    headBlock("mini_packed_mud", "packed_mud");
    headBlock("mini_pearlescent_froglight", "pearlescent_froglight_side",
              "pearlescent_froglight_top");
    headBlock("mini_pink_glazed_terracotta", "pink_glazed_terracotta");
    headBlock("mini_pink_wool", "wool_colored_pink");
    headBlock("mini_piston", "piston_side", "piston_side", "piston_side",
              "piston_side", "piston_top_normal", "piston_bottom");
    headBlock("mini_planks", "planks");
    headBlock("mini_podzol", "dirt_podzol_side", "dirt_podzol_side",
              "dirt_podzol_side", "dirt_podzol_side", "dirt_podzol_top",
              "dirt_podzol_bottom");
    headBlock("mini_polished_basalt", "polished_basalt_side",
              "polished_basalt_top");
    headBlock("mini_polished_blackstone", "polished_blackstone");
    headBlock("mini_polished_blackstone_bricks", "polished_blackstone_bricks");
    headBlock("mini_polished_deepslate", "polished_deepslate");
    headBlock("mini_powder_snow", "powder_snow");
    headBlock("mini_prismarine", "prismarine");
    headBlock("mini_pumpkin", "pumpkin_side", "pumpkin_side", "pumpkin_face",
              "pumpkin_side", "pumpkin_top", "pumpkin_top");
    headBlock("mini_purple_glazed_terracotta", "purple_glazed_terracotta");
    headBlock("mini_purple_wool", "wool_colored_purple");
    headBlock("mini_purpur_block", "purpur_block_side", "purpur_block_side",
              "purpur_block_side", "purpur_block_side", "purpur_block_top",
              "purpur_block_bottom");
    headBlock("mini_quartz_block", "quartz_block_side", "quartz_block_side",
              "quartz_block_side", "quartz_block_side", "quartz_block_top",
              "quartz_block_bottom");
    headBlock("mini_quartz_bricks", "quartz_bricks");
    headBlock("mini_quartz_ore", "quartz_ore");
    headBlock("mini_raw_copper_block", "raw_copper_block");
    headBlock("mini_raw_gold_block", "raw_gold_block");
    headBlock("mini_raw_iron_block", "raw_iron_block");
    headBlock("mini_red_glazed_terracotta", "red_glazed_terracotta");
    headBlock("mini_red_mushroom_block", "mushroom_red_north",
              "mushroom_red_east", "mushroom_red_south", "mushroom_red_west",
              "mushroom_red_top", "mushroom_red_bottom");
    headBlock("mini_red_nether_brick", "red_nether_brick");
    headBlock("mini_red_sandstone", "redsandstone_side", "redsandstone_side",
              "redsandstone_side", "redsandstone_side", "redsandstone_top",
              "redsandstone_bottom");
    headBlock("mini_red_wool", "wool_colored_red");
    headBlock("mini_redstone_block", "redstone_block");
    headBlock("mini_redstone_lamp", "redstone_lamp_off");
    headBlock("mini_redstone_ore", "redstone_ore");
    headBlock("mini_reinforced_deepslate", "reinforced_deepslate_side",
              "reinforced_deepslate_side", "reinforced_deepslate_side",
              "reinforced_deepslate_side", "reinforced_deepslate_top",
              "reinforced_deepslate_bottom");
    headBlock("mini_respawn_anchor", "respawn_anchor_side",
              "respawn_anchor_side", "respawn_anchor_side",
              "respawn_anchor_side", "respawn_anchor_top",
              "respawn_anchor_bottom");
    headBlock("mini_sand", "sand");
    headBlock("mini_sandstone", "sandstone_side", "sandstone_side",
              "sandstone_side", "sandstone_side", "sandstone_top",
              "sandstone_bottom");
    headBlock("mini_scaffolding", "scaffolding_side", "scaffolding_side",
              "scaffolding_side", "scaffolding_side", "scaffolding_top",
              "scaffolding_bottom");
    headBlock("mini_sculk", "sculk");
    headBlock("mini_sculk_catalyst", "sculk_catalyst_side",
              "sculk_catalyst_side", "sculk_catalyst_side",
              "sculk_catalyst_side", "sculk_catalyst_top",
              "sculk_catalyst_bottom");
    headBlock("mini_sea_lantern", "sea_lantern");
    headBlock("mini_shroomlight", "shroomlight");
    headBlock("mini_shulker_box", "shulker_box_top");
    headBlock("mini_silver_glazed_terracotta", "silver_glazed_terracotta");
    headBlock("mini_slime", "slime_block");
    headBlock("mini_smithing_table", "smithing_table_front",
              "smithing_table_side", "smithing_table_front",
              "smithing_table_side", "smithing_table_top",
              "smithing_table_bottom");
    headBlock("mini_smoker", "smoker_side", "smoker_side", "smoker_front_off",
              "smoker_side", "smoker_bottom", "smoker_top");
    headBlock("mini_smooth_basalt", "smooth_basalt");
    headBlock("mini_smooth_stone", "smooth_stone");
    headBlock("mini_snow", "snow");
    headBlock("mini_soul_sand", "soul_sand");
    headBlock("mini_soul_soil", "soul_soil");
    headBlock("mini_sponge", "sponge");
    headBlock("mini_stained_glass", "stained_glass");
    headBlock("mini_stained_hardened_clay", "stained_clay");
    headBlock("mini_sticky_piston", "piston_side", "piston_side", "piston_side",
              "piston_side", "piston_top_sticky", "piston_bottom");
    headBlock("mini_stone", "stone");
    headBlock("mini_stonebrick", "stonebrick");
    headBlock("mini_stripped_acacia_log", "stripped_acacia_log_side",
              "stripped_acacia_log_top");
    // headBlock("mini_stripped_bamboo_block");
    headBlock("mini_stripped_birch_log", "stripped_birch_log_side",
              "stripped_birch_log_top");
    headBlock("mini_stripped_crimson_hyphae", "stripped_crimson_stem_side");
    headBlock("mini_stripped_crimson_stem", "stripped_crimson_stem_side",
              "stripped_crimson_stem_top");
    headBlock("mini_stripped_dark_oak_log", "stripped_dark_oak_log_side",
              "stripped_dark_oak_log_top");
    headBlock("mini_stripped_jungle_log", "stripped_jungle_log_side",
              "stripped_jungle_log_top");
    headBlock("mini_stripped_mangrove_log", "stripped_mangrove_log_side",
              "stripped_mangrove_log_top");
    headBlock("mini_stripped_mangrove_wood", "stripped_mangrove_log_side");
    headBlock("mini_stripped_oak_log", "stripped_oak_log_side",
              "stripped_oak_log_top");
    headBlock("mini_stripped_spruce_log", "stripped_spruce_log_side",
              "stripped_spruce_log_top");
    headBlock("mini_stripped_warped_hyphae", "stripped_warped_stem_side");
    headBlock("mini_stripped_warped_stem", "stripped_warped_stem_side",
              "stripped_warped_stem_top");
    headBlock("mini_target", "target_side", "target_top");
    headBlock("mini_tinted_glass", "tinted_glass");
    headBlock("mini_tnt", "tnt_side", "tnt_side", "tnt_side", "tnt_side",
              "tnt_top", "tnt_bottom");
    headBlock("mini_trapped_chest", "chest_inventory_side",
              "chest_inventory_side", "trapped_chest_inventory_front",
              "chest_inventory_side", "chest_inventory_top",
              "chest_inventory_top");
    headBlock("mini_tuff", "tuff");
    headBlock("mini_undyed_shulker_box", "undyed_shulker_box_top");
    headBlock("mini_verdant_froglight", "verdant_froglight_side",
              "verdant_froglight_top");
    headBlock("mini_warped_hyphae", "warped_stem_side");
    headBlock("mini_warped_nylium", "warped_nylium_side", "warped_nylium_side",
              "warped_nylium_side", "warped_nylium_side", "warped_nylium_top",
              "netherrack");
    headBlock("mini_warped_planks", "warped_planks");
    headBlock("mini_warped_stem", "warped_stem_side", "warped_stem_top");
    headBlock("mini_warped_wart_block", "warped_wart_block");
    headBlock("mini_waxed_copper", "copper_block");
    headBlock("mini_waxed_cut_copper", "cut_copper");
    headBlock("mini_waxed_exposed_copper", "exposed_copper");
    headBlock("mini_waxed_exposed_cut_copper", "exposed_cut_copper");
    headBlock("mini_waxed_oxidized_copper", "oxidized_copper");
    headBlock("mini_waxed_oxidized_cut_copper", "oxidized_cut_copper");
    headBlock("mini_waxed_weathered_copper", "weathered_copper");
    headBlock("mini_waxed_weathered_cut_copper", "weathered_cut_copper");
    headBlock("mini_weathered_copper", "weathered_copper");
    headBlock("mini_weathered_cut_copper", "weathered_cut_copper");
    headBlock("mini_white_glazed_terracotta", "white_glazed_terracotta");
    headBlock("mini_wood", "wood");
    headBlock("mini_white_wool", "wool_colored_white");
    headBlock("mini_yellow_glazed_terracotta", "yellow_glazed_terracotta");
    headBlock("mini_yellow_wool", "wool_colored_yellow");

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
    armorModel("smokey_bedrock", "inferno_crown",
               "textures/armour/inferno_crown", HEAD);
    simpleItem("inferno_crown", "inferno_crown");
}