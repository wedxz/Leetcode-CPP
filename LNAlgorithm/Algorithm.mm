//
//  Arithmetic.m
//  LNDemo
//
//  Created by vvusu on 4/25/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#import "Algorithm.h"
// 经典排序
#include "Sort/AL_quickSort.cpp"
#include "Sort/AL_bubbleSort.cpp"
// 剑指Offer
#include "Jianzhioffer/AL_TwoArrayFind.cpp"
#include "Jianzhioffer/AL_ReplaceSpace.cpp"
#include "Jianzhioffer/AL_PrintListFromTailToHead.cpp"
#include "Jianzhioffer/AL_ReConstructBinaryTree.cpp"
#include "Jianzhioffer/AL_CustomQueue.cpp"
#include "Jianzhioffer/AL_MinNumberInRotateArray.cpp"
// Leetcode
#include "Leetcode/AL_TwoSum.cpp"
#include "Leetcode/AL_AddTwoNumbers.cpp"
#include "Leetcode/AL_LongestSubstring.cpp"

@interface Algorithm ()
@end

@implementation Algorithm

- (void)dealloc {}

- (void)run
{
    [self sort];
    [self jianzhioffer];
    [self leetcode];
}

#pragma mark - 剑指Offer
- (void)sort
{
    quickSort_test();
    bubbleSrot_test();
}

#pragma mark - 剑指Offer
-(void)jianzhioffer
{
#pragma mark - 003二维数组中的查找
    //    twoArrayFind_test();
    
#pragma mark - 004-替换空格
    //    replaceSpace_test();
    
#pragma mark - 005-从尾到头打印链表
    //    printListFromTailToHead_test();
    
#pragma mark - 006-重建二叉树
    reConstructBinaryTree_test();
    
#pragma mark - 007-用两个栈实现队列
    //    customQueue_test();
    
#pragma mark - 008-旋转数组的最小数字
//    minNumberInRotateArray_test();
}

#pragma mark - Leetcode
- (void)leetcode
{
    
#pragma mark -
    //    twoSum_test();
#pragma mark -
    //    addTwoNumbers_test();
#pragma mark -
    //    lengthOfLongestSubstring_test();
}

@end
