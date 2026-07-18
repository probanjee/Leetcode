class Solution {
private:
void solve(vector<int>& candidates, vector<int>& output, int index, int target, vector<vector<int>>& ans ){
    //base casse
    if(target==0){
        ans.push_back(output);
        return ;
    }
    if(target<0) return;
    
    for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]) continue;     //skip duplicates
        if(candidates[i]>target) break; //if element is greater than target cannot sum upto target
        
        output.push_back(candidates[i]);
        solve(candidates, output, i+1,target-candidates[i],ans);
        output.pop_back();
        
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        int index=0;
        vector<int> output;
        solve(candidates, output, index, target, ans);
        return ans;
    }
};