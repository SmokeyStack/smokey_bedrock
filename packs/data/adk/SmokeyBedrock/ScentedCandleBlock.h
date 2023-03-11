#ifndef SCENTEDCANDLEBLOCK_H
#define SCENTEDCANDLEBLOCK_H

#include "Block.h"
#include "BlockProperty.h"
#include "CandleBlock.h"
#include "json.hpp"

class ScentedCandleBlock : public CandleBlock {
   protected:
    std::string _effect;

   public:
    ScentedCandleBlock() {}
    /// @brief Represents a scented candle block
    /// @param property A BlockProperty object
    ScentedCandleBlock(BlockProperty property, std::string effect) {
        _block_light_filter = property.getBlockLightFilter();
        _crafting = property.getCrafting();
        _explosion = property.getExplosion();
        _mining = property.getMining();
        _display_name = property.getName();
        _flammable = property.getFlamamble();
        _friction = property.getFriction();
        _light_emission = property.getLightEmission();
        _loot = property.getLoot();
        _color = property.getColor();
        _rotation = property.getRotation();
        _collision = property.getCollision();
        _selection = property.getSelection();
        _creative = property.getCreative();
        _effect = effect;
    }

    /// @brief Generates the json object
    /// @param mod_id Namespace identifier
    /// @param id Identifier for the block
    /// @return json object
    json output(std::string mod_id, std::string id) {
        j = CandleBlock::output(mod_id, id);

        // Components
        j["minecraft:block"]["components"]["minecraft:queued_ticking"]
         ["interval_range"] = {600, 1200};
        j["minecraft:block"]["components"]["minecraft:queued_ticking"]
         ["on_tick"]["event"] = mod_id + ":effect_one";

        // Events
        j["minecraft:block"]["events"][mod_id + ":effect_one"]["run_command"]
         ["command"] = {"effect @e[r=4] " + _effect + " 10 0 true"};
        j["minecraft:block"]["events"][mod_id + ":effect_two"]["run_command"]
         ["command"] = {"effect @e[r=8] " + _effect + " 10 0 true"};
        j["minecraft:block"]["events"][mod_id + ":effect_three"]["run_command"]
         ["command"] = {"effect @e[r=12] " + _effect + " 10 0 true"};
        j["minecraft:block"]["events"][mod_id + ":effect_four"]["run_command"]
         ["command"] = {"effect @e[r=16] " + _effect + " 10 0 true"};

        j["minecraft:block"].erase("permutations");

        // Permutations
        j["minecraft:block"]["permutations"].push_back(
            {{"components",
              {{"minecraft:collision_box",
                {{"origin", {-3, 0, -1}}, {"size", {5, 6, 3}}}},
               {"minecraft:selection_box",
                {{"origin", {-3, 0, -1}}, {"size", {5, 6, 3}}}},
               {"minecraft:geometry", "geometry.candle_two"},
               {"minecraft:queued_ticking",
                {{"interval_range", {600, 1200}},
                 {"on_tick", {{"event", mod_id + ":effect_two"}}}}}}},
             {"condition", "q.block_property('" + mod_id + ":count') == 2"}});
        j["minecraft:block"]["permutations"].push_back(
            {{"components",
              {{"minecraft:collision_box",
                {{"origin", {-2, 0, -2}}, {"size", {5, 6, 5}}}},
               {"minecraft:selection_box",
                {{"origin", {-2, 0, -2}}, {"size", {5, 6, 5}}}},
               {"minecraft:geometry", "geometry.candle_three"},
               {"minecraft:queued_ticking",
                {{"interval_range", {600, 1200}},
                 {"on_tick", {{"event", mod_id + ":effect_three"}}}}}}},
             {"condition", "q.block_property('" + mod_id + ":count') == 3"}});
        j["minecraft:block"]["permutations"].push_back(
            {{"components",
              {{"minecraft:collision_box",
                {{"origin", {-3, 0, -3}}, {"size", {6, 6, 5}}}},
               {"minecraft:selection_box",
                {{"origin", {-3, 0, -3}}, {"size", {6, 6, 5}}}},
               {"minecraft:geometry", "geometry.candle_four"},
               {"minecraft:queued_ticking",
                {{"interval_range", {600, 1200}},
                 {"on_tick", {{"event", mod_id + ":effect_four"}}}}}}},
             {"condition", "q.block_property('" + mod_id + ":count') == 4"}});

        return j;
    };
};

#endif