//
//  NSString+Tool.h
//  LNAlgorithm
//
//  Created by vvusu on 7/21/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Tool)

/*
 描述：给定一个字符串，返回无重复字符的最长子串的长度
 参数：NSString string
 返回值：NSInteger
 示例：输入 "bbbbb" 结果为 1
 */
+ (NSInteger)lengthOfLongestSubstring:(NSString *)string;

// 测试
+ (void)testLengthOfLongestSubstring;

@end

NS_ASSUME_NONNULL_END
