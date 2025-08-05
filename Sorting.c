#include <stdio.h>
#include <limits.h>
#define MAXN 1000
#define COUNT_MAX_RANGE 1000  // max allowed range size for counting sort (increase if needed)

/* ================= BUBBLE SORT ================= */
// bubble sort: swap adjacent elements, big ones bubble to end

/* --------------- Bubble Sort Notes ---------------
Think of it like a club line: big guys get pushed to the back one step at a time
Keep swapping neighbors until no one’s out of place
Best: Already sorted → O(n)
Worst: Totally messed up → O(n²)
Stable: Yes
---------------------------------------------------*/

void bubble_sort(int arr[], int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){ int t=arr[j]; arr[j]=arr[j+1]; arr[j+1]=t; } // swap
        }
    }
}

/* ================= INSERTION SORT ================= */
// insertion sort: build sorted prefix by inserting current into proper place
/* --------------- Insertion Sort Notes ---------------
Builds a neat lineup by sliding new people into their spot
Sorts one more element on each loop, like adding cards into a hand
Best: Almost sorted lists fly by in O(n)
Worst: Full chaos → O(n²)
Stable: Yes
------------------------------------------------------*/

void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){ int t=arr[j-1]; arr[j-1]=arr[j]; arr[j]=t; j--; } // shift
    }
}

/* ================= SELECTION SORT ================= */
// selection sort: pick minimum from unsorted and swap to front
/* --------------- Selection Sort Notes ---------------
The picky one — hunts down the smallest kid and sticks them at the start
Doesn’t care about order until they’ve picked all winners
Always O(n²), even if already sorted
Stable: No
------------------------------------------------------*/

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++) if(arr[j]<arr[mini]) mini=j; // find min
        if(mini!=i){ int t=arr[i]; arr[i]=arr[mini]; arr[mini]=t; } // swap
    }
}


/* ================= COUNTING SORT ================= */
// counting sort: counts occurrences then rebuilds array (static count array)
// NOTE: values must fit in range [min .. min+COUNT_MAX_RANGE-1]
/* --------------- Counting Sort Notes ---------------
Counts how many of each number you’ve got
Then spits them out in order, no swapping drama
O(n + range), super fast if numbers aren’t too spread out
Needs extra memory for counts
Stable: Yes (if done right)
------------------------------------------------------*/

void counting_sort(int arr[], int n){
    if(n==0) return;
    int mn=arr[0], mx=arr[0];
    for(int i=1;i<n;i++){ if(arr[i]<mn) mn=arr[i]; if(arr[i]>mx) mx=arr[i]; }
    int range = mx - mn + 1;
    if(range > COUNT_MAX_RANGE){ /* range too big for static buffer */ return; }
    static int cnt[COUNT_MAX_RANGE]; for(int i=0;i<range;i++) cnt[i]=0; // reset counts
    for(int i=0;i<n;i++) cnt[arr[i]-mn]++; // count
    int idx=0;
    for(int v=0; v<range; v++){
        while(cnt[v]-- > 0) arr[idx++]=v+mn; // write back sorted
    }
}

/* ================= MERGE SORT ================= */
// merge sort: divide & conquer, uses static temp buffer
/* --------------- Merge Sort Notes ---------------
Splits the squad in half, sorts each side, then merges back in order
Consistent O(n log n) — cool under pressure
Needs extra array space for merging
Stable: Yes
---------------------------------------------------*/

static int merge_tmp[MAXN];
void merge(int arr[], int l, int m, int r){
    int i=l, j=m+1, k=l;
    while(i<=m && j<=r){
        if(arr[i] <= arr[j]) merge_tmp[k++] = arr[i++]; else merge_tmp[k++] = arr[j++];
    }
    while(i<=m) merge_tmp[k++]=arr[i++]; while(j<=r) merge_tmp[k++]=arr[j++];
    for(i=l;i<=r;i++) arr[i]=merge_tmp[i]; // copy back
}
void merge_sort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

/* ================= QUICK SORT ================= */
// quick sort: partition around pivot (last element), then recurse

/* --------------- Quick Sort Notes ---------------
Picks a pivot, sends smaller numbers left, bigger ones right
Sorts each side like a boss — in-place, usually fastest
Best/Average: O(n log n)
Worst: O(n²) if bad pivots picked
Stable: No
---------------------------------------------------*/

int partition(int arr[], int low, int high){
    int pivot = arr[high]; int i = low - 1;
    for(int j=low;j<high;j++){
        if(arr[j] <= pivot){ i++; int t=arr[i]; arr[i]=arr[j]; arr[j]=t; }
    }
    int t=arr[i+1]; arr[i+1]=arr[high]; arr[high]=t;
    return i+1;
}
void quick_sort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

void printArray(int arr[], int n){ for(int i=0;i<n;i++){ printf("%d",arr[i]); if(i+1<n) printf(" "); } printf("\n"); }

int main(){
    int a1[] = {13,46,24,52,20,9}; int n1 = sizeof(a1)/sizeof(a1[0]);
    printf("Before bubble: "); printArray(a1,n1);
    bubble_sort(a1,n1);
    printf("After bubble:  "); printArray(a1,n1);

    int a2[] = {13,46,24,52,20,9}; int n2 = sizeof(a2)/sizeof(a2[0]);
    printf("\nBefore insertion: "); printArray(a2,n2);
    insertion_sort(a2,n2);
    printf("After insertion:  "); printArray(a2,n2);

    int a3[] = {13,46,24,52,20,9}; int n3 = sizeof(a3)/sizeof(a3[0]);
    printf("\nBefore selection: "); printArray(a3,n3);
    selection_sort(a3,n3);
    printf("After selection:  "); printArray(a3,n3);

    int a4[] = {4,2,2,8,3,3,1}; int n4 = sizeof(a4)/sizeof(a4[0]);
    printf("\nBefore counting: "); printArray(a4,n4);
    counting_sort(a4,n4); // range must be <= COUNT_MAX_RANGE
    printf("After counting:  "); printArray(a4,n4);

    int a5[] = {38,27,43,3,9,82,10}; int n5 = sizeof(a5)/sizeof(a5[0]);
    printf("\nBefore merge: "); printArray(a5,n5);
    merge_sort(a5,0,n5-1);
    printf("After merge:  "); printArray(a5,n5);

    int a6[] = {10,7,8,9,1,5}; int n6 = sizeof(a6)/sizeof(a6[0]);
    printf("\nBefore quick: "); printArray(a6,n6);
    quick_sort(a6,0,n6-1);
    printf("After quick:  "); printArray(a6,n6);

    return 0;
}
