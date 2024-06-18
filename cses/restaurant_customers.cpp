#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> start(n, 0);
    vector<int> end(n, 0);
    for (int i = 0; i < n; ++i){
        cin >> start[i] >> end[i];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int a, b, count, maxcount;
    while (a < n && b < n){
        if (start[a] < end[b]){
            count++;
            a++;
        }
        else{
            count--;
            b++;
        }
        maxcount = max(count, maxcount);
    }
    cout << maxcount << endl;
}
