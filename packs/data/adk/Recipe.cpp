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
}