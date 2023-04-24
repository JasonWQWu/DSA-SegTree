#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "SegTree.h"
//#include "SegTree.cpp"

std::vector<SegNode> readFile(std::string filename){
    std::vector<SegNode> ArrayNodes;
    std::ifstream data(filename);
    if (data.is_open()) {
        std::string line;
        std::getline(data,line);
        while (getline(data, line)) {
            std::istringstream ss(line);
            std::string timestamp;
            int value;
            getline(ss, timestamp, ',');
            ss >> value;
            //date_time.push_back(timestamp);
            //cars.push_back(value);
            SegNode node = SegNode(value,timestamp);
            ArrayNodes.push_back(node);
//            Node.set_date_time(timestamp);
//            Node.set_cars(value);
        }
        data.close();
    }
    return ArrayNodes;
}





int main(int argc, char* argv[]) {
    std::string data = argv[1];

    std::vector<SegNode> ArrayNode = readFile(data);

    // std::vector<SegNode>::iterator it = ArrayNode.begin();
    // std::cout << "[";
    // for(int i = 0; i < 10; i++){
    //     std::cout << "[" << it[i].get_cars() << ", " << it[i].get_date_time() << "]";
    //     i < 9 ? std::cout << ", " : std::cout << "]";
    // }

    SegTree *seg_tree = new SegTree(ArrayNode);
    int len = ArrayNode.size();
    int input = 0;

    // UI
    while (input != -1) {
        std::cout << "-------------------------------------------";
        std::cout << "\nChoose option:\n"
                  << "\t1. Find Max\n\t2. Update a value\n\t3. Output DOT file\n\t4. Quit\n"
                  << "-------------------------------------------\n";
        std::cin >> input;
        //std::cout << "TEST\n";

        switch (input) {
            case 1: {// Find Max
                //std::cout << "TEST\n";
                SegNode max = seg_tree->treeMax(seg_tree->getTree(), len, 0, len - 1);
                std::cout << "Cars: " << max.get_cars() << " | Date & Time: " << max.get_date_time() << std::endl;
                break;
            }
            case 2: {// Update Value
                int index, value;
                std::cout << "Enter an index (0-720) to update: \n";
                std::cin >> index;
                if (index >= 0 && index <= len - 1) {
                    std::cout << "Enter an value to update: \n";
                    std::cin >> value;
                    SegNode newSegNode = SegNode(value, ArrayNode[index].get_date_time());
                    seg_tree->update(ArrayNode, seg_tree->getTree(), 0, len - 1, index, newSegNode, 0);
                } else {
                    std::cout << "Not valid \n";
                    input = 2;
                }
                break;
                //seg_tree->update(ArrayNode, seg_tree->getTree(), 0, len-1, index, newSegNode, 0;)
                }
            case 3: {// Dot Gen
                seg_tree->genDot();
                std::cout << "DOT file will now generate after quitting.\n";
                break;
                }
            case 4: {// Quit
                input = -1;
                std::cout << "Quitting.\n";
                break;
                }
            default: {// Default
                std::cout << "Error: Not a valid option.\n";
                input = 0;
                }
        }
    }

    // // Test Max
    // int len = ArrayNode.size();

    // SegNode max = seg_tree->treeMax(seg_tree->getTree(), len, 0, len-1);
    // std::cout << max.get_cars() << " - " << max.get_date_time() << std::endl;

    // // Update Max
    // SegNode newSegNode = SegNode(921, "Updated Node");
    // seg_tree->update(ArrayNode, seg_tree->getTree(), 0, len-1, 20, newSegNode, 0);
    // max = seg_tree->treeMax(seg_tree->getTree(), len, 0, len-1);
    // std::cout << max.get_cars() << " - " << max.get_date_time() << std::endl;
    // newSegNode = SegNode(90, "Updated Node");
    // seg_tree->update(ArrayNode, seg_tree->getTree(), 0, len-1, 21, newSegNode, 0);
    // max = seg_tree->treeMax(seg_tree->getTree(), len, 0, len-1);
    // std::cout << max.get_cars() << " - " << max.get_date_time() << std::endl;

    // seg_tree->printTree();
    seg_tree->genDot();

}
