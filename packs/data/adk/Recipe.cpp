#include "Recipe.h"

#include "CookingRecipeBuilder.h"
#include "GlobalRegistry.h"
#include "ShapedRecipeBuilder.h"
#include "ShapelessRecipeBuilder.h"

Recipe::Recipe() {}

void Recipe::init() {
    ShapelessRecipeBuilder()
        .shapeless("smokey_bedrock:honeycomb_bricks", 4)
        .requires("minecraft:honeycomb_block")
        .save("honeycomb_bricks_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:honeycomb_bricks_slab", 6)
        .pattern("###")
        .define('#', "smokey_bedrock:honeycomb_bricks")
        .save("honeycomb_bricks_slab_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:honeycomb_tiles", 4)
        .pattern("##")
        .pattern("##")
        .define('#', "smokey_bedrock:honeycomb_bricks")
        .save("honeycomb_tiles_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:honeycomb_tiles_slab", 6)
        .pattern("###")
        .define('#', "smokey_bedrock:honeycomb_tiles")
        .save("honeycomb_tiles_slab_recipe");
    CookingRecipeBuilder()
        .cook("smokey_bedrock:solidified_honey", "minecraft:honey_block",
              std::vector<std::string>{"furnace"})
        .save("solidified_honey_recipe");
    CookingRecipeBuilder()
        .cook("smokey_bedrock:smooth_honeycomb", "minecraft:honeycomb_block",
              std::vector<std::string>{"furnace"})
        .save("smooth_honeycomb_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:solidified_honey_slab", 6)
        .pattern("###")
        .define('#', "smokey_bedrock:solidified_honey")
        .save("solidified_honey_slab_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:smooth_honeycomb_slab", 6)
        .pattern("###")
        .define('#', "smokey_bedrock:smooth_honeycomb")
        .save("smooth_honeycomb_slab_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:seagrass_block_blue")
        .pattern("###")
        .pattern("###")
        .pattern("###")
        .define('#', "smokey_bedrock:seagrass_blue")
        .save("seagrass_block_blue_recipe");
    CookingRecipeBuilder()
        .cook("smokey_bedrock:seagrass_block_dried_blue",
              "smokey_bedrock:seagrass_block_blue",
              std::vector<std::string>{"furnace"})
        .save("seagrass_block_dried_blue_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:seagrass_block_purple")
        .pattern("###")
        .pattern("###")
        .pattern("###")
        .define('#', "smokey_bedrock:seagrass_purple")
        .save("seagrass_block_purple_recipe");
    CookingRecipeBuilder()
        .cook("smokey_bedrock:seagrass_block_dried_purple",
              "smokey_bedrock:seagrass_block_purple",
              std::vector<std::string>{"furnace"})
        .save("seagrass_block_dried_purple_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_block", 4)
        .pattern("##")
        .pattern("##")
        .define('#', "minecraft:scute")
        .save("scute_block_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_block_tile", 4)
        .pattern("##")
        .pattern("##")
        .define('#', "smokey_bedrock:scute_block")
        .save("scute_block_tile_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_block_shingles", 4)
        .pattern("##")
        .pattern("##")
        .define('#', "smokey_bedrock:scute_block_tile")
        .save("scute_block_shingles_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_block_slab", 6)
        .pattern("###")
        .define('#', "smokey_bedrock:scute_block")
        .save("scute_block_slab_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_block_tile_slab", 6)
        .pattern("###")
        .define('#', "smokey_bedrock:scute_block_tile")
        .save("scute_block_tile_slab_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_block_shingles_slab", 6)
        .pattern("###")
        .define('#', "smokey_bedrock:scute_block_shingles")
        .save("scute_block_shingles_slab_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_chestplate")
        .pattern("# #")
        .pattern("###")
        .pattern("###")
        .define('#', "minecraft:scute")
        .save("scute_chestplate_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_leggings")
        .pattern("###")
        .pattern("# #")
        .pattern("# #")
        .define('#', "minecraft:scute")
        .save("scute_leggings_recipe");
    ShapedRecipeBuilder()
        .shaped("smokey_bedrock:scute_boots")
        .pattern("# #")
        .pattern("# #")
        .define('#', "minecraft:scute")
        .save("scute_boots_recipe");
}