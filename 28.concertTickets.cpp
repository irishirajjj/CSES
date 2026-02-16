#include <bits/stdc++.h>

using namespace std;

int findLessThanOrEqualTo(multiset<int>& ms, int money) {

    //NOTE: WE WON'T DO BINARY SEARCH, AS IT WILL LEAD TO A LINEAR SEARCH TOO
    // int index = -1;
    // while(low <= high) {
    //     int mid = (low + high) / 2;

    //     if(tickets[mid] > money) {
    //         high = mid;
    //     }
    //     if(tickets[mid] <= money) {

    //     }
    // }
    // return index == -1 ? -1 : tickets[index];
    
    int paidMoney = -1;
    auto it = ms.upper_bound(money);
    if(it == ms.begin())return paidMoney;
    else {
        --it;
        paidMoney = *it;
        ms.erase(it);
    }
    return paidMoney;
}
vector<int> concertTickets(vector<int>& tickets, vector<int>& customers) {
    int n = tickets.size();
    int m = customers.size();

    multiset<int> ms(tickets.begin(), tickets.end());


    vector<int>paid(m, -1);

    for(int i = 0; i < m; i++) {
        paid[i] = findLessThanOrEqualTo(ms, customers[i]);
    }

    return paid;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; 
    vector<int> tickets(n, 0), customers(m, 0);
    for(int i = 0; i < n; i++) {
        cin >> tickets[i];
    }
    for(int j = 0; j < m; j++) {
        cin >> customers[j];
    }

    vector<int> paid = concertTickets(tickets, customers);

    for(int i = 0; i < m; i++) {
        cout << paid[i] << endl;
    }

    return 0;
}