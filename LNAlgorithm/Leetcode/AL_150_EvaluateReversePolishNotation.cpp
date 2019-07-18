//
//  AL_150_EvaluateReversePolishNotation.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/15/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

// 150. 逆波兰表达式求值
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class AL_150_EvaluateReversePolishNotation {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        stack.push(0);
        for (int i = 0; i < tokens.size(); i++) {
            string c = tokens[i];
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int v = stack.top();
                stack.pop();
                int w = stack.top();
                stack.pop();
                if (c == "+") {
                    stack.push(w + v);
                } else if (c == "-"){
                    stack.push(w - v);
                } else if (c == "*"){
                stack.push(w * v);
                } else if (c == "/"){
                    stack.push(w / v);
                }
            } else {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};
