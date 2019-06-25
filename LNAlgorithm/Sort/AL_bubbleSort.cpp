//
//  AL_bubbleSort.cpp
//  LNAlgorithm
//
//  Created by vvusu on 6/24/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"


/*
 冒泡排序
 */

static void bubbleSrot(vector<int> &arr)
{
    int i, j, temp;
    for (i = 0; i < arr.size(); i++)
    {
        for (j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
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
    for (i = 0; i < arr.size(); i++)
    {
        for (j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// Test
static void bubbleSrot_test()
{
    int a[] = {3,5,7,9,2,3,1,0,7,5,4};
    vector<int> v(a, a+11);
    bubbleSrotA(v);
    cout<<"冒泡排序:\n";
    for(auto x:v) {
        cout<<x<<" ";
    }
    cout <<endl;
}

