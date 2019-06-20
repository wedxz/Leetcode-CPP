//
//  AL_ReplaceSpace.cpp
//  LNDemo
//
//  Created by vvusu on 6/18/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include <stdio.h>
#include <iostream>

/*
 004-替换空格
 
 描述:
    请实现一个函数，将一个字符串中的空格替换成“%20”。 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 
 示例:
    We Are Happy
    We%20Are%20Happy
 
 解题思路:
    遍历一遍字符串,统计字符出现的数目, 计算替换后的字符串长度
    再遍历一遍字符串，完成替换
 */

static void replaceSpace(char *str, int length)
{
    int count = 0;
    for (int i = 0; i < length ; i++)
    {
        // 如果当前字符是空格
        if (str[i] == ' ')
        {
            count++;
        }
    }

    int len = length + count * 2;
    for (int i = length -1, j = len -1; i >= 0 && j >= 0;)
    {
        if(str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            i--;
        }
        else
        {
            str[j--] = str[i--];
        }
    }
    str[len] = '\0';
}

// Test
static void replaceSpace_test()
{
    // 初始化长度必须够，要不执行完后会崩溃
    char str[20] = "a b c d";
    replaceSpace(str, 10);
    std::cout <<str <<std::endl;
}
