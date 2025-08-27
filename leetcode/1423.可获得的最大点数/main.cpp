#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
    }
};

int main() {
    Solution* s = new Solution();
    {
        vector<int> input = {1,2,3,4,5,6,1};
        assert(s->maxScore(input, 3) == 12);
    }
    {
        vector<int> input = {2,2,2};
        assert(s->maxScore(input, 2) == 4);
    }
    {
        vector<int> input = {9,7,7,9,7,7,9};
        assert(s->maxScore(input, 7) == 55);
    }
    {
        vector<int> input = {1,1000,1};
        assert(s->maxScore(input, 1)  == 1);
    }
    {
        vector<int> input = {1,79,80,1,1,1,200,1};
        assert(s->maxScore(input, 3) == 202);
    }
}