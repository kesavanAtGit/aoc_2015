#include <iostream>
#include <fstream>
#include <string>

size_t calculateFloor() {
    std::fstream file("01_AOC_2015_input.txt", std::ios::in);

    if(!file) {
        std::cerr << "File not found!" << '\n';
    }

    size_t floor;
    size_t charPosition;

    while(!file.eof()) {
        char ch = file.peek();
        if(ch == '(') {
            ++floor;
        }else if(ch == ')') {
            --floor;
        }
        if(floor == -1) {
            charPosition = file.tellg();
            break;
        }
        file.get();

    }
    return charPosition + 1;
}

int main() {
    std::cout << calculateFloor();
    return 0;
}
