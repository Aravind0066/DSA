#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

void explain_pair()
{
    // Time Complexity: O(1) for all operations
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second;

    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second;
}

void explain_vector()
{
    // No fixed size like array. Dynamic in nature.
    // push_back: Amortized O(1), worst case O(n) when resizing
    // emplace_back: Amortized O(1), slightly faster than push_back
    // Access: O(1)
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // This is faster than push_back

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2); // Here curly braces not required

    vector<int> v0(5, 100); // [100, 100, 100, 100, 100] - O(n) construction
    vector<int> v00(5);     // Container of size 5 with zero or garbage value - O(n) construction

    vector<int> v1(5, 20);
    vector<int> v2(v1); // Copies v1 - O(n) copy constructor
}

void explain_iterator()
{
    // Iterator operations: O(1) for random access iterators
    vector<int> v(5, 20);

    vector<int>::iterator it1 = v.begin(); // Like a pointer pointing to 0th index
    it1++;
    cout << *it1; // Prints 1st index;

    vector<int>::iterator it2 = v.end();            // Points to the memory location right next to the last element
    vector<int>::reverse_iterator it3 = v.rbegin(); // Reverse begin. Points to the memory location of the last element.
    it3++;                                          // Points to last before element.
    vector<int>::reverse_iterator it4 = v.rend();   // Reverse end. Points to the memory location just before the first element.
    it4--;                                          // Points to first element.

    cout << v[0] << " " << v.at(0); // Both O(1), at() does bounds checking
    cout << v.back() << " "; // O(1)

    // Iteration: O(n) overall
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
}

void explain_auto()
{
    // auto keyword deduces type automatically - O(1) type deduction at compile time
    vector<int> v = {1, 2, 3, 4, 5};
    // Iterator-based loop: O(n)
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    // Range-based for loop: O(n)
    for (auto it : v) // Here it is int
    {
        cout << it << " ";
    }
}

void explain_other_vector_functions()
{
    vector<int> v = {10, 20, 12, 23};
    // {10, 20, 12, 23}
    v.erase(v.begin() + 1); // {10, 12, 23} - O(n) due to shifting elements
    // {10, 20, 12, 23, 35}
    v.erase(v.begin() + 2, v.begin() + 4); // {10, 20, 35} v.begin(4) is not removed - O(n)

    // Insert function
    vector<int> v2(2, 100);          // {100, 100}
    v2.insert(v2.begin(), 300);       // {300, 100, 100} - O(n) due to shifting
    v2.insert(v2.begin() + 1, 2, 10); // {300, 10, 10, 100, 100} - O(n)
    vector<int> copy(2, 50);        // {50, 50}
    v2.insert(v2.begin(), copy.begin(), copy.end()); // O(n + m) where m is size of range
    // {50, 50, 300, 10, 10, 100, 100}

    // {10, 20}
    cout << v2.size(); // O(1)

    // {10, 20}
    v2.pop_back(); // {10} - O(1)

    vector<int> v1 = {10, 20};
    vector<int> v3 = {30, 40};
    // v1 -> {10, 20}
    // v3 -> {30, 40}
    v1.swap(v3); // v1 -> {30, 40}, v3 -> {10, 20} - O(1)

    v2.clear();         // Erases the entire vector - O(n) due to destructor calls
    cout << v2.empty(); // Prints true if v has 0 elements and false for other cases - O(1)
}

void explain_list()
{
    // Doubly linked list - no random access
    // push/pop operations: O(1)
    // insert/erase at known position: O(1)
    // search: O(n)
    list<int> ls;

    ls.push_back(2);     // {2} - O(1)
    ls.emplace_back(4);  // {2, 4} - O(1)
    ls.push_front(5);    // {5, 2, 4} // Much faster than insert - O(1)
    ls.emplace_front(6); // {6, 5, 2, 4} - O(1)

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
    // Note: insert/erase at iterator position is O(1), unlike vector's O(n)
}

void explainDeque()
{
    // Double-ended queue - allows efficient insertion/deletion at both ends
    // push/pop front/back: O(1)
    // random access: O(1)
    // insert/erase in middle: O(n)
    deque<int> dq;
    dq.push_back(1);     // {1} - O(1)
    dq.emplace_back(2);  // {1, 2} - O(1)
    dq.push_front(4);    // {4, 1, 2} - O(1)
    dq.emplace_front(3); // {3, 4, 1, 2} - O(1)

    dq.pop_back();  // {3, 4, 1} - O(1)
    dq.pop_front(); // {4, 1} - O(1)

    dq.back();  // O(1)
    dq.front(); // O(1)

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainStack() // TC = Big Oh(1)
{
    // LIFO (Last In First Out) container adapter
    // All operations: O(1)
    stack<int> st;
    st.push(1);    // {1} - O(1)
    st.push(2);    // {2, 1} - O(1)
    st.push(3);    // {3, 2, 1} - O(1)
    st.push(3);    // {3, 3, 2, 1} - O(1)
    st.emplace(5); // {5, 3, 3, 2, 1} - O(1)

    cout << st.top(); // prints 5   "** st[2] is invalid **" - O(1)
    st.pop();         // st looks like {3, 3, 2, 1} - O(1)

    cout << st.top();  // 3 - O(1)
    cout << st.size(); // 4 - O(1)
    cout << st.empty(); // O(1)
    stack<int> st1, st2;
    st1.swap(st2); // O(1)
}

void explainQueue()
{
    // FIFO (First In First Out) container adapter
    // All operations: O(1)
    queue<int> q;
    q.push(1);    // {1} - O(1)
    q.push(2);    // {1, 2} - O(1)
    q.emplace(4); // {1, 2, 4} - O(1)

    q.back() += 5; // O(1)

    cout << q.back(); // prints 9 - O(1)

    // Q is {1, 2, 9}
    cout << q.front(); // prints 1 - O(1)

    q.pop(); // {2, 9} - O(1)

    cout << q.front(); // prints 2 - O(1)

    // size, swap, empty same as stack - all O(1)
}

// Function to explain Priority Queue (Max Heap & Min Heap) in C++
void explainPQ()
{
    // Binary heap implementation
    // push: O(log n)
    // pop: O(log n)
    // top: O(1)
    
    // Max Heap (Default behavior of priority_queue in C++)
    priority_queue<int> pq;

    pq.push(5);     // Insert 5 → pq = {5} - O(log n)
    pq.push(2);     // Insert 2 → pq = {5, 2} - O(log n)
    pq.push(8);     // Insert 8 → pq = {8, 5, 2} (8 is the highest) - O(log n)
    pq.emplace(10); // Insert 10 → pq = {10, 8, 5, 2} - O(log n)

    cout << pq.top(); // prints 10 → Top returns the largest element - O(1)

    pq.pop(); // removes 10 → pq = {8, 5, 2} - O(log n)

    cout << pq.top(); // prints 8 → Now the largest is 8 - O(1)

    // Notes: functions like size(), swap(), empty() also work similarly
    // size(), empty(): O(1)

    // Min Heap version using custom comparator (greater<int>)
    priority_queue<int, vector<int>, greater<int>> pq_min;

    pq_min.push(5);     // pq = {5} - O(log n)
    pq_min.push(2);     // pq = {2, 5} - O(log n)
    pq_min.push(8);     // pq = {2, 5, 8} - O(log n)
    pq_min.emplace(10); // pq = {2, 5, 8, 10} - O(log n)

    cout << pq_min.top(); // prints 2 → In Min Heap, smallest element is on top - O(1)
}

void explainSet()
{
    // Balanced Binary Search Tree (usually Red-Black Tree)
    // insert, erase, find: O(log n)
    // Stores elements in sorted order, no duplicates
    set<int> st;
    st.insert(1);  // {1} - O(log n)
    st.emplace(2); // {1, 2} - O(log n)
    st.insert(2);  // {1, 2} - O(log n), duplicate ignored
    st.insert(4);  // {1, 2, 4} - O(log n)
    st.insert(3);  // {1, 2, 3, 4} - O(log n)

    // Functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    // begin(), end(), rbegin(), rend(), size(),
    // empty() and swap() are same as those of above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3); // O(log n) - returns iterator if found, st.end() if not found

    // {1, 2, 3, 4, 5}
    auto it2 = st.find(6); // O(log n) - returns st.end() since 6 not present

    // {1, 4, 5}
    st.erase(5); // erases 5 // takes logarithmic time - O(log n)

    int cnt = st.count(1); // O(log n) - returns 0 or 1 for set (0 or more for multiset)

    auto it3 = st.find(3);
    st.erase(it3); // it takes constant time - O(1) when erasing by iterator

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it4 = st.find(4);
    st.erase(it1, it4); // after erase → {1, 4, 5}  → [first, last) - O(k + log n) where k is number of elements

    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does.

    // This is the syntax
    auto it5 = st.lower_bound(2); // O(log n) - first element >= 2

    auto it6 = st.upper_bound(3); // O(log n) - first element > 3
}

void explainMultiSet() {
    // Everything is same as set
    // Only difference: multiset allows duplicate elements
    // Same time complexities as set
    
    multiset<int> ms;
    ms.insert(1);        // {1} - O(log n)
    ms.insert(1);        // {1, 1} - O(log n)
    ms.insert(1);        // {1, 1, 1} - O(log n)

    ms.erase(1);         // All 1's erased - O(log n + k) where k is count of element

    int cnt = ms.count(1); // Count how many times 1 is present - O(log n)

    // Only a single 1 is erased
    ms.erase(ms.find(1)); // O(log n) for find + O(1) for erase by iterator

    // Erase a range of two 1's
    auto it1 = ms.find(1);
    auto it2 = it1;
    advance(it2, 2);     // Move iterator 2 steps forward - O(k) where k is distance
    ms.erase(it1, it2);  // Removes two 1's in range [it1, it2) - O(k) where k is elements in range

    // Rest of the functions (size, empty, swap, etc.) are same as set
}

void explainUSet() {
    // Hash table implementation
    // Average case: insert, erase, find: O(1)
    // Worst case: O(n) when many hash collisions occur
    unordered_set<int> st;

    // lower_bound and upper_bound functions DO NOT work
    // Rest of the functions like insert, erase, find, size etc. are SAME as set

    // Unlike set, it does NOT store elements in any particular order
    // So you can't expect sorted output from it

    // Time complexity is on average O(1) for insert, erase, find (better than set)
    // But in worst-case (when hash collisions happen), it can degrade to O(n)
    
    st.insert(1);    // Average O(1), Worst O(n)
    st.erase(1);     // Average O(1), Worst O(n)
    st.find(1);      // Average O(1), Worst O(n)
    st.count(1);     // Average O(1), Worst O(n)
    st.size();       // O(1)
    st.empty();      // O(1)
}


void explainMap() {
    // Define different types of maps:
    map<int, int> mpp;                                // Maps int to int
    map<int, pair<int, int>> mpp2;                    // Maps int to pair<int, int>
    map<pair<int, int>, int> mpp3;                    // Maps a pair<int, int> to an int

    // Inserting elements
    mpp[1] = 2;                                        // Insert using indexing
    mpp.emplace(3, 1);                                 // Insert using emplace (more efficient than insert)
    mpp.insert({2, 4});                                // Insert using insert function
    mpp3[{2, 3}] = 10;                                  // For mpp3: insert into map with pair as key

    // Iterate over the map and print all key-value pairs
    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;  // Output format: key value
    }

    // Access values using indexing
    cout << mpp[1];                                    // Outputs 2 (value for key 1)
    cout << mpp[5];                                    // Key 5 doesn't exist, default initializes to 0

    // Using find to get iterator to key 3
    auto it = mpp.find(3);                             // Returns iterator to pair where key == 3
    cout << it->second;                              // Print value at that iterator (value for key 3)

    // Find key 5 using find (safer than mpp[5] as it won’t insert if key doesn’t exist)
    auto it2 = mpp.find(5);                            // Returns end() if key not found

    // Lower and upper bound functions (for ordered maps)
    auto it3 = mpp.lower_bound(2);                     // Returns iterator to first element with key >= 2
    auto it4 = mpp.upper_bound(3);                     // Returns iterator to first element with key > 3

    // Other useful functions (not shown here): erase, swap, size, empty
}


int main()
{
    return 0;
}