//
//  AL_856_ScoreOfParentheses.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/14/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


/*
 856. 括号的分数
 https://leetcode.com/problems/score-of-parentheses/
 
 Given a balanced parentheses string S, compute the score of the string based on the following rule:
 
 () has score 1
 AB has score A + B, where A and B are balanced parentheses strings.
 (A) has score 2 * A, where A is a balanced parentheses string.
 */


class AL_856_ScoreOfParentheses {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        st.push(0);
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                st.push(0);
            } else {
                int v = st.top();
                st.pop();
                int w = st.top();
                st.pop();
                st.push(w + max(2 * v , 1));
            }
        }
        return st.top();
    }
};
