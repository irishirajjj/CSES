#include <bits/stdc++.h>

using namespace std;

int movieLoverFunction(const vector<pair<int,int>>& movies) {
    int moviesWatched = 0, lastWatchingMovies =0, previousEndTime = movies[0].second;
    vector<int> watchedMovies;
    for(int i = 1; i < movies.size(); i++) {
        if(previousEndTime <= movies[i].first) { // previous movie completed
            moviesWatched++;
            watchedMovies.push_back(lastWatchingMovies);
            previousEndTime = movies[i].second;
            lastWatchingMovies = i;
        }
        else if(previousEndTime > movies[i].second) { //We started to watch the movie, but left it and started another: LOL
            previousEndTime = movies[i].second;
            lastWatchingMovies = i;
        }
    }
    moviesWatched++;
    // watchedMovies.push_back(lastWatchingMovies);
    // cout << "Watched Movies Numbers: " << endl;
    // for(int i = 0; i < watchedMovies.size(); i++) {
    //     cout << i + 1 <<  ". "  << watchedMovies[i] << endl;
    // }
    return moviesWatched;
}

void sortMoviesByEndTime(vector<pair<int,int>>& movies) {
    int n = movies.size();
    sort(movies.begin(), movies.end(),[](pair<int,int>& a, pair<int,int>&b){
        return a.second < b.second;
    } );
    int moviesCount = 1;
    int previousEndTime = movies[0].second;
    for(int i = 1; i < n; i++) {
        if(previousEndTime <= movies[i].first) {
            moviesCount++;
            previousEndTime = movies[i].second;
        }
    }
    cout << moviesCount << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> movies;
    for(int i = 0; i < n; i++) {
        int start = 0, end = 0;
        cin >> start >> end;
        movies.push_back({start, end});
    }

    sortMoviesByEndTime(movies);

    // sort(movies.begin(), movies.end());

    // int maxMoviesWatched = movieLoverFunction(movies);

    // cout << maxMoviesWatched << endl;

    return 0;
}