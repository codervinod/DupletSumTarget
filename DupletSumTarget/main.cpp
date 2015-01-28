//
//  main.cpp
//  DupletSumTarget
//
//  Created by Vinod Gupta on 1/28/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <unordered_map>
#include <iostream>

void printArray(int ar[], int high)
{
    for (int i = 0; i < high; ++i)
    {
        std::cout << ar[i] << "\t";
    }
    std::cout << std::endl;
}

bool findDupletWithSum(int ar[], int high, int sum)
{
    //Two iterations, in first one we can insert it into a hash
    //In second iteration we will check if target exists
    bool found = false;
    std::unordered_map<int, int> HashMap;
    for (int i = 0; i < high; ++i)
    {
        HashMap[ar[i]]= i;
    }
    
    int i = 0;
    while (i < high)
    {
        int target = sum - ar[i];
        std::unordered_map<int, int>::iterator itr = HashMap.find(target);
        if (itr != HashMap.end() && itr->second != i)
        {
            std::cout << "(" << ar[i] << "," << itr->first << ")";
            found = true;
        }
        ++i;
    }
    if (!found)
        std::cout << "Not found" << std::endl;
    return found;
}

int main(int argc, char* argv[])
{
    int ar[] = { 4, 9, 2, 7, 34, 12, 42, 22, 52 };
    int high = sizeof ar / sizeof(int);
    
    printArray(ar, high);
    findDupletWithSum(ar, high, 11);
    std::cout << std::endl;
    return 0;
    
}
