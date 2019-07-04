//
//  AL_UglyNumber.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


// Is Ugly Number （是否是丑数）

static bool uglyNumber(int num)
{
    if (num == 0) {
        return false;
    } else if (num == 1) {
        return true;
    } else {
        while (num%2 == 0) {
            num /= 2;
        }
        while (num%3 == 0) {
            num /= 3;
        }
        while (num%5 == 0) {
            num /= 5;
        }
        if (num == 1) {
            return true;
        } else {
            return false;
        }
    }
}


static void uglyNumber_test()
{
    cout <<  uglyNumber(14) << endl;
}
