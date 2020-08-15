//
//  main.cpp
//  cppLinq_test
//
//  Created by Mingzhao Liu on 8/13/20.
//  Copyright © 2020 Mingzhao Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

#include "../cpplinq/CppLinq/cpplinq.hpp"

using namespace std;

vector<vector<int>> data;

int computes_a_sum ()
{
    using namespace cpplinq;
    
    int ints[] = {3,1,4,1,5,9,2,6,5,4};
    auto result =    from_array (ints)
                  >> where ([](int i) {return i%2 ==0;})  // Keep only even numbers
                  >> sum ()                               // Sum remaining numbers
                  ;
    return result;
}

void read_csv(string filePath, int numCols) {
    
    std::ifstream file(filePath);
    vector<int> row;
    
    if (!file.is_open()) {
        std::cout << "ERROR: FILE NOT OPEN" << endl;
    }
    
    while (file.good()) {
        
        string line;

        while (row.size() < numCols - 1) {
            getline(file, line, ',');
            row.push_back(std::stoi(line));
        }
        
        getline(file, line, '\n');
        row.push_back(std::stoi(line));
        
        data.push_back(row);
        row.clear();
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    read_csv("test.csv", 5);
    for (vector<int> vec: data) {
        for (int i = 0; i < vec.size() - 1; i++) {
            cout << vec[i] << ",";
        }
        cout << vec[vec.size() - 1] << endl;
    }
    
    return 0;
}


