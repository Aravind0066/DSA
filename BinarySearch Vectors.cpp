#include <bits/stdc++.h>
using namespace std;

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
    cout << index << endl;

    return 0;
}
