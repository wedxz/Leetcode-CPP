//
//  Arithmetic.m
//  LNDemo
//
//  Created by vvusu on 4/25/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#import "Algorithm.h"

// 经典排序
#include "Sort/AL_Sort.cpp"

// 剑指Offer
#include "Jianzhioffer/AL_CustomQueue.cpp"
#include "Jianzhioffer/AL_Fibonacci.cpp"
#include "Jianzhioffer/AL_MinNumberInRotateArray.cpp"
#include "Jianzhioffer/AL_PrintListFromTailToHead.cpp"
#include "Jianzhioffer/AL_ReConstructBinaryTree.cpp"
#include "Jianzhioffer/AL_ReplaceSpace.cpp"
#include "Jianzhioffer/AL_TwoArrayFind.cpp"

// Leetcode
#include "Leetcode/AL_AddTwoNumbers.cpp"
#include "Leetcode/AL_BalancedTree.cpp"
#include "Leetcode/AL_GetIntersectionNode.cpp"
#include "Leetcode/AL_HasCycleList.cpp"
#include "Leetcode/AL_InvertTree.cpp"
#include "Leetcode/AL_LongestSubstring.cpp"
#include "Leetcode/AL_MaxDepthTree.cpp"
#include "Leetcode/AL_ReverseString.cpp"
#include "Leetcode/AL_SameTree.cpp"
#include "Leetcode/AL_SymmetricTree.cpp"
#include "Leetcode/AL_TwoSum.cpp"
#include "Leetcode/AL_UglyNumber.cpp"
#include "Leetcode/AL_PowerOfTwo.cpp"
#include "Leetcode/AL_PowerOfThree.cpp"
#include "Leetcode/AL_CountPrimes.cpp"

@interface Algorithm ()
@end

@implementation Algorithm

- (void)dealloc
{
}

- (void)run
{
    [self sort];
//    [self jianzhioffer];
//    [self leetcode];
}

#pragma mark - 基础排序算法

- (void)sort
{
    sortTest();
    
    // 二分法查找
//    binarySearch_test();
}


#pragma mark - 剑指Offer
- (void)jianzhioffer
{
    // 003 - 二维数组中的查找
    twoArrayFind_test();
    
    // 004 - 替换空格
    replaceSpace_test();
    
    // 005 - 从尾到头打印链表
    printListFromTailToHead_test();
    
    // 006 - 重建二叉树
    reConstructBinaryTree_test();
    
    // 007 - 用两个栈实现队列
    customQueue_test();
    
    // 008 - 旋转数组的最小数字
    minNumberInRotateArray_test();
    
    // 009 - 斐波那契数列
    fibonacci_test();
}

#pragma mark - Leetcode
- (void)leetcode
{
//    // 001 -
//    twoSum_test();
//
//    addTwoNumbers_test();
//
//    lengthOfLongestSubstring_test();
    
    [self leetcode_math];
//    [self leetcode_list];
//    [self leetcode_tree];
//    [self leetcode_array];
//    [self leetcode_string];
}


#pragma mark - 数学相关问题
- (void)leetcode_math
{
    // 204 - Count Primes （质数的个数）
    countPrimes_test();

    // 231 - Is Power Of Two（是否是2的幂）
    powerOfTwo_test();

    // 263 - Is Ugly Number（是否是丑数）
    uglyNumber_test();
    
    // 326 - Is Power Of Three（是否是3的幂）
    powerOfThree_test();
}

#pragma mark - 链表相关问题
- (void)leetcode_list
{
    // 141 - Linked List Cycle (链表是否有环)
    hasCycleList_test();
    
    // 160 - Intersection Of Two Linked Lists (两个链表是否有交点)
    getIntersectionNode_test();
}

#pragma mark - 数组相关问题
- (void)leetcode_array
{
    
}

#pragma mark - 字符串相关问题
- (void)leetcode_string
{
    // LeetCode 344 - Reverse String（反转字符串）
    reverseString_test();
}

#pragma mark - 二叉树相关问题
- (void)leetcode_tree
{
    // 100 - Is Same Tree（树是否相等）
    sameTree_test();
    
    // 101 - Symmetric Tree（是否是镜像树）
    symmetricTree_test();
    
    // 104 - Maximum Depth of Binary Tree（二叉树的深度）
    maxDepthTree_test();
    
    // 110 - Balanced Binary Tree（是否是平衡二叉树）
    balancedTree_test();
    
    // 226 - Invert Binary Tree（反转二叉树）
    invertTree_test();
}

@end
