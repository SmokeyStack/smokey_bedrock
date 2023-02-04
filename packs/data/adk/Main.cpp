#include <fstream>
#include <iostream>
#include <vector>

#include "Block.h"
#include "BlockProperty.h"
#include "HeadBlock.h"
#include "Registry.h"

int main() {
    const std::string MODID = "smokey_bedrock";
    Registry<Block> blocks(MODID);

    std::ifstream file("./data/adk/blocks.txt");
    std::string str;
    std::vector<std::string> block_list;
    while (std::getline(file, str)) block_list.push_back(str);

    for (const std::string& a : block_list)
        blocks.subscribe(a, new HeadBlock(BlockProperty::Property()));

    return 0;
}