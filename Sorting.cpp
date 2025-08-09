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
    arr[mini] = arr[i];
    arr[i] = temp;
  }

  cout << "After selection sort: " << "\n";
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
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;
    selection_sort(arr, n);

    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertion_sort(arr, n);
    
    return 0;
}