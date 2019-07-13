//
//  AL_PowerOfTwo.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


static bool powerOfTwo(int num)
{
    if (num == 1) {
        return true;
    }
    if (num >= 2 && num %2 == 0) {
        return powerOfTwo(num/2);
    }
    return false;
}


static void powerOfTwo_test()
{
    cout <<  powerOfTwo(8) << endl;
}
