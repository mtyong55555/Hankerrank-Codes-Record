#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;

void inQueue(deque<pair<int,int>> &Q, pair<int,int> item){
    while(!Q.empty() && Q.back().first < item.first)
        Q.pop_back();
    Q.push_back(item);
}

void outQueue(deque<pair<int,int>> &Q, int index){
    if(Q.front().second == index)
        Q.pop_front();
}

int main() {
    int n,q;
    cin >> n >> q;
    vector<pair<int,int>> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i].first;
        vec[i].second = i;
    }
    for(int i = 0; i < q; i++){
        int d;
        cin >> d;
        int minim = INT_MAX;
        deque<pair<int,int>> max_queue;
        
        for(int j = 0; j < d - 1; j++){
            inQueue(max_queue,vec[j]);
        }
        
        for(int j = d - 1;j < n; j++){
            inQueue(max_queue,vec[j]);
            minim = min(minim,max_queue.front().first);
            outQueue(max_queue,j - d + 1);
        }
        cout << minim << endl;
    }
    return 0;
}
