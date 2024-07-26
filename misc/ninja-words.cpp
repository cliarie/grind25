#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    getline(cin, s);
    cout << s << endl;
    int n;
    cin >> n;
    vector<string> arr(n);
    for (auto &a : arr)
        cin >> a;
    cout << s.length() << endl;
    // peak 6 ninja words
    int points = 0;
    for (auto &word : arr)
    {
        // move sliding window of size word.size() + 1 over s, count spaces, astericks, and matches
        int tpoints = 0;
        int ast = 0, match = 0; // at most 1 space, any asterick, rest are matches
        for (int i = 0; i < s.length() - (word.length()); ++i)
        {
            if (s[i] == ' ')
                continue;
            int widx = 0;
            for (int space = 1; space < word.length(); space++)
            { // assume space position
                ast = 0, match = 0, widx = 0;
                for (int j = 0; j < word.length() + 1; ++j)
                {
                    // cout << s[i + j] << " " << word[widx] << endl;
                    // cout << word << " i" << space << " " << i << " " << widx << endl;
                    if (j == space)
                    {
                        if (s[i + j] == '*')
                            ast++;
                        else if (s[i + j] != ' ')
                            break;
                        continue;
                    }
                    if (tolower(s[i + j]) == tolower(word[widx]) || s[i + j] == '*')
                    {
                        if (s[i + j] == '*')
                            ast++;
                        match++;
                        widx++;
                    }
                    else
                        break;
                }
                // cout << match << " " << ast << " " << widx << endl;
                if (match == word.length())
                {
                    tpoints = max(tpoints, 1 + ast);
                    // cout << word << " " << 1 + ast << endl;
                    break;
                }
            }
        }
        points += tpoints;
    }
    cout << points << endl;
}
