class Solution {
public:
    vector<int>genRows(int row){
        long long ans=1;
        vector<int>rowNum;
        rowNum.push_back(1);
        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            rowNum.push_back(ans);
        }
        return rowNum;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(genRows(i));
        }
        return ans;
    }
};