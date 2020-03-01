//
//  NSString+Tool.m
//  LNAlgorithm
//
//  Created by vvusu on 7/21/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#import "NSString+Tool.h"

@implementation NSString (Tool)

/*
 描述：给定一个字符串，返回无重复字符的最长子串的长度
 参数：NSString 类型 string
 返回值：NSInteger 类型
 示例：输入 "abcabcbb" 结果为 3
 */
+ (NSInteger)lengthOfLongestSubstring:(NSString *)string
{
    NSString *subString = [self subStringOfLongestString:string];
    return subString.length;
}

/*
 描述：给定一个字符串，返回无重复字符的最长子串
 参数：NSString 类型 string
 返回值：NSString 类型
 示例：输入 "abcabcbb" 结果为 "abc"
 */
+ (NSString *)subStringOfLongestString:(NSString *)string
{
    if (!string || ![string isKindOfClass:[NSString class]]) {
        // 如果类型不匹配可以强制抛异常，或者直接返回 nil
//        @throw [[NSException alloc] initWithName:@"参数类型错误" reason:@"类型不是 NSString 类型" userInfo:nil];
        return nil;
    }
    // 字符串长度 如果为空 或者 为1直接返回
    if (string.length == 0 || string.length == 1) {
        return string;
    }
    NSString *subString = nil;
    NSInteger array[256] = {0};
    // 最后子串的起始位置记录
    NSInteger start = 0;
    // 窗口 left 开始 right 结束
    NSInteger left = 0;
    NSInteger right = -1;
    // 最长字串的长度
    NSInteger maxLength = 0;
    NSInteger len = string.length;
    const char *chars = [string UTF8String];
    // 从头开始循环，到 len 截止，每次循环逐渐改变窗口，记录窗口中是否找到新的最大值
    while (left < len) {
        if (right + 1 < len && array[chars[right + 1]] == 0) {
            right++;
            array[chars[right]]++;
        } else {
            array[chars[left]]--;
            left++;
        }
        // 比较窗口区间最大的长度，如果改变，记录新的起始位置
        if (maxLength < right - left + 1) {
            maxLength = right - left + 1;
            start = left;
        }
    }
    // 截取最后的子串
    subString = [string substringWithRange:NSMakeRange(start, maxLength)];
    return subString;
}

/*
 描述：给定一个字符串，返回无重复字符的最长子串的长度
 参数：NSString 类型
 返回值：NSInteger 类型
 示例：输入 "bbbbb" 结果为 1
 */
+ (NSInteger)lengthOfLongestSubstring2:(NSString *)string
{
    if (!string || ![string isKindOfClass:[NSString class]]) {
        // 如果类型不匹配可以强制抛异常
        // @throw [[NSException alloc] initWithName:@"参数类型错误" reason:@"类型不是 NSString 类型" userInfo:nil];
        return 0;
    }
    // 字符串长度 如果为空 或者 为1直接返回
    if (string.length == 0) {
        return 0;
    } else if(string.length == 1) {
        return 1;
    }
    // 最长字符串的左边的起始位置
    NSInteger left = 0;
    // 最大的长度
    NSInteger maxLength = 0;
    NSMutableDictionary *dic = [NSMutableDictionary dictionary];
    for (NSInteger i = 0; i < string.length; i++) {
        // 从string 中取出一个字符
        NSString *subStr = [string substringWithRange:NSMakeRange(i, 1)];
        // 在字典中查找是否有 subStr，如果有的话，更新左边的起始位置
        if ([dic valueForKey:subStr]) {
            left = MAX(left, [[dic valueForKey:subStr] integerValue]);
        }
        // 比较之前的字符串长度和当前 i - left 的字符串长度哪个大
        maxLength = MAX(maxLength, i - left);
        [dic setValue:@(i) forKey:subStr];
    }
    return maxLength;
}

// 测试
+ (void)testLengthOfLongestSubstring
{
    NSString *string = nil;
    string = @"abcabcbb";
    string = @"bbbbb";
    string = @"pwwkew";
    string = @"中文文字";
    NSLog(@"%@ 的最长子串长度为: %ld",string, [NSString lengthOfLongestSubstring:string]);
    NSLog(@"%@ 的最长子串长度为: %ld",string, [NSString lengthOfLongestSubstring2:string]);
    NSLog(@"%@ 的最长子串为: %@",string, [NSString subStringOfLongestString:string]);
}

/*
 解题思路：
 创建一个256位的整型数组，来对应字符出现位置之间的映射，
 维护一个滑动窗口，窗口中是没有重复的字符，窗口一直向右边滑动，
 如果子字符没有出现过，就扩大窗口右边，如果字符出现过，则左边窗口向右边移动，
 然后重复上面步骤，直到左边索引无法移动。
 同时要维护一个 start值 和 maxLength值，记录无重复最长字串的起始位置，以及最大长度。
 */

@end
