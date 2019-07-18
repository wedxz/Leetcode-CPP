//
//  AL_225_ImplementStackUsingQueues.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/15/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

// 225. 用队列实现栈
// https://leetcode.com/problems/implement-stack-using-queues/


class AL_225_ImplementStackUsingQueues {
public:
    /** Initialize your data structure here. */
    queue<int> inQueue,outQueue;
    AL_225_ImplementStackUsingQueues() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while (!outQueue.empty()) {
            inQueue.push(outQueue.front());
            outQueue.pop();
        }
        outQueue.push(x);
        while (!inQueue.empty()) {
            outQueue.push(inQueue.front());
            inQueue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = outQueue.front();
        outQueue.pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return outQueue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return outQueue.empty();
    }
};
