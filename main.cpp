#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "SegTree.h"

// % g++ -std=c++11 main.cpp SegTree.cpp -o main && ./main traffic.txt

// Return vector<SegNode> containing timestamp and car number
std::vector<SegNode> readFile(std::string filename){
    
    // Initialize file and the vector of type SegNode
    std::vector<SegNode> ArrayNodes;
    std::ifstream data(filename);
    
    // Read each line and store the first part of the file
    // into the timestamp and second part into cars.
    if (data.is_open()) {
        std::string line;
        std::getline(data,line);
        while (getline(data, line)) {
            std::istringstream ss(line);
            std::string timestamp;
            int value;
            getline(ss, timestamp, ',');
            ss >> value;

            // Create node and push into arrray
            SegNode node = SegNode(value,timestamp);
            ArrayNodes.push_back(node);
        }
        data.close();
    }
    return ArrayNodes;
}


int main(int argc, char* argv[]) {
    
    // Name of file
    std::string data = argv[1];

    // Get data from file
    std::vector<SegNode> ArrayNode = readFile(data);
    
    // Create Segment Tree
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


        switch (input) {
            // Find Max
            case 1: {
                SegNode max = seg_tree->treeMax(seg_tree->getTree(), len, 0, len - 1);
                std::cout << "Cars: " << max.get_cars() << " | Date & Time: " << max.get_date_time() << std::endl;
                break;
            }
            // Update Value
            case 2: {
                int index, value;
                std::cout << "Enter an index (0-" << ArrayNode.size() - 1 << ") to update: \n";
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
            // Dot Gen
            case 3: {
                seg_tree->genDot();
                std::cout << "DOT file will now generate after quitting.\n";
                break;
            }
            // Quit
            case 4: {
                input = -1;
                std::cout << "Quitting.\n";
                break;
            }
            // Default
            default: {
                std::cout << "Error: Not a valid option.\n";
                input = 0;
            }
        }
    }
    
    // Create dot file of segment tree
    seg_tree->genDot();
}
