#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {

    std::ifstream data;
    std::string line;

    data.open(argv[1]);
    while(std::getline(data,line)) {
        std::string entry, date, time, value;
        std::istringstream iss(line);
        iss >> date >> time >> value;
        std::cout << date << " " << time << " " << value << std::endl;

        // Made node with time and value
        // Append to array
        // Make tree
    }
}
