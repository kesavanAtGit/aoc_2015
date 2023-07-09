#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

size_t slack(size_t l, size_t w, size_t h) {
    size_t side1 = l*w;
    size_t side2 = w*h;
    size_t side3 = h*l;

    size_t smallestSideArea = side1;
    if(side2 < smallestSideArea) {
        smallestSideArea = side2;
    }
    if(side3 < smallestSideArea) {
        smallestSideArea = side3;
    }
    return smallestSideArea;
}

size_t surfaceArea(size_t l, size_t w, size_t h) {
    size_t surfaceArea = 2*l*w + 2*w*h + 2*h*l;
    return surfaceArea;
}

std::vector<size_t> getDimension(const std::string& str, char delimiter) {
    std::istringstream stringStream(str);

    std::string dimensionStr;
    std::vector<size_t> dimension;
    while(std::getline(stringStream, dimensionStr, delimiter)) {
        dimension.push_back(std::stoi(dimensionStr));
    }
    return dimension;
}

size_t volume(size_t l, size_t w, size_t h) {
    return l*w*h;
}

size_t perimeter(size_t l, size_t w, size_t h) {
    size_t sideOne = l + w;
    size_t sideTwo = w + h;
    size_t sideThree = l + h;

    size_t smallestPerimeter = sideOne;

    if(sideTwo < smallestPerimeter) {
        smallestPerimeter = sideTwo;
    }
    if(sideThree < smallestPerimeter) {
        smallestPerimeter = sideThree;
    }
    return 2*smallestPerimeter;
}

size_t totalFeet() {
    std::fstream file("02_AOC_2015_input.txt", std::ios::in);

    if(!file) {
        std::cerr << "Can't find the file. \n";
    }

    size_t sqrFeet = 0;
    std::string input;

    while(std::getline(file, input)) {
        std::vector<size_t> dimensionVec;
        dimensionVec = getDimension(input, 'x');

        size_t l = dimensionVec[0];
        size_t w = dimensionVec[1];
        size_t h = dimensionVec[2];

        sqrFeet += surfaceArea(l, w, h) + slack(l, w, h);
    }
    file.close();
    return sqrFeet;
}

size_t ribbonFeet() {
    std::fstream file("02_AOC_2015_input.txt", std::ios::in);

    if(!file) {
        std::cerr << "Can't find the file. \n";
    }

    size_t sqrFeet = 0;
    std::string input;

    while(std::getline(file, input)) {
        std::vector<size_t> dimensionVec;
        dimensionVec = getDimension(input, 'x');

        size_t l = dimensionVec[0];
        size_t w = dimensionVec[1];
        size_t h = dimensionVec[2];

        sqrFeet += volume(l, w, h) + perimeter(l, w, h);
    }
    file.close();
    return sqrFeet;
}

int main() {
    std::cout << totalFeet() << '\n';
    std::cout << ribbonFeet();
    return 0;
}
