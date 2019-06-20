//
//  AL_CustomQueue.cpp
//  LNDemo
//
//  Created by vvusu on 6/20/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 007-用两个栈实现队列
 
 描述:
    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 
 示例:
 
 解题思路:
    1. 入队时，将元素压入s1。
    2. 出队时，将s1的元素逐个“倒入”（弹出并压入）s2，将s2的顶元素弹出作为出队元素，之后再将s2剩下的元素逐个“倒回”s1。
 
    上述思路，有些变种，如：
        入队时，先判断s1是否为空，如不为空，说明所有元素都在s1，此时将入队元素直接压入s1；如为空，要将s2的元素逐个“倒回”s1，再压入入队元素。
        出队时，先判断s2是否为空，如不为空，直接弹出s2的顶元素并出队；如为空，将s1的元素逐个“倒入”s2，把最后一个元素弹出并出队。
         有些人能同时想到大众方法和变种，应该说头脑还是比较灵光的。
 
    1. 入队时，将元素压入s1。
    2. 出队时，判断s2是否为空，如不为空，则直接弹出顶元素；如为空，则将s1的元素逐个“倒入”s2，把最后一个元素弹出并出队。
       这个思路，避免了反复“倒”栈，仅在需要时才“倒”一次。但在实际面试中很少有人说出，可能是时间较少的缘故吧。
 */

class CustomQueue {
    
private:
    stack<int> stackIn;
    stack<int> stackOut;
    
public:
    void push(int node)
    {
        stackIn.push(node);
    }
    
    int pop()
    {
        int node = -1;
        if (this->empty())
        {
            debug <<"整个队列为NULL" <<endl;
            return -1;
        }
        else
        {
            if (stackOut.empty())
            {
                while (!stackIn.empty())
                {
                    node = stackIn.top();
                    stackIn.pop();
                    stackOut.push(node);
                }
            }
            node = stackOut.top();
            stackOut.pop();
        }
        return node;
    }
    
    bool empty()
    {
        return (stackIn.empty() && stackOut.empty());
    }
};


static void customQueue_test()
{
    CustomQueue solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);
    while(solu.empty() != true)
    {
        cout <<solu.pop( );
    }
}
