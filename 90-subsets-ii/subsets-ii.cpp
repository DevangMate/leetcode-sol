class Solution {
public:
void findpowset(int index,vector<int>& ds,vector<vector<int>>& ans,vector<int>& arr){
 if(index==arr.size()){
    ans.push_back(ds);
    return;
 }

 if(ds.empty() || ds.back()!=arr[index]){
    findpowset(index+1,ds,ans,arr);
    
 }
 ds.push_back(arr[index]);
 findpowset(index+1,ds,ans,arr);
 ds.pop_back();
 
 

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(),nums.end());
    findpowset(0,ds,ans,nums);
    return ans;
    }
};