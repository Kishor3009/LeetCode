class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                vector<int>&v=ans.back();
                int y=v[1];
                if(intervals[i][0]<=y){
                    v[1]=max(y,intervals[i][1]);
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};