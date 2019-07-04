//
//  AL_ReverseString.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/27/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 LeetCode 344
 Reverse String (反转字符串)
 */


static string reverseString(string s)
{
    int left = 0;
    int right = (int)s.size() - 1;
    while (left < right) {
        char c = s[left];
        s[left++] = s[right];
        s[right--] = c;

    }
    return s;
}


static void reverseString_test()
{
    string s = "hello";
    cout << "反转字符串: "<< s <<endl;
    cout << reverseString(s) <<endl;
}
