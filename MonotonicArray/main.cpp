//
//  main.cpp
//  MonotonicArray
//
//  Created by adeeb mohammed on 17/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
// program to find whether the array is monotonic
// monotonic means that the array is strictly decreasing or increasing from its left right

#include <vector>
#include <iostream>

bool isBreakDirection(int flowDirection, int num1, int num2){
    int difference = num2 - num1;
    if(flowDirection > 0){
        return difference < 0;
    }
    return difference > 0;
}

bool isMonotonicNormal(std::vector<int> array) {
    if (array.size() < 3) {
        return true;
    }
    int flowDirection = array.at(1) - array.at(0);
    
    for (auto i = 2; i < array.size(); i++) {
        if (flowDirection == 0) {
            flowDirection = array.at(i) - array.at(i-1);
            continue;
        }
        if (isBreakDirection(flowDirection,array.at(i-1), array.at(i))) {
            return false;
        }
            
    }
    return true;
}


bool isMonotonic(std::vector<int> array){
    bool isNonIncreasing = true;
    bool isNonDecreasing = true;
    
    for(int i = 1 ; i < array.size(); i++){
        if(array.at(i) > array.at(i-1)){
            isNonIncreasing = false;
        }else if(array.at(i) < array.at(i-1)){
            isNonDecreasing = false;
        }
    }
    
    return isNonDecreasing || isNonIncreasing;
}

int main(int argc, const char * argv[]) {
    std::cout << "Program to check whether the array is monotic" << std::endl;
    std::cout << isMonotonicNormal({-1,2,3,4,-222});
    return 0;
}
