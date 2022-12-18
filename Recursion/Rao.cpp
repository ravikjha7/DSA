#include <bits/stdc++.h>
using namespace std;

class Solution{

    void findCombinations(vector<int> candidates, int target, int ind, vector<int> &curr, vector<vector<int>> &res){
        if(ind == candidates.size()){
            if(!target) res.push_back(curr);
        
            return;
        }

        // Picking/Choosing the current element
        if(candidates[ind] <= target){
            curr.push_back(candidates[ind]);

            findCombinations(candidates, target - candidates[ind], ind + 1, curr, res);
        
            curr.pop_back();
        }

        // Not picking/Choosing the current element
        findCombinations(candidates, target, ind + 1, curr, res);

        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
        vector<vector<int>> res;
        vector<int> curr;

        findCombinations(candidates, target, 0, curr, res);

        return res;
    }
};