//
//  AL_TwoSum.cpp
//  LNDemo
//
//  Created by vvusu on 6/18/19.
//  Copyright © 2019 vvusu. All rights reserved.
//

#include "Algorithm.hpp"
// unordered_map(无序映射)

using namespace std;

/*
 两数之和
 
 描述：
    给定一个整数数列，找出其中和为特定值的那两个数。
    你可以假设每个输入都只会有一种答案，同样的元素不能被重用。
 
 示例：
    给定 nums = [2, 7, 11, 15], target = 9
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]
 
 解题思路:
    最简单粗暴的办法就是多次循环遍历数列进行求解，时间复杂度为O(n^2)，这应该不是本题的本意，所以应该换个思路，考虑一个更高效的算法。
    我们可以考虑现成的关联容器map，map通过二叉搜索树实现，效率较高，其中的函数count可以得知某个键是否在map中，而本题的关键是求解某个值在数列中的位置，
    所以可以把数列中的元素作为map的键，元素对应的索引作为map的值，在一次数列遍历中通过map辅助求解。另外，map会根据key进行排序，而unordered_map则不会，
    unordered_map对于查找问题速度更快，本题中使用unordered_map（hash map）
*/

static vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        // m 是否包含 target - nums[i]
        if (m.count(target - nums[i]))
        {
            return {i, m[target - nums[i]]};
        }
        m[nums[i]] = i;
    }
    return {};
}


static void twoSum_test()
{
    vector<int> nums;
    vector<int> result;
    nums = {1, 2, 7, 11, 15};
    result = twoSum(nums, 9);
    if (result.size() >= 2)
    {
        cout <<"两数之和:\n" <<result[0] <<"," <<result[1] <<endl;
    }
    else
    {
        cout <<"无结果" <<endl;
    }
}
