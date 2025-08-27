#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {0,1,0,3,12};
        s->moveZeroes(input);
        for(auto i:input) cout<<i<<endl;

        assert(input[0] == 1);
        assert(input[1] == 3);
        assert(input[2] == 12);
        assert(input[3] == 0);
        assert(input[4] == 0);
    }
    {
        vector<int> input = {0};
        s->moveZeroes(input);
        assert(input[0] == 0);
    }
}