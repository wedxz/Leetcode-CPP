//
//  AL_OtherSort.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

// 二分法查找元素
static int binarySearch(vector<int> &arr, int num)
{
    int low = 0;
    int high = (int)arr.size() - 1;
    if (low <= high) {
        int middle = (high - low) / 2 + low;
        if (arr[middle] == num) {
            return middle;
        } else if (arr[middle] > num) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    return -1;
}

static void binarySearch_test()
{
    
}
