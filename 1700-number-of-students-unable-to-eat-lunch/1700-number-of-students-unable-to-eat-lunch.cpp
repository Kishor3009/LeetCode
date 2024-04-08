#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    int countStudents(vector<int>& stu, vector<int>& sand) {
        int c1=0, c0=0;
        for(int x:stu){
            if(x) c1++;
            else c0++;
        }
        for(int x:sand){
            if(x){
                if(c1>0)  c1--;
                else return c0;
            }
            else{
                if(c0>0) c0--;
                else return c1;
            }
        }
        return 0;
    }
};
