#include <vector>
#include <unordered_set>
#include <fstream>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'authEvents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY events as parameter.
 */
const int MOD = 1e9 + 7;
const int P = 131;

long long fhash(string &s){
    long long ans = 0;
    long long mul = 1;
    for (int i = s.size() - 1; i >= 0; --i){
        ans = (ans + (s[i]) * mul) % MOD;
        mul = (mul * P) % MOD;
    }
    // cout << s << " " << ans << endl;
    return ans;
}

string curpass = "";
vector<int> authEvents(vector<vector<string>> events) {
    vector<int> ans;
    unordered_set<long long> valid;

    for (auto &event : events){
        if (event[0] == "setPassword"){
            curpass = event[1];
            valid.clear();
            valid.insert(fhash(event[1]));
            // modified;
            for (char c = 'a'; c <= 'z'; ++c){
                string n = event[1] + c;
                valid.insert(fhash(n));
            }
            for (char c = 'A'; c <= 'Z'; ++c){
                string n = event[1] + c;
                valid.insert(fhash(n));
            }
            for (char c = '0'; c <= '9'; ++c){
                string n = event[1] + c;
                valid.insert(fhash(n));
            }
        }
        else{
            long long h = stoll(event[1]);
            // for (auto d : valid) cout << d << " ";
            // cout << endl;
            if (valid.count(h)) ans.push_back(1);
            else ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string events_rows_temp;
    getline(cin, events_rows_temp);

    int events_rows = stoi(ltrim(rtrim(events_rows_temp)));

    string events_columns_temp;
    getline(cin, events_columns_temp);

    int events_columns = stoi(ltrim(rtrim(events_columns_temp)));

    vector<vector<string>> events(events_rows);

    for (int i = 0; i < events_rows; i++) {
        events[i].resize(events_columns);

        string events_row_temp_temp;
        getline(cin, events_row_temp_temp);

        vector<string> events_row_temp = split(rtrim(events_row_temp_temp));

        for (int j = 0; j < events_columns; j++) {
            string events_row_item = events_row_temp[j];

            events[i][j] = events_row_item;
        }
    }

    vector<int> result = authEvents(events);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
