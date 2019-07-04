//
//  AL_Fibonacci.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/3/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

static long long fibonacci(int n)
{
    int result[2] = {0, 1};
    if(n < 2){
        return result[n];
    }
    long long one = 1;
    long long num = 0;
    for(int i = 2; i <= n; i++){
        num = num + one;
        one = num - one;
    }
    return num;
}


static void fibonacci_test()
{
    cout << "斐波那契数列 64:" << fibonacci(8) <<endl;
}
