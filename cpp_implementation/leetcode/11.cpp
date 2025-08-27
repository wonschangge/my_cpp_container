#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //找最大面积
        //法1.暴力-【超时】
        //设第1个点 (i,height[i]), 第2个点 (j,height[j]), j>i
        //最大面积=(j-i)*(min(height[i], height[j]))
        // int ans = 0;
        // for (int i = 0; i < height.size() - 1; i++) {
        //     for (int j = i + 1; j < height.size(); j++) {
        //         ans = max(ans, (j-i)*(min(height[i], height[j])));
        //     }
        // }
        // return ans;
        //法2.双指针
        // maxArea = min(x,y)*t
        int ans = 0, n = height.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            ans = max(ans,  area);
            if (height[left] <= height[right]) left++;
            else right++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        vector<int> v = {1,8,6,2,5,4,8,3,7};
        cout << s.maxArea(v);
    }
}