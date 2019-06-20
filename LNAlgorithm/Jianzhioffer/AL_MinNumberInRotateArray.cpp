//
//  AL_ MinNumberInRotateArray.cpp
//  LNDemo
//
//  Created by vvusu on 6/20/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 008-旋转数组的最小数字
 
 描述:
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减序列的一个旋转，输出旋转数组的最小元素。
 
 示例:
    数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
    该数组的最小值为1。
 
 解题思路:
    1. 旋转之后的数组存在两个上升序列，最小元素在两个上升序列的中间
    2. 用两个指针在两个序列中找到最大和最小的值，这样 end 指向的数则为最小
 */

// 顺序寻找最小值
static int MinOrder(vector<int> &num, int low, int high)
{
    int result = num[low];
    for(int i = low + 1; i < high; i++)
    {
        if(num[i] < result)
        {
            result = num[i];
        }//if
    }//for
    return result;
}

static int minNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.size() == 0)
    {
        debug <<"非法输入" <<endl;
        return 0;
    }
    
    //  如果把排序数组前面0个元素搬到后面，也就是说其实没有旋转，
    //  那么第0个元素就是最小的元素
    //  因此我们将mid初始化为0
    int mid = 0;
    int low = 0, high = (int)rotateArray.size( ) - 1;
    if(rotateArray[low] < rotateArray[high])
    {
        debug <<"数组未被旋转" <<endl;
    }
    while(rotateArray[low] >= rotateArray[high])
    {
        //  如果前一个元素与后一个元素差一位
        //  说明找到了最大最小的元素
        if(high - low == 1)
        {
            mid = high;
            debug <<"min = " <<low <<", high = " <<high <<endl;
            break;
        }
        
        mid = (low + high) / 2;
        debug <<rotateArray[low] <<", " <<rotateArray[mid] <<", " <<rotateArray[high] <<endl;
        
        // rotateArray[low] rotateArray[mid] rotateArray[high]三者相等
        // 无法确定中间元素是属于前面还是后面的递增子数组
        // 只能顺序查找
        if(rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high])
        {
            debug <<"low == mid == high, so we should order it" <<endl;
            return MinOrder(rotateArray, low, high);
        }
        //  如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素
        if(rotateArray[mid] >= rotateArray[low])
        {
            low = mid;          //  此时最小的元素位于中间元素的后面
        }
        // 如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指 向的元素
        else if(rotateArray[mid] <= rotateArray[high])
        {
            high = mid;         //  此时最小的元素位于中间元素的前面
        }
    }
    return rotateArray[mid];
}

// Test
static void minNumberInRotateArray_test()
{
    int a[] = { 1, 0, 1, 1, 1,};
    vector<int> vec(a, a + 5);
    cout << minNumberInRotateArray(vec) <<endl;
}
