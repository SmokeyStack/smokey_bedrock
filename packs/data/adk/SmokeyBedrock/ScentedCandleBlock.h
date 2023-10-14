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
        _internal = property;
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
        json::object_t temp = {
            {"condition", "q.block_state('" + mod_id + ":count') == 2"}};
        temp["components"].update(
            helper.collision(std::make_pair(std::vector<int>{-3, 0, -1},
                                            std::vector<int>{5, 6, 3}),
                             id));
        temp["components"].update(
            helper.selection(std::make_pair(std::vector<int>{-3, 0, -1},
                                            std::vector<int>{5, 6, 3}),
                             id));
        temp["components"].update(
            {{"minecraft:queued_ticking",
              {{"interval_range", {600, 1200}},
               {"on_tick", {{"event", mod_id + ":effect_two"}}}}}});
        j["minecraft:block"]["permutations"].push_back(temp);
        temp = {{"condition", "q.block_state('" + mod_id + ":count') == 3"}};
        temp["components"].update(
            helper.collision(std::make_pair(std::vector<int>{-2, 0, -2},
                                            std::vector<int>{5, 6, 5}),
                             id));
        temp["components"].update(
            helper.selection(std::make_pair(std::vector<int>{-2, 0, -2},
                                            std::vector<int>{5, 6, 5}),
                             id));
        temp["components"].update(
            {{"minecraft:queued_ticking",
              {{"interval_range", {600, 1200}},
               {"on_tick", {{"event", mod_id + ":effect_three"}}}}}});
        j["minecraft:block"]["permutations"].push_back(temp);
        temp = {{"condition", "q.block_state('" + mod_id + ":count') == 4"}};
        temp["components"].update(
            helper.collision(std::make_pair(std::vector<int>{-3, 0, -3},
                                            std::vector<int>{6, 6, 5}),
                             id));
        temp["components"].update(
            helper.selection(std::make_pair(std::vector<int>{-3, 0, -3},
                                            std::vector<int>{6, 6, 5}),
                             id));
        temp["components"].update(
            {{"minecraft:queued_ticking",
              {{"interval_range", {600, 1200}},
               {"on_tick", {{"event", mod_id + ":effect_four"}}}}}});
        j["minecraft:block"]["permutations"].push_back(temp);

        return j;
    };
};

#endif