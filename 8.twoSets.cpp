#include <bits/stdc++.h>
using namespace std;

void twoSetsByMaths(int n) {
    if(n % 4 == 1 || n % 4 == 2){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<int> v1, v2;
    if(n % 4 == 0) {
        v1.push_back(1);
        int i = 2;
        while(i <= n) {
            if(i <= n) v2.push_back(i);i++;
            if(i <= n) v2.push_back(i);i++;
            if(i <= n) v1.push_back(i);i++;
            if(i <= n) v1.push_back(i);i++;
        }
    }
    else {
        v1.push_back(1);
        int i = 2;
        if(n % 8 == 3) {
            while(i <= n) {
                if(i <= n) { 
                    if(i==(n+1)/2) {
                        v1.push_back(i);
                    }
                    else v2.push_back(i);
                    i++;
                }
                if(i <= n) {
                    if(i==(n+1)/2) {
                        v1.push_back(i);
                    }
                    else v2.push_back(i);
                    i++;
                }
                if(i <= n) v1.push_back(i);i++;
                if(i <= n) v1.push_back(i);i++;
            }
        }
        else if(n % 8 == 7) {
            while(i <= n) {
                if(i <= n) v2.push_back(i);i++;
                if(i <= n) v2.push_back(i);i++;
                if(i <= n)  {
                    if(i==(n+1)/2) {
                        v2.push_back(i);
                    }
                    else v1.push_back(i);
                    i++;
                }
                if(i <= n)  {
                    if(i==(n+1)/2) {
                        v2.push_back(i);
                    }
                    else v1.push_back(i);
                    i++;
                }
            }
            int v1l1 = v1.back();
            v1.pop_back();
            int v2l1 = v2.back();
            v2.pop_back();
            int v2l2 = v2.back();
            v2.pop_back();
            v1.push_back(v2l2);
            v1.push_back(v2l1);
            v2.push_back(v1l1);
        }
    }
    int n1 = v1.size(), n2 = v2.size();
    cout << n1 << endl;
    for(int i = 0; i < n1; i++) {
        cout << v1[i] << " ";
    }
    cout << endl << n2 << endl;
    for(int i = 0; i < n2; i++) {
        cout << v2[i] << " ";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    twoSetsByMaths(n);

    return 0;
}