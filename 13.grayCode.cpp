#include <bits/stdc++.h>
using namespace std;


vector<string> grayCodes(int n) {
    if(n == 0) return {""};
    if(n == 1) return {"0", "1"};
    vector<string> tempAns = grayCodes(n-1);
    vector<string> ans;
    ans.reserve(1<<n);
    for(int i = 0; i < tempAns.size(); i++) {
        ans.push_back("0" + (tempAns[i]));
    }
    for(int i = tempAns.size() - 1; i >= 0 ; i--) {
        ans.push_back("1" + (tempAns[i]));
    }
    return ans;
}

vector<string> grayCodesBitManipulation(int n) {
    //Total no of codes
    vector<string> ans;
    int totalCodes = (1 << n);
    for(int i = 0; i < totalCodes; i++) {
        int grayI = i ^ (i >> 1);
        bitset<32> grayCodeI(grayI);
        string grayCodeIString = grayCodeI.to_string().substr(32-n);
        ans.push_back(grayCodeIString);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> result = grayCodesBitManipulation(n);
    // vector<string> result = grayCodes(n);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}