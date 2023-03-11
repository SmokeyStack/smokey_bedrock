#include "Recipe.h"

#include "GlobalRegistry.h"
#include "ShapedRecipeBuilder.h"
#include "ShapelessRecipeBuilder.h"

Recipe::Recipe() {}

void Recipe::init() {
    ShapelessRecipeBuilder()
        .shapeless("smokey_bedrock:honeycomb_bricks", 4)
        .requires("minecraft:honeycomb")
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
}