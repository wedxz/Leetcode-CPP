//
//  AL_TwoArrayFind.cpp
//  LNDemo
//
//  Created by vvusu on 6/18/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

/*
 003-二维数组中的查找
 
 描述：
    在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 
 解题思路:
    如果是等于则查找成功；
    如果是数组中元素小于要查找的数字，说明要查找的数字应该在当前位置的右边或下边。
    如果是数组中元素大于要查找的数字，说明要查找的数字应该在当前位置的左边或上边。
*/

static bool twoArrayFind_right(vector<vector<int>> array,int target)
{
    bool res = false;
    int row = (int)array.size();
    int col = (int)array[0].size();
    
    //  我们从右上角的元素找起来
    //  如果查找的元素比当前位置元素小, 就向左走
    //  如果查找的元素比当前位置元素大, 就向下走
    for(int i = 0, j = col -1; (i >=0 && i < row) && (j >= 0 && j < col);)
    {
        if(target == array[i][j])
        {
            res = true;
            break;
        }
        else if(target < array[i][j])     // 小的元素在当前位置左侧
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return res;
}

static bool twoArrayFind_left(vector<vector<int>> array,int target)
{
    bool res = false;
    int row = (int)array.size();
    int col = (int)array[0].size();
    for (int i = row-1, j = 0; (i >= 0 && i < row) && (j >=0 && j < col);)
    {
        if (target == array[i][j])
        {
            res = true;
            break;
        }
        else if (target < array[i][j])
        {
            i--;
        }
        else
        {
            j++;
        }
    }
    return res;
}

// 测试
static void twoArrayFind_test()
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));
    
    string msg = "二维数组: YES";
    twoArrayFind_left(array, 4);
    if (!twoArrayFind_right(array, 4))
    {
        msg = "二维数组: NO";
    }
    cout <<msg <<endl;
}
