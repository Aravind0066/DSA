#include <bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, currSum = 0;
    int start = 0, end = -1, ansSt = -1;
    for(int i=0; i<nums.size(); i++){
        currSum += nums[i];
        if(maxSum < currSum){
            maxSum = currSum;
            ansSt = start;
            end = i;
        }

        if(currSum < 0){
            currSum = 0;
            start = i+1;
        }
    }
    cout << maxSum << endl;
    for(int i=ansSt; i<=end; i++){
        cout << nums[i] << " ";
    }
}

int main(){
    vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
    maxSubArray(n);
    return 0;
}
