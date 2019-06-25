//
//  AL_quickSort.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/24/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"

/*
 快速排序
*/

#pragma mark - A
// 算法导论
// 交换方法
static int quickSortPartition(vector<int> &vi, int low, int up)
{
    // 标记节点
    int pivot = vi[up];
    int i = low-1;
    for (int j = low; j < up; j++)
    {
        if(vi[j] <= pivot)
        {
            i++;
            swap(vi[i], vi[j]);
        }
    }
    swap(vi[i+1], vi[up]);
    return i+1;
}

static void quickSort(vector<int> &vi, int low, int up)
{
    if (low < up) {
        int mid = quickSortPartition(vi, low, up);
        quickSort(vi, low, mid-1);
        quickSort(vi, mid + 1, up);
    }
}

#pragma mark - B

// 通用版本
static void quickSortA(vector<int> &arr, int low, int high)
{
    if (high <= low) return;
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i] < key)
        {
            if (i == high){
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j] > key)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    quickSortA(arr, low, j - 1);
    quickSortA(arr, j + 1, high);
}

// Test
static void quickSort_test()
{
    int a[] = {3,5,7,9,2,3,1,0,7,5,4};
    vector<int> v(a, a+11);
    quickSortA(v, 0, (int)v.size()-1);
    cout<<"快速排序:\n";
    for(auto x:v) {
        cout<<x<<" ";
    }
    cout <<endl;
}
