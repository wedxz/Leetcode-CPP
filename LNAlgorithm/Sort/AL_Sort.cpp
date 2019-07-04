//
//  AL_Sort.cpp
//  LNAlgorithm
//
//  Created by vvusu on 7/4/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// 调试开关
#define __tmain main
#ifdef __tmain
#define debug cout
#else
#define debug 0 && cout
#endif


// 打印排序
static void printSrotArray(vector<int> &v, string name)
{
    cout << name <<":\n";
    for (auto x : v) { cout << x << " "; }
    cout << endl;
}

//
static vector<int> sortTestArr()
{
    int a[] = {3, 5, 7, 9, 2, 3, 1, 0, 7, 5, 4};
    vector<int> v(a, a + 11);
    return v;
}


#pragma mark - 快速排序
// 交换方法
static int quickSortPartition(vector<int> &vi, int low, int up)
{
    // 标记节点
    int pivot = vi[up];
    int i = low - 1;
    for (int j = low; j < up; j++) {
        if (vi[j] <= pivot) {
            i++;
            swap(vi[i], vi[j]);
        }
    }
    swap(vi[i + 1], vi[up]);
    return i + 1;
}

static void quickSort(vector<int> &vi, int low, int up)
{
    if (low < up) {
        int mid = quickSortPartition(vi, low, up);
        quickSort(vi, low, mid - 1);
        quickSort(vi, mid + 1, up);
    }
}

// 通用版本
static void quickSortA(vector<int> &arr, int low, int high)
{
    if (high <= low) return;
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true) {
        /*从左向右找比key大的值*/
        while (arr[++i] < key) {
            if (i == high) {
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j] > key) {
            if (j == low) {
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


#pragma mark - 冒泡排序
static void bubbleSrot(vector<int> &arr)
{
    int i, j, temp;
    for (i = 0; i < arr.size(); i++) {
        for (j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

static void bubbleSrotA(vector<int> &arr)
{
    int i, j, temp;
    for (i = 0; i < arr.size(); i++) {
        for (j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

#pragma mark - 插入排序
static void insertionSort(vector<int> &arr)
{
    int i, j;
    for (i = 1; i < arr.size(); ++i) {
        int value = arr[i];
        j = 0;
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > value) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = value;
    }
}

#pragma mark - 选择排序
static void selectionSort(vector<int> &arr)
{
    int i, j, min;
    for (i = 0; i < arr.size(); i++) {
        min = i;
        for (j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


#pragma mark - 堆排序
static void sinkSortHeap(vector<int> &arr, int index, int length)
{
    int present = index;//要调整的节点下标
    int leftChild = 2 * index + 1;//左子节点下标
    int rightChild = 2 * index + 2;//右子节点下标
    //下沉左边
    if (leftChild < length && arr[leftChild] > arr[present]) {
        present = leftChild;
    }
    
    //下沉右边
    if (rightChild < length && arr[rightChild] > arr[present]) {
        present = rightChild;
    }
    
    //如果下标不相等 证明调换过了
    if (present != index) {
        //交换值
        int temp = arr[index];
        arr[index] = arr[present];
        arr[present] = temp;
        //继续下沉
        sinkSortHeap(arr, present, length);
    }
}

static void buildSortHeap(vector<int> &arr, int length) {
    for (int i = length / 2; i >= 0; i--) {
        sinkSortHeap(arr, i, length);
    }
}

static void heapSort(vector<int> &arr)
{
    int length = (int)arr.size();
    //构建堆
    buildSortHeap(arr, length);
    for (int i = length - 1; i > 0; i-- ) {
        //将堆顶元素与末位元素调换
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        //数组长度-1 隐藏堆尾元素
        length--;
        //将堆顶元素下沉 目的是将最大的元素浮到堆顶来
        sinkSortHeap(arr, 0, length);
    }
}

#pragma mark - Test
static void sortTest()
{
    vector<int> v = sortTestArr();
    quickSortA(v, 0, (int)v.size() - 1);
    printSrotArray(v, "快速排序");
    
    v = sortTestArr();
    bubbleSrotA(v);
    printSrotArray(v, "冒泡排序");
    
    v = sortTestArr();
    insertionSort(v);
    printSrotArray(v, "插入排序");
    
    v = sortTestArr();
    selectionSort(v);
    printSrotArray(v, "选择排序");
    
    v = sortTestArr();
    heapSort(v);
    printSrotArray(v, "堆排序");
}
