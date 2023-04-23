#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void readFile(std::string filename){
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
            SegNode node = node(value,timestamp);
            arrayName.push_back(node);
//            Node.set_date_time(timestamp);
//            Node.set_cars(value);
        }
        data.close();
    }
}
void generateDOT(SegTree nodes, std::string outputFileName ){
    std::ofstream dotFile(outputFileName);
    dotFile << "digraph G {" << std::endl;

    for (int i = 0; i < nodes.size(); i++){
        SegNode* node = node[i];
        if(!node) {
            continue;
        }
        dotFile << "  node" << i << " [label=\"" << node->cars << "\'];" << std::endl;
        if (node->left) {
            dotFile << "  node" << i << " -> node" << (2 * i + 1) << ";" << std::endl;
        }
        if (node->right) {
            dotFile << "  node" << i << " -> node" << (2 * i + 2) << ";" << std::endl;
        }
    }
    dotFile << "}" << std::endl;
    dotFile.close();
};





int main(int argc, char* argv[]) {
    std::ifstream data(argv[1]);
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
            SegNode node = node(value,timestamp);
            arrayName.push_back(node);
//            Node.set_date_time(timestamp);
//            Node.set_cars(value);
        }
        data.close();
    }

}
