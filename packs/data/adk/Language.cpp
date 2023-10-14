#include "Language.h"

#include <map>
#include <string>
#include <vector>

#include "GlobalRegistry.h"

Language::Language(std::string id, std::string locale) {
    mod_id = id;
    this->locale = locale;
}

void Language::init() {
    add("mini_amethyst_block", "Mini Block of Amethyst");
    add("mini_ancient_debris", "Mini Ancient Debris");
    add("mini_azalea_leaves", "Mini Azalea Leaves");
    add("mini_azalea_leaves_flowered", "Mini Flowering Azalea Leaves");
    add("mini_bamboo_block", "Mini Block of Bamboo");
    add("mini_bamboo_mosaic", "Mini Bamboo Mosaic");
    add("mini_bamboo_planks", "Mini Bamboo Planks");
    add("mini_barrel", "Mini Barrel");
    add("mini_basalt", "Mini Basalt");
    add("mini_bee_nest", "Mini Bee Nest");
    add("mini_beehive", "Mini Beehive");
    add("mini_black_concrete", "Mini Black Concrete");
    add("mini_black_concrete_powder", "Mini Black Concrete Powder");
    add("mini_black_glazed_terracotta", "Mini Black Glazed Terracotta");
    add("mini_black_shulker_box", "Mini Black Shulker Box");
    add("mini_black_stained_glass", "Mini Black Stained Glass");
    add("mini_black_terracotta", "Mini Black Terracotta");
    add("mini_black_wool", "Mini Black Wool");
    add("mini_blackstone", "Mini Blackstone");
    add("mini_blast_furnace", "Mini Blast Furnace");
    add("mini_blue_concrete", "Mini Blue Concrete");
    add("mini_blue_concrete_powder", "Mini Blue Concrete Powder");
    add("mini_blue_glazed_terracotta", "Mini Blue Glazed Terracotta");
    add("mini_blue_ice", "Mini Blue Ice");
    add("mini_blue_shulker_box", "Mini Blue Shulker Box");
    add("mini_blue_stained_glass", "Mini Blue Stained Glass");
    add("mini_blue_terracotta", "Mini Blue Terracotta");
    add("mini_blue_wool", "Mini Blue Wool");
    add("mini_bone_block", "Mini Bone Block");
    add("mini_bookshelf", "Mini Bookshelf");
    add("mini_brick_block", "Mini Brick Block");
    add("mini_brown_concrete", "Mini Brown Concrete");
    add("mini_brown_concrete_powder", "Mini Brown Concrete Powder");
    add("mini_brown_glazed_terracotta", "Mini Brown Glazed Terracotta");
    add("mini_brown_mushroom_block", "Mini Brown Mushroom Block");
    add("mini_brown_shulker_box", "Mini Brown Shulker Box");
    add("mini_brown_stained_glass", "Mini Brown Stained Glass");
    add("mini_brown_terracotta", "Mini Brown Terracotta");
    add("mini_brown_wool", "Mini Brown Wool");
    add("mini_calcite", "Mini Calcite");
    add("mini_cartography_table", "Mini Cartography Table");
    add("mini_carved_pumpkin", "Mini Carved Pumpkin");
    add("mini_cherry_leaves", "Mini Cherry Leaves");
    add("mini_cherry_log", "Mini Cherry Log");
    add("mini_cherry_planks", "Mini Cherry Planks");
    add("mini_cherry_wood", "Mini Cherry Wood");
    add("mini_chest", "Mini Chest");
    add("mini_chiseled_bookshelf", "Mini Chiseled Bookshelf");
    add("mini_chiseled_deepslate", "Mini Chiseled Deepslate");
    add("mini_chiseled_nether_bricks", "Mini Chiseled Nether Bricks");
    add("mini_chiseled_polished_blackstone",
        "Mini Chiseled Polished Blackstone");
    add("mini_chorus_flower", "Mini Chorus Flower");
    add("mini_chorus_plant", "Mini Chorus Plant");
    add("mini_clay", "Mini Clay");
    add("mini_coal_block", "Mini Block of Coal");
    add("mini_coal_ore", "Mini Coal Ore");
    add("mini_cobbled_deepslate", "Mini Cobbled Deepslate");
    add("mini_cobblestone", "Mini Cobblestone");
    add("mini_copper_block", "Mini Block of Copper");
    add("mini_copper_ore", "Mini Copper Ore");
    add("mini_coral_block", "Mini Coral Block");
    add("mini_cracked_deepslate_bricks", "Mini Cracked Deepslate Bricks");
    add("mini_cracked_deepslate_tiles", "Mini Cracked Deepslate Tiles");
    add("mini_cracked_nether_bricks", "Mini Cracked Nether Bricks");
    add("mini_cracked_polished_blackstone_bricks",
        "Mini Cracked Polished Blackstone Bricks");
    add("mini_crafting_table", "Mini Crafting Table");
    add("mini_crimson_hyphae", "Mini Crimson Hyphae");
    add("mini_crimson_nylium", "Mini Crimson Nylium");
    add("mini_crimson_planks", "Mini Crimson Planks");
    add("mini_crimson_stem", "Mini Crimson Stem");
    add("mini_crying_obsidian", "Mini Crying Obsidian");
    add("mini_cut_copper", "Mini Cut Copper");
    add("mini_cyan_concrete", "Mini Cyan Concrete");
    add("mini_cyan_concrete_powder", "Mini Cyan Concrete Powder");
    add("mini_cyan_glazed_terracotta", "Mini Cyan Glazed Terracotta");
    add("mini_cyan_shulker_box", "Mini Cyan Shulker Box");
    add("mini_cyan_stained_glass", "Mini Cyan Stained Glass");
    add("mini_cyan_terracotta", "Mini Cyan Terracotta");
    add("mini_cyan_wool", "Mini Cyan Wool");
    add("mini_dark_oak_log", "Mini Dark Oak Log");
    add("mini_deepslate", "Mini Deepslate");
    add("mini_deepslate_bricks", "Mini Deepslate Bricks");
    add("mini_deepslate_coal_ore", "Mini Deepslate Coal Ore");
    add("mini_deepslate_copper_ore", "Mini Deepslate Copper Ore");
    add("mini_deepslate_diamond_ore", "Mini Deepslate Diamond Ore");
    add("mini_deepslate_emerald_ore", "Mini Deepslate Emerald Ore");
    add("mini_deepslate_gold_ore", "Mini Deepslate Gold Ore");
    add("mini_deepslate_iron_ore", "Mini Deepslate Iron Ore");
    add("mini_deepslate_lapis_ore", "Mini Deepslate Lapis Ore");
    add("mini_deepslate_redstone_ore", "Mini Deepslate Redstone Ore");
    add("mini_deepslate_tiles", "Mini Deepslate Tiles");
    add("mini_diamond_block", "Mini Block of Diamond");
    add("mini_diamond_ore", "Mini Diamond Ore");
    add("mini_dirt", "Mini Dirt");
    add("mini_dirt_with_roots", "Mini Dirt with Roots");
    add("mini_dispenser", "Mini Dispenser");
    add("mini_dried_kelp_block", "Mini Dried Kelp Block");
    add("mini_dripstone_block", "Mini Dripstone Block");
    add("mini_dropper", "Mini Dropper");
    add("mini_emerald_block", "Mini Block of Emerald");
    add("mini_emerald_ore", "Mini Emerald Ore");
    add("mini_end_bricks", "Mini End Bricks");
    add("mini_end_stone", "Mini End Stone");
    add("mini_ender_chest", "Mini Ender Chest");
    add("mini_exposed_copper", "Mini Exposed Copper");
    add("mini_exposed_cut_copper", "Mini Exposed Cut Copper");
    add("mini_farmland", "Mini Farmland");
    add("mini_fletching_table", "Mini Fletching Table");
    add("mini_furnace", "Mini Furnace");
    add("mini_gilded_blackstone", "Mini Gilded Blackstone");
    add("mini_glass", "Mini Glass");
    add("mini_glowstone", "Mini Glowstone");
    add("mini_gold_block", "Mini Block of Gold");
    add("mini_gold_ore", "Mini Gold Ore");
    add("mini_grass", "Mini Grass");
    add("mini_grass_path", "Mini Grass Path");
    add("mini_gravel", "Mini Gravel");
    add("mini_gray_concrete", "Mini Gray Concrete");
    add("mini_gray_concrete_powder", "Mini Gray Concrete Powder");
    add("mini_gray_glazed_terracotta", "Mini Gray Glazed Terracotta");
    add("mini_gray_shulker_box", "Mini Gray Shulker Box");
    add("mini_gray_stained_glass", "Mini Gray Stained Glass");
    add("mini_gray_terracotta", "Mini Gray Terracotta");
    add("mini_gray_wool", "Mini Gray Wool");
    add("mini_green_concrete", "Mini Green Concrete");
    add("mini_green_concrete_powder", "Mini Green Concrete Powder");
    add("mini_green_glazed_terracotta", "Mini Green Glazed Terracotta");
    add("mini_green_shulker_box", "Mini Green Shulker Box");
    add("mini_green_stained_glass", "Mini Green Stained Glass");
    add("mini_green_terracotta", "Mini Green Terracotta");
    add("mini_green_wool", "Mini Green Wool");
    add("mini_hardened_clay", "Mini Hardened Clay");
    add("mini_hay_block", "Mini Hay Bale");
    add("mini_honey_block", "Mini Honey Block");
    add("mini_honeycomb_block", "Mini Honeycomb Block");
    add("mini_ice", "Mini Ice");
    add("mini_iron_block", "Mini Block of Iron");
    add("mini_iron_ore", "Mini Iron Ore");
    add("mini_jukebox", "Mini Jukebox");
    add("mini_jungle_log", "Mini Jungle Log");
    add("mini_lapis_block", "Mini Block of Lapis Lazuli");
    add("mini_lapis_ore", "Mini Lapis Lazuli Ore");
    add("mini_leaves", "Mini Leaves");
    add("mini_leaves2", "Mini Leaves");
    add("mini_light_blue_concrete", "Mini Light Blue Concrete");
    add("mini_light_blue_concrete_powder", "Mini Light Blue Concrete Powder");
    add("mini_light_blue_glazed_terracotta",
        "Mini Light Blue Glazed Terracotta");
    add("mini_light_blue_shulker_box", "Mini Light Blue Shulker Box");
    add("mini_light_blue_stained_glass", "Mini Light Blue Stained Glass");
    add("mini_light_blue_terracotta", "Mini Light Blue Terracotta");
    add("mini_light_blue_wool", "Mini Light Blue Wool");
    add("mini_light_gray_concrete", "Mini Light Gray Concrete");
    add("mini_light_gray_concrete_powder", "Mini Light Gray Concrete Powder");
    add("mini_light_gray_shulker_box", "Mini Light Gray Shulker Box");
    add("mini_light_gray_stained_glass", "Mini Light Gray Stained Glass");
    add("mini_light_gray_terracotta", "Mini Light Gray Terracotta");
    add("mini_light_gray_wool", "Mini Light Gray Wool");
    add("mini_lime_concrete", "Mini Lime Concrete");
    add("mini_lime_concrete_powder", "Mini Lime Concrete Powder");
    add("mini_lime_glazed_terracotta", "Mini Lime Glazed Terracotta");
    add("mini_lime_shulker_box", "Mini Lime Shulker Box");
    add("mini_lime_stained_glass", "Mini Lime Stained Glass");
    add("mini_lime_terracotta", "Mini Lime Terracotta");
    add("mini_lime_wool", "Mini Lime Wool");
    add("mini_lodestone", "Mini Lodestone");
    add("mini_loom", "Mini Loom");
    add("mini_magenta_concrete", "Mini Magenta Concrete");
    add("mini_magenta_concrete_powder", "Mini Magenta Concrete Powder");
    add("mini_magenta_glazed_terracotta", "Mini Magenta Glazed Terracotta");
    add("mini_magenta_shulker_box", "Mini Magenta Shulker Box");
    add("mini_magenta_stained_glass", "Mini Magenta Stained Glass");
    add("mini_magenta_terracotta", "Mini Magenta Terracotta");
    add("mini_magenta_wool", "Mini Magenta Wool");
    add("mini_magma", "Mini Magma Block");
    add("mini_mangrove_leaves", "Mini Mangrove Leaves");
    add("mini_mangrove_log", "Mini Mangrove Log");
    add("mini_mangrove_planks", "Mini Mangrove Planks");
    add("mini_mangrove_roots", "Mini Mangrove Roots");
    add("mini_mangrove_wood", "Mini Mangrove Wood");
    add("mini_melon_block", "Mini Melon");
    add("mini_moss_block", "Mini Moss Block");
    add("mini_mossy_cobblestone", "Mini Mossy Cobblestone");
    add("mini_mud", "Mini Mud");
    add("mini_mud_bricks", "Mini Mud Bricks");
    add("mini_muddy_mangrove_roots", "Mini Muddy Mangrove Roots");
    add("mini_mycelium", "Mini Mycelium");
    add("mini_nether_brick", "Mini Nether Bricks");
    add("mini_nether_gold_ore", "Mini Nether Gold Ore");
    add("mini_nether_wart_block", "Mini Nether Wart Block");
    add("mini_netherite_block", "Mini Block of Netherite");
    add("mini_netherrack", "Mini Netherrack");
    add("mini_noteblock", "Mini Note Block");
    add("mini_oak_log", "Mini Oak Log");
    add("mini_observer", "Mini Observer");
    add("mini_obsidian", "Mini Obsidian");
    add("mini_ochre_froglight", "Mini Ochre Froglight");
    add("mini_orange_concrete", "Mini Orange Concrete");
    add("mini_orange_concrete_powder", "Mini Orange Concrete Powder");
    add("mini_orange_glazed_terracotta", "Mini Orange Glazed Terracotta");
    add("mini_orange_shulker_box", "Mini Orange Shulker Box");
    add("mini_orange_stained_glass", "Mini Orange Stained Glass");
    add("mini_orange_terracotta", "Mini Orange Terracotta");
    add("mini_orange_wool", "Mini Orange Wool");
    add("mini_oxidized_copper", "Mini Oxidized Copper");
    add("mini_oxidized_cut_copper", "Mini Oxidized Cut Copper");
    add("mini_packed_ice", "Mini Packed Ice");
    add("mini_packed_mud", "Mini Packed Mud");
    add("mini_pearlescent_froglight", "Mini Pearlescent Froglight");
    add("mini_pink_concrete", "Mini Pink Concrete");
    add("mini_pink_concrete_powder", "Mini Pink Concrete Powder");
    add("mini_pink_glazed_terracotta", "Mini Pink Glazed Terracotta");
    add("mini_pink_shulker_box", "Mini Pink Shulker Box");
    add("mini_pink_stained_glass", "Mini Pink Stained Glass");
    add("mini_pink_terracotta", "Mini Pink Terracotta");
    add("mini_pink_wool", "Mini Pink Wool");
    add("mini_piston", "Mini Piston");
    add("mini_planks", "Mini Planks");
    add("mini_podzol", "Mini Podzol");
    add("mini_polished_basalt", "Mini Polished Basalt");
    add("mini_polished_blackstone", "Mini Polished Blackstone");
    add("mini_polished_blackstone_bricks", "Mini Polished Blackstone Bricks");
    add("mini_polished_deepslate", "Mini Polished Deepslate");
    add("mini_powder_snow", "Mini Powder Snow");
    add("mini_prismarine", "Mini Prismarine");
    add("mini_pumpkin", "Mini Pumpkin");
    add("mini_purple_concrete", "Mini Purple Concrete");
    add("mini_purple_concrete_powder", "Mini Purple Concrete Powder");
    add("mini_purple_glazed_terracotta", "Mini Purple Glazed Terracotta");
    add("mini_purple_shulker_box", "Mini Purple Shulker Box");
    add("mini_purple_stained_glass", "Mini Purple Stained Glass");
    add("mini_purple_terracotta", "Mini Purple Terracotta");
    add("mini_purple_wool", "Mini Purple Wool");
    add("mini_purpur_block", "Mini Purpur Block");
    add("mini_quartz_block", "Mini Block of Quartz");
    add("mini_quartz_bricks", "Mini Quartz Bricks");
    add("mini_quartz_ore", "Mini Nether Quartz Ore");
    add("mini_raw_copper_block", "Mini Raw Copper Block");
    add("mini_raw_gold_block", "Mini Raw Gold Block");
    add("mini_raw_iron_block", "Mini Raw Iron Block");
    add("mini_red_concrete", "Mini Red Concrete");
    add("mini_red_concrete_powder", "Mini Red Concrete Powder");
    add("mini_red_glazed_terracotta", "Mini Red Glazed Terracotta");
    add("mini_red_mushroom_block", "Mini Red Mushroom Block");
    add("mini_red_nether_brick", "Mini Red Nether Bricks");
    add("mini_red_sandstone", "Mini Red Sandstone");
    add("mini_red_shulker_box", "Mini Red Shulker Box");
    add("mini_red_stained_glass", "Mini Red Stained Glass");
    add("mini_red_terracotta", "Mini Red Terracotta");
    add("mini_red_wool", "Mini Red Wool");
    add("mini_redstone_block", "Mini Block of Redstone");
    add("mini_redstone_lamp", "Mini Redstone Lamp");
    add("mini_redstone_ore", "Mini Redstone Ore");
    add("mini_reinforced_deepslate", "Mini Reinforced Deepslate");
    add("mini_respawn_anchor", "Mini Respawn Anchor");
    add("mini_sand", "Mini Sand");
    add("mini_sandstone", "Mini Sandstone");
    add("mini_scaffolding", "Mini Scaffolding");
    add("mini_sculk", "Mini Sculk Sensor");
    add("mini_sculk_catalyst", "Mini Sculk Catalyst");
    add("mini_sea_lantern", "Mini Sea Lantern");
    add("mini_shroomlight", "Mini Shroomlight");
    add("mini_silver_glazed_terracotta", "Mini Light Gray Glazed Terracotta");
    add("mini_slime", "Mini Slime Block");
    add("mini_smithing_table", "Mini Smithing Table");
    add("mini_smoker", "Mini Smoker");
    add("mini_smooth_basalt", "Mini Smooth Basalt");
    add("mini_smooth_stone", "Mini Smooth Stone");
    add("mini_snow", "Mini Snow");
    add("mini_soul_sand", "Mini Soul Sand");
    add("mini_soul_soil", "Mini Soul Soil");
    add("mini_sponge", "Mini Sponge");
    add("mini_spruce_log", "Mini Spruce Log");
    add("mini_sticky_piston", "Mini Sticky Piston");
    add("mini_stone", "Mini Stone");
    add("mini_stonebrick", "Mini Stone Bricks");
    add("mini_stripped_acacia_log", "Mini Stripped Acacia Log");
    add("mini_stripped_bamboo_block", "Mini Stripped Bamboo Block");
    add("mini_stripped_birch_log", "Mini Stripped Birch Log");
    add("mini_stripped_cherry_log", "Mini Stripped Cherry Log");
    add("mini_stripped_cherry_wood", "Mini Stripped Cherry Log");
    add("mini_stripped_crimson_hyphae", "Mini Stripped Crimson Hyphae");
    add("mini_stripped_crimson_stem", "Mini Stripped Crimson Stem");
    add("mini_stripped_dark_oak_log", "Mini Stripped Dark Oak Log");
    add("mini_stripped_jungle_log", "Mini Stripped Jungle Log");
    add("mini_stripped_mangrove_log", "Mini Stripped Mangrove Log");
    add("mini_stripped_mangrove_wood", "Mini Stripped Mangrove Wood");
    add("mini_stripped_oak_log", "Mini Stripped Oak Log");
    add("mini_stripped_spruce_log", "Mini Stripped Spruce Log");
    add("mini_stripped_warped_hyphae", "Mini Stripped Warped Hyphae");
    add("mini_stripped_warped_stem", "Mini Stripped Warped Stem");
    add("mini_target", "Mini Target");
    add("mini_tinted_glass", "Mini Tinted Glass");
    add("mini_tnt", "Mini TNT");
    add("mini_trapped_chest", "Mini Trapped Chest");
    add("mini_tuff", "Mini Tuff");
    add("mini_undyed_shulker_box", "Mini Undyed Shulker Box");
    add("mini_verdant_froglight", "Mini Verdant Froglight");
    add("mini_warped_hyphae", "Mini Warped Hyphae");
    add("mini_warped_nylium", "Mini Warped Nylium");
    add("mini_warped_planks", "Mini Warped Planks");
    add("mini_warped_stem", "Mini Warped Stem");
    add("mini_warped_wart_block", "Mini Warped Wart Block");
    add("mini_waxed_copper", "Mini Waxed Copper");
    add("mini_waxed_cut_copper", "Mini Waxed Cut Copper");
    add("mini_waxed_exposed_copper", "Mini Waxed Exposed Copper");
    add("mini_waxed_exposed_cut_copper", "Mini Waxed Exposed Cut Copper");
    add("mini_waxed_oxidized_copper", "Mini Waxed Oxidized Copper");
    add("mini_waxed_oxidized_cut_copper", "Mini Waxed Oxidized Cut Copper");
    add("mini_waxed_weathered_copper", "Mini Waxed Weathered Copper");
    add("mini_waxed_weathered_cut_copper", "Mini Waxed Weathered Cut Copper");
    add("mini_weathered_copper", "Mini Weathered Copper");
    add("mini_weathered_cut_copper", "Mini Weathered Cut Copper");
    add("mini_white_concrete", "Mini White Concrete");
    add("mini_white_concrete_powder", "Mini White Concrete Powder");
    add("mini_white_glazed_terracotta", "Mini White Glazed Terracotta");
    add("mini_white_shulker_box", "Mini White Shulker Box");
    add("mini_white_stained_glass", "Mini White Stained Glass");
    add("mini_white_terracotta", "Mini White Terracotta");
    add("mini_white_wool", "Mini White Wool");
    add("mini_wood", "Mini Wood");
    add("mini_yellow_concrete", "Mini Yellow Concrete");
    add("mini_yellow_concrete_powder", "Mini Yellow Concrete Powder");
    add("mini_yellow_glazed_terracotta", "Mini Yellow Glazed Terracotta");
    add("mini_yellow_shulker_box", "Mini Yellow Shulker Box");
    add("mini_yellow_stained_glass", "Mini Yellow Stained Glass");
    add("mini_yellow_terracotta", "Mini Yellow Terracotta");
    add("mini_yellow_wool", "Mini Yellow Wool");

    std::map<std::string, std::string> effect_list = {
        std::make_pair("absorption", "Absorption"),
        std::make_pair("bad_omen", "Bad Omen"),
        std::make_pair("blindness", "Blindness"),
        std::make_pair("conduit_power", "Conduit Power"),
        std::make_pair("darkness", "Darkness"),
        std::make_pair("fatal_poison", "Fatal Poison"),
        std::make_pair("fire_resistance", "Fire Resistance"),
        std::make_pair("haste", "Haste"),
        std::make_pair("health_boost", "Health Boost"),
        std::make_pair("hunger", "Hunger"),
        std::make_pair("instant_damage", "Instant Damage"),
        std::make_pair("instant_health", "Instant Health"),
        std::make_pair("invisibility", "Invisibility"),
        std::make_pair("jump_boost", "Jump Boost"),
        std::make_pair("levitation", "Levitation"),
        std::make_pair("mining_fatigue", "Mining Fatigue"),
        std::make_pair("nausea", "Nausea"),
        std::make_pair("night_vision", "Night Vision"),
        std::make_pair("poison", "Poison"),
        std::make_pair("regeneration", "Regeneration"),
        std::make_pair("resistance", "Resistance"),
        std::make_pair("saturation", "Saturation"),
        std::make_pair("slow_falling", "Slow Falling"),
        std::make_pair("slowness", "Slowness"),
        std::make_pair("speed", "Speed"),
        std::make_pair("strength", "Strength"),
        std::make_pair("village_hero", "Hero of the Village"),
        std::make_pair("water_breathing", "Water Breathing"),
        std::make_pair("weakness", "Weakness"),
        std::make_pair("wither", "Wither")};

    for (auto const& [key, val] : effect_list)
        add("candle_" + key, "Scented Candle of " + val);

    add("honeycomb_bricks", "Honeycomb Bricks");
    add("honeycomb_tiles", "Honeycomb Tiles");
    add("solidified_honey", "Solidified Honey");
    add("smooth_honeycomb", "Smooth Honeycomb");
    add("honeycomb_bricks_slab", "Honeycomb Bricks Slab");
    add("honeycomb_tiles_slab", "Honeycomb Tiles Slab");
    add("solidified_honey_slab", "Solidified Honey Slab");

    add("smooth_honeycomb_slab", "Smooth Honeycomb Slab");
    add("searocket_white", "White Searocket");
    add("searocket_pink", "Pink Searocket");
    add("seagrass_blue", "Blue Seagrass");
    add("seagrass_purple", "Purple Seagrass");
    add("seagrass_block_blue", "Block of Blue Seagrass");
    add("seagrass_block_dried_purple", "Block of Dried Purple Seagrass");
    add("seagrass_block_purple", "Block of Purple Seagrass");
    add("seagrass_dried_purple", "Block of Dried Purple Seagrass");

    add("scute_block", "Block of Scute");
    add("scute_block_tile", "Scute Tiles");
    add("scute_block_shingles", "Scute Shingles");
    add("scute_block_slab", "Scute Slab");
    add("scute_block_tile_slab", "Scute Tile Slab");
    add("scute_block_shingles_slab", "Scute Shingle Slab");

    createLangFile();
}