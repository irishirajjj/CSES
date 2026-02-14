#include <bits/stdc++.h>
using namespace std;

void printStrings(vector<int>& v, string& s, int len) {
    if (s.length() == len) {
        cout << s << '\n';
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (v[i] > 0) {
            v[i]--;
            s.push_back('a' + i);
            printStrings(v, s, len);
            s.pop_back();
            v[i]++;
        }
    }
}

void creatingStrings(string& s) {
    int n = s.length();
    vector<int> frequencyArray (26,0);
    int totalCount = 1;
    for(int i = 0; i < n; i++) {
        frequencyArray[s[i] - 'a']++;
        totalCount *= (i+1);
    }
    for(int i = 0; i < 26; i++) {
        int curr = frequencyArray[i];
        while(curr > 1) {
            totalCount /= curr;
            curr--;
        }
    }
    cout << totalCount << endl;
    string ss = "";
    printStrings(frequencyArray, ss, n);
    
}

void createStringsNextPermuation(string& s) {
    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << ans.size() << endl;
    for(auto& str : ans) {
        cout << str << endl;
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    // createStringsNextPermuation(s);
    creatingStrings(s);

    return 0;
}