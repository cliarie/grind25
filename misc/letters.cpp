#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Function to find the string that differs from every string in the array by at most one position
string findDifferingString(const vector<string> &strings)
{
    int n = strings.size();
    int k = strings[0].size();
    vector<char> candidate(k);

    // Step 1: Majority Voting
    for (int i = 0; i < k; ++i)
    {
        unordered_map<char, int> counter;
        for (const string &str : strings)
        {
            counter[str[i]]++;
        }

        // Find the character with the maximum frequency
        char majority_char = strings[0][i];
        int max_count = 0;
        for (const auto &pair : counter)
        {
            if (pair.second > max_count)
            {
                max_count = pair.second;
                majority_char = pair.first;
            }
        }
        candidate[i] = majority_char;
    }

    // Convert vector to string
    string candidate_str(candidate.begin(), candidate.end());

    // Step 2: Verification and Adjustment
    auto isValid = [&](const string &candidate)
    {
        for (const string &str : strings)
        {
            int diff_count = 0;
            for (int i = 0; i < k; ++i)
            {
                if (candidate[i] != str[i])
                {
                    diff_count++;
                    if (diff_count > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    };

    if (isValid(candidate_str))
    {
        return candidate_str;
    }

    // If the candidate is not valid, attempt to adjust
    for (int i = 0; i < k; ++i)
    {
        char original_char = candidate[i];
        for (char c = 'a'; c <= 'z'; ++c)
        {
            if (c != original_char)
            {
                candidate[i] = c;
                candidate_str = string(candidate.begin(), candidate.end());
                if (isValid(candidate_str))
                {
                    return candidate_str;
                }
            }
        }
        candidate[i] = original_char; // Revert change
    }

    // Fallback to the initial candidate
    return "";
}

// Test cases
int main()
{
    vector<string> test1 = {"bay", "zaz", "bab"};
    vector<string> test2 = {"aya", "aba", "abb", "zba"};

    cout << "Result for test1: " << findDifferingString(test1) << endl; // Output: "baz"
    cout << "Result for test2: " << findDifferingString(test2) << endl; // Output: "aba"

    return 0;
}
