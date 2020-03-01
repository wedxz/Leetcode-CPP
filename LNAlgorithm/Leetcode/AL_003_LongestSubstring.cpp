//
//  AL_LongestSubstring.cpp
//  LNDemo
//
//  Created by vvusu on 6/18/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

/*
 无重复字符的最长子串
 https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
 
 描述:
 给定一个字符串，找出不含有重复字符的最长子串的长度。
 
 示例:
 给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
 给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
 给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列
 而不是子串。
 
 解题思路:
 求无重复字符的最长子串的长度，从头到尾遍历字符串时（索引index），考虑到无重复字符，我们先把字符逐个放到容器set中，并更新最长子串的长度，
 如果遇到了重复字符，即当前遍历的字符在set中，则要从set中删除重复字符，包括这个重复字符前面的所有字符，也就是从当前子串的最左边（left）开始删除，
 直到删除重复字符。
 */

/*
 解题思路
 1.从头到尾遍历字符串时先把字符逐个放到容器set中，并更新最长子串的长度.
 2.如果遇到了重复字符，即当前遍历的字符在set中，则要从set中删除重复字符，包括这个重复字符前面的所有字符，从当前子串的最左边 left 开始删除，直到删除重复字符.
 */

static int lengthOfLongestSubstring(string s)
{
    if (s.empty()) {
        return 0;
//        throw "Division by zero condition!";
    }
    set<char> cache;
    int maxlen = 0;
    int left = 0;
    int index = 0;
    while (index < s.size()) {
        if (cache.find(s[index]) == cache.end()) {
            cache.insert(s[index++]);
            maxlen = max(maxlen, (int)cache.size());
        } else {
            cache.erase(s[left++]);
        }
    }
    return maxlen;
}

/*
  建立一个256位大小的整型数组 array ，用来建立字符和其出现位置之间的映射。
  维护一个滑动窗口，窗口内的都是没有重复的字符，去尽可能的扩大窗口的大小，窗口不停的向右滑动。
 （1）如果当前遍历到的字符从未出现过，那么直接扩大右边界；
 （2）如果当前遍历到的字符出现过，则缩小窗口（左边索引向右移动），然后继续观察当前遍历到的字符；
 （3）重复（1）（2），直到左边索引无法再移动；
 （4）维护一个结果maxlen，每次用出现过的窗口大小来更新结果 maxlen，最后返回 maxlen 获取结果。
 */

//

/*
 描述：给定一个字符串，返回无重复字符的最长子串的长度
 参数：string s
 返回值：int
 示例：输入 "bbbbb" 结果为 1
 */
static int lengthOfLongestSubstring2(string s)
{
    // throw "Division by zero condition!";
    // 如果为空 或者 为1直接返回
    if (s.size() == 0) {
        return 0;
    } else if(s.size() == 1) {
        return 1;
    }
    int array[256] = {0};
    int left = 0;
    int right = -1;
    int maxlen = 0;
    int len = (int)s.size();
    while (left < len) {
        if (right + 1 < len && array[s[right + 1]] == 0) {
            right++;
            array[s[right]]++;
        } else {
            array[s[left]]--;
            left++;
        }
        maxlen = max(maxlen, right - left + 1);
    }
    return maxlen;
}

// 给定一个字符串，返回无重复字符的最长子串
static string LongestSubstring21(string s)
{
    int array[256] = {0};
    int left = 0;
    int right = -1;
    int maxlen = 0;
    int len = (int)s.size();
    while (left < len) {
        if (right + 1 < len && array[s[right + 1]] == 0) {
            right++;
            array[s[right]]++;
        } else {
            array[s[left]]--;
            left++;
        }
        maxlen = max(maxlen, right - left + 1);
    }
    return "";
}

// 测试
static void lengthOfLongestSubstring_test()
{
//     string str = "abcabcbb";
     string str = "bbbbb";
//    string str = NULL;
//    int lenth = lengthOfLongestSubstring(str);
    int lenth = lengthOfLongestSubstring2(str);
    cout << "无重复字符的最长子串:" << str << "\n" << lenth << endl;
}
