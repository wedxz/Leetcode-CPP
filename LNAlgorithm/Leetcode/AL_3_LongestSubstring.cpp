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

static int lengthOfLongestSubstring(string s)
{
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

// 测试
static void lengthOfLongestSubstring_test()
{
    //    string str = "abcabcbb";
    string str = "bbbbbbb";
    int lenth = lengthOfLongestSubstring(str);
    cout << "无重复字符的最长子串:" << str << "\n" << lenth << endl;
}
