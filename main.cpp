#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "SegTree.h"
#include "SegTree.cpp"

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
