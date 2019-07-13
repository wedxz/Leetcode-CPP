//
//  AL_CountPrimes.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


// 是否是质数
static bool isPrime(int num)
{
    for (int i = 3; i <= sqrt(num); i +=2) {
        if(num % i == 0) {
            return false;
        }
    }
    return true ;
}

// 一个数里面有多少个质数
static int countPrimes(int n)
{
    int count = 0;
    if (n > 2) {
        count++;
    }
    for (int i = 3; i < n; i +=2) {
        if(isPrime(i)) {
            count++;
        }
    }
    return count;
}

static void countPrimes_test()
{
    cout << countPrimes(10)<< endl;
}
