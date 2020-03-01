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
#include "Jianzhioffer/AL_03_TwoArrayFind.cpp"
#include "Jianzhioffer/AL_04_ReplaceSpace.cpp"
#include "Jianzhioffer/AL_05_PrintListFromTailToHead.cpp"
#include "Jianzhioffer/AL_06_ReConstructBinaryTree.cpp"
#include "Jianzhioffer/AL_07_CustomQueue.cpp"
#include "Jianzhioffer/AL_08_MinNumberInRotateArray.cpp"
#include "Jianzhioffer/AL_09_Fibonacci.cpp"

// Leetcode
#include "Leetcode/AL_001_TwoSum.cpp"
#include "Leetcode/AL_002_AddTwoNumbers.cpp"
#include "Leetcode/AL_003_LongestSubstring.cpp"
#include "Leetcode/AL_083_DeleteDuplicates.cpp"
#include "Leetcode/AL_100_SameTree.cpp"
#include "Leetcode/AL_101_SymmetricTree.cpp"
#include "Leetcode/AL_110_BalancedTree.cpp"
#include "Leetcode/AL_141_HasCycleList.cpp"
#include "Leetcode/AL_160_GetIntersectionNode.cpp"
#include "Leetcode/AL_203_RemoveElements.cpp"
#include "Leetcode/AL_204_CountPrimes.cpp"
#include "Leetcode/AL_226_InvertTree.cpp"
#include "Leetcode/AL_231_PowerOfTwo.cpp"
#include "Leetcode/AL_263_UglyNumber.cpp"
#include "Leetcode/AL_326_PowerOfThree.cpp"
#include "Leetcode/AL_344_ReverseString.cpp"

#import "NSString+Tool.h"

@interface Algorithm ()
@end

@implementation Algorithm

- (void)dealloc {}

- (void)run
{
    [NSString testLengthOfLongestSubstring];
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
    [self leetcode_math];
    [self leetcode_list];
    [self leetcode_tree];
    [self leetcode_array];
    [self leetcode_string];
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
    // 083 -
    
    // 141 - Linked List Cycle (链表是否有环)
    hasCycleList_test();
    
    // 160 - Intersection Of Two Linked Lists (两个链表是否有交点)
    getIntersectionNode_test();
    
    // 203 - 删除链表中的值
    removeElements_test();
}

#pragma mark - 数组相关问题
- (void)leetcode_array
{
    // 001 - 1. Two Sum
    twoSum_test();
    
    // 002 - 2. Add Two Numbers
    addTwoNumbers_test();
    
    // 003 - 3. Longest Substring Without Repeating Characters
    lengthOfLongestSubstring_test();
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
    // 101 - Symmetric Tree（是否是镜像树）
    // 104 - Maximum Depth of Binary Tree（二叉树的深度）
    // 110 - Balanced Binary Tree（是否是平衡二叉树）
    // 226 - Invert Binary Tree（反转二叉树）
}

@end
