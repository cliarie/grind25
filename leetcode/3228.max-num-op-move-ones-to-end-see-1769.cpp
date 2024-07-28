class Solution
{
public:
    int maxOperations(string s)
    {
        // check if last
        int n = s.length();
        vector<int> boxes;
        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            if (s[i] == '1')
                count = 1;
            while (s[i] == '1' && i + 1 < n && s[i] == s[i + 1])
            {
                count++;
                i++;
            }
            if (count)
                boxes.push_back(count);
        }
        if (s[n - 1] == '1')
            boxes.pop_back();

        vector<int> pref(boxes.size() + 1, 0);
        int psum = 0;
        for (int i = 1; i <= boxes.size(); ++i)
        {
            psum += boxes[i - 1]; // num ones on the left
            pref[i] = pref[i - 1] + psum;
        }
        for (auto d : pref)
            cout << d << "d ";
        cout << endl;
        for (auto d : boxes)
            cout << d << " ";
        return pref.back();
    }
};

// shorter, better
int maxOperations(string s)
{
    int res = 0, ones = 0, n = s.size();
    for (int i = 0; i < n; ++i)
    {
        ones += s[i] - '0';
        if (i > 0 && s[i] < s[i - 1])
            res += ones;
    }
    return res;
}