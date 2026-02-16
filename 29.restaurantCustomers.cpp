#include <bits/stdc++.h>

using namespace std;

int maxRestaurantCustomers(const vector<int>& arrivals, const vector<int>& departures) {
    int n = arrivals.size();
    int maxCustomers = 0;
    int a = 0, d = 0;
    int currCustomers = 0;
    while(a < n) {
        if(arrivals[a] < departures[d]){
            currCustomers++;
            a++;
        }
        else {
            currCustomers--;
            d++;
        }
        maxCustomers = max(maxCustomers, currCustomers);
    }
    return maxCustomers;
}

int findMaxRestaurantCustomers(const vector<pair<int,int>>& events) {
    int maxCustomers = 0, currentCustomers = 0;
    for(auto event : events) {
        currentCustomers += event.second;
        maxCustomers = max(maxCustomers, currentCustomers);
    }
    return maxCustomers;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // vector<int> arrivals(n, -1), departures(n, -1);
    // for(int i = 0; i < n; i++){
    //     cin >> arrivals[i] >> departures[i];
    // }
    // sort(arrivals.begin(), arrivals.end());
    // sort(departures.begin(), departures.end());

    // int maxCustomers = maxRestaurantCustomers(arrivals, departures);

    // CLEANER APPROACH: 

    vector<pair<int,int>> events;
    for(int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        events.push_back({a, 1});
        events.push_back({d, -1});
    }
    sort(events.begin(), events.end());

    int maxCustomers = findMaxRestaurantCustomers(events);
    cout << maxCustomers << endl;

    return 0;
}