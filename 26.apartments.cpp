#include <bits/stdc++.h>

using namespace std;

int apartmentsCount(vector<int>& applicants, vector<int>& apartments, int k) {
    int n = applicants.size(), m = apartments.size();
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    int i = 0, j = 0;
    int count = 0;
    while(i < n && j < m) {

        while(j < m && applicants[i] - k  > apartments[j]){
            j++;
        }
        if( j < m && i < n && apartments[j] >= applicants[i] - k && apartments[j] <= applicants[i] + k) {
            count++; i++; j++;
        }
        while(i < n && applicants[i] + k  < apartments[j]){
            i++;
        }
    }
    return count;
}

int apartmentsCountPolished(vector<int>& applicants, vector<int>& apartments, int k) {
    int n = applicants.size(), m = apartments.size();
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    int i = 0, j = 0;
    int count = 0;
    while(i < n && j < m) {
        int low = applicants[i] - k;
        int high = applicants[i] + k;
        if(apartments[j] < low) j++;
        else if(apartments[j] >= low && apartments[j] <= high){
            i++; j++; count++;
        }
        else i++;
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n, 0), apartments(m, 0);

    for(int i = 0; i < n; i++)cin >> applicants[i];
    for(int i = 0; i < m; i++)cin >> apartments[i];

    // Time: O(n log n + m log m), Space: O(1)
    int applicantsToGetHome = apartmentsCountPolished(applicants, apartments, k);
    // int applicantsToGetHome = apartmentsCount(applicants, apartments, k);
    cout << applicantsToGetHome << endl;

    return 0;
}