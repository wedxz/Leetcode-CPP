//
//  AL_224_BasicCalculator.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/15/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

// 224. 基本计算器
// https://leetcode.com/problems/basic-calculator/

class AL_224_BasicCalculator {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                int cur = c - '0';
                while (i+1 < s.length() && (s[i+1] >= '0' && s[i+1] <= '9')) {
                    cur = cur * 10 + (s[++i] - '0');
                }
                res += sign * cur;
            } else if (c  == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                res = 0;
                st.push(sign);
                sign = 1;
            } else if (c == ')') {
                res = st.top() * res;
                st.pop();
                res += st.top();
                st.pop();
                sign = 1;
            }
        }
        return res;
    }
};

