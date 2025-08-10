#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
  // selection sort                             /// selection sort is all about finding minimum and swapping with the elements starting from the start
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;                           /// we find the minimum element and swap with the i element thus we use 2 loops;
      }
    }
    int temp = arr[mini];          /// The swapping part // can also use a function for this..
    arr[mini] = arr[i];                          //// time complexity is always O(n^2) i e n(n+1)/2 
    arr[i] = temp;
  }

  cout << "After using selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}

void bubble_sort(int arr[], int n) {              //// bubble sort is all about swapping adjacent elements till the max is pushed to the end 
    for (int i = n - 1; i >= 0; i--) {
        int swap = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {              // check if the next element is smaller if so switch;
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swap = 1;
            }
        }
        if(!swap) break;                          /// if all the elements are already sorted it only runs for O(n) it is the best case... worst case is O(n^2)
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertion_sort(int arr[], int n) {             ////insertion sort is different from the rest
    for (int i = 0; i < n; i++) {                   //// it actually divides the array for example if n==5  j -->> 1-0, 2-0, 3-0, 4-0, 5-0 like that 
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Before sorting: " << "\n";
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;

    selection_sort(arr, n);

    bubble_sort(arr, n);

    insertion_sort(arr, n);

    return 0;
}