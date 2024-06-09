#include <iostream>
#include <vector>
using namespace std;

/*
method using binary search
longest_subsequece[i] = smallest element that can be the last element of an increasing subsequence of length i + 1
*/
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> longest_subsequence;

    for (int i = 0; i < n; ++i)
    {
        // it returns position of element in longest_subsequence >= arr[i]
        auto it = lower_bound(longest_subsequence.begin(), longest_subsequence.end(), arr[i]); // uses binary search to find the first (smallest) element in ans array >= arr[i]
        if (it == longest_subsequence.end())
            longest_subsequence.push_back(arr[i]); // arr[i] > all elements in sequence, append to sequence, we have a new longest subsequence
        else
            *it = arr[i]; // replace first greater/equal to element in ans with arr[i]
    }
    for (int i = 0; i < longest_subsequence.size(); ++i)
        cout << longest_subsequence[i] << " ";
    cout << longest_subsequence.size() << endl;
}