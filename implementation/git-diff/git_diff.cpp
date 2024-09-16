#include <iostream>
#include <vector>
#include <unordered_set>
#include <deque>
using namespace std;

vector<string> part1(const vector<string> &a, const vector<string> &b){
    unordered_set<string> setb(b.begin(), b.end());
    vector<string> res;
    for (auto &s : a){
        if (setb.find(s) != setb.end()) res.push_back(s);
    }
    return res;
}

tuple<vector<string>, vector<string>, vector<string>, vector<string>> part2(const vector<string> &a, const vector<string> &b){
    int prefixl = 0, suffixl = 0;

    while (prefixl < a.size() && prefixl < b.size() && a[prefixl] == b[prefixl]) prefixl++;
    while (suffixl < (a.size() - prefixl) && suffixl < (b.size() - prefixl) && a[a.size() - 1 - suffixl] == b[b.size() - 1 - suffixl]) suffixl++;

    vector<string> prefix(a.begin(), a.begin() + prefixl);

    vector<string> suffix, mid1, mid2;
    if (suffixl > 0) suffix = vector<string>(a.end() - suffixl, a.end());

    if (a.size() > suffixl) mid1 = vector<string>(a.begin() + prefixl, a.end() - suffixl);
    else mid1 = vector<string>(a.begin() + prefixl, a.end());

    if (b.size() > suffixl) mid2 = vector<string>(b.begin() + prefixl, b.end() - suffixl);
    else mid2 = vector<string>(b.begin() + prefixl, b.end());

    return {prefix, suffix, mid1, mid2};

}

string recursiveDiff(const vector<string> &a, const vector<string> &b){
    if (a.empty() && b.empty()) return "";

    if (a.empty()){
        string res = "";
        for (auto &s : b) res += "+ " + s + "\n";
        return res;
    }

    if (b.empty()){
        string res = "";
        for (auto &s : a) res += "- " + s + "\n";
        return res;
    }

    auto [prefix, suffix, ra, rb] = part2(a, b);
    string res = "";

    for (auto &s : prefix) res += " " + s + "\n";

    vector<string> common = part1(ra, rb);
    if (!common.empty()){
        int preva = 0, prevb = 0;
        for (auto &c : common){
            auto posa = find(ra.begin() + preva, ra.end(), c);
            auto posb = find(rb.begin() + prevb, rb.end(), c);

            vector<string> suba(ra.begin() + preva, posa);
            vector<string> subb(rb.begin() + prevb, posb);
            res += recursiveDiff(suba, subb);
            res += " " + c + "\n";
            preva = posa - ra.begin() + 1;
            prevb = posb - rb.begin() + 1;
        }
        vector<string> suba(ra.begin() + preva, ra.end());
        vector<string> subb(rb.begin() + prevb, rb.end());
        res += recursiveDiff(suba, subb);
    }
    else{
        vector<string> t;
        res += recursiveDiff(ra, t);
        res += recursiveDiff(t, rb);
    }

    for (auto &s : suffix) res += " " + s + "\n";

    return res;
}

void part3(const vector<string>&a, const vector<string>&b){
    cout << recursiveDiff(a, b);
}

int main(){
    vector<string> a = {"a", "b", "c", "f", "d", "e"};
    vector<string> b = {"a", "b", "w", "f", "e"};
    vector<string> res = part1(a, b);
    for (auto &s : res) cout << s << " ";
    cout << endl;
    auto [p, suf, ra, rb] = part2(a, b);
    for (auto &s : p) cout << s << " ";
    cout << endl;
    for (auto &s : suf) cout << s << " ";
    cout << endl;
    for (auto &s : ra) cout << s << " ";
    cout << endl;
    for (auto &s : rb) cout << s << " ";
    cout << "END " << endl;

    part3(a, b);


}
