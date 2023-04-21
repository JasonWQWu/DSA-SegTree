#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {

    std::ifstream data;
    std::string line;

    data.open(argv[1]);
    while(std::getline(data,line)) {
        std::string entry, time, value;
        std::istringstream iss(line);
        iss >> time >> value;
        std::cout << time << " " << value << std::endl;

        // Made node with time and value
        // Append to array
        // Make tree
    }
}
