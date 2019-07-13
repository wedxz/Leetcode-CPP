//
//  AL_PowerOfThree.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"



static bool powerOfThree(int n)
{
    if (n > 1){
        while (n %3 == 0) {
            n /= 3;
        }
    }
    return n==1;
}

static void powerOfThree_test()
{
    cout << powerOfThree(9)<< endl;
}
