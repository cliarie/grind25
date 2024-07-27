#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

bool is_kangaroo(const string &word, const string &synonym)
{
    unordered_map<char, int> counter;
    for (char c : word)
    {
        counter[c]++;
    }
    for (char c : synonym)
    {
        if (counter.find(c) == counter.end())
        {
            return false;
        }
    }
    size_t start = word.find(synonym[0]);
    size_t end = word.rfind(synonym.back());
    if (start == string::npos || end == string::npos)
    {
        return false;
    }
    return !((end - start + 1) == synonym.length());
}

int my_func(vector<string> &words, vector<string> &wordsToSynonyms, vector<string> &wordsToAntonyms)
{
    // Convert to lowercase
    for (auto &word : words)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
    for (auto &pair : wordsToSynonyms)
    {
        transform(pair.begin(), pair.end(), pair.begin(), ::tolower);
    }
    for (auto &pair : wordsToAntonyms)
    {
        transform(pair.begin(), pair.end(), pair.begin(), ::tolower);
    }

    int output = 0;
    unordered_map<string, int> synonym_dict;

    for (const auto &pair : wordsToSynonyms)
    {
        istringstream ss(pair);
        string word, synonyms;
        getline(ss, word, ':');
        getline(ss, synonyms);
        if (find(words.begin(), words.end(), word) != words.end())
        {
            istringstream synonymStream(synonyms);
            string synonym;
            while (getline(synonymStream, synonym, ','))
            {
                if (is_kangaroo(word, synonym))
                {
                    synonym_dict[synonym]++;
                    output++;
                }
            }
        }
    }

    for (const auto &kv : synonym_dict)
    {
        if (kv.second > 1)
        {
            output += (kv.second * (kv.second - 1)) / 2;
        }
    }

    unordered_map<string, int> antonym_dict;

    for (const auto &pair : wordsToAntonyms)
    {
        istringstream ss(pair);
        string word, antonyms;
        getline(ss, word, ':');
        getline(ss, antonyms);
        if (find(words.begin(), words.end(), word) != words.end())
        {
            istringstream antonymStream(antonyms);
            string antonym;
            while (getline(antonymStream, antonym, ','))
            {
                if (is_kangaroo(word, antonym))
                {
                    antonym_dict[antonym]++;
                    output--;
                }
            }
        }
    }

    for (const auto &kv : antonym_dict)
    {
        if (kv.second > 1)
        {
            output += (kv.second * (kv.second - 1)) / 2;
        }
    }

    return output;
}

int main()
{
    vector<string> words = {"illuminated", "animosity", "deoxyribonucleic", "container", "lit", "amity", "encourage", "lighted"};
    vector<string> wordsToSynonyms = {"encourage:urge,boost,inspire", "container:tin,can,bag,bottle", "lighted:lit", "illuminated:lit"};
    vector<string> wordsToAntonyms = {"encourage:discourage", "animosity:amity,like", "lighted:dark"};

    int result = my_func(words, wordsToSynonyms, wordsToAntonyms);
    cout << "Output: " << result << endl;

    return 0;
}
