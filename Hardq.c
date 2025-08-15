/* #include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key, num;
    scanf("%d %d", &key, &num);

    // Sort based on difference first, then bigger number first if diff same
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff1 = abs(arr[i] - key);
            int diff2 = abs(arr[j] - key);

            // Sort by smallest difference first
            // If difference equal → bigger number first
            if (diff1 > diff2 || (diff1 == diff2 && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print first num elements
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

*/

#include <stdio.h>
