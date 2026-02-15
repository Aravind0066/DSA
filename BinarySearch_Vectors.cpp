#include <bits/stdc++.h>
using namespace std;

int lowerbound(const vector<int>& arr, int t){
    int ans = -1, low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= t) {
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int upperbound(const vector<int>& arr, int t){
    int ans = -1, low = 0, high = arr.size() - 1;
     while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > t) {
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int search(const vector<int>& arr, int t) {
    int low = 0, high = arr.size() - 1, mid;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (t == arr[mid]) return mid;
        if (t > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1; // Element not found
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int index = search(arr, target);
    int lb = lowerbound(arr, target);
    int ub = upperbound(arr, target);
    int default_lb = lower_bound(arr.begin(),arr.end(),target) - arr.begin();
    int default_ub = upper_bound(arr.begin(),arr.end(),target) - arr.begin();
    cout << index << endl;
    cout << "lb = "<< lb <<"  ub = " << ub << endl;
    cout << "lb = "<< default_lb <<"  ub = " << default_ub << endl;
    return 0;
}


/// the floor is the lower bound and the ceil is the upper bound if the element is not found  
/// if the element is found then floor and ceil both are the target element

/// searching the index is similar to finding the lowerbound. 
/// 