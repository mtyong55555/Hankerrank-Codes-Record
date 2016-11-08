#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <stack>
using namespace std;

typedef std::pair<long int, long int> my_pair;

bool sort_pred(const my_pair& left, const my_pair& right)
{
     return left.first < right.first;
}

int main() {  
    long int n,m;
    cin >> n >> m;
    long sum = n*m;
    int k;
    cin >> k;
    map<long int,vector<my_pair>> track;
    for(int i = 0; i < k; i++){
        long int r,c1,c2;
        cin >> r >> c1 >> c2;
        if(track.find(r) == track.end()){
            vector<my_pair> temp;
            temp.push_back(my_pair(c1,c2));
            track.insert(make_pair(r,temp));
        }
        else{
            track[r].push_back(my_pair(c1,c2));
        }
    }
    map<long int,vector<my_pair>>::iterator iter;
    
    for(iter = track.begin(); iter != track.end(); ++iter){
        sort(iter->second.begin(),iter->second.end(),sort_pred);
    }
    
    long int count = 0;
    
    for(iter = track.begin(); iter != track.end(); ++iter){
        long int length = iter->second.size();
        stack<my_pair> merge;
        merge.push(iter->second[0]);
        for(long int i = 1; i < length; i++){
            my_pair top = merge.top();
            if(top.second < iter->second[i].first){
                merge.push(iter->second[i]);
            }
            else if(top.second < iter->second[i].second){
                top.second = iter->second[i].second;
                merge.pop();
                merge.push(top);
            }
        }
        
        while(!merge.empty()){
            my_pair top = merge.top();
            count += top.second - top.first + 1;
            merge.pop();
        }
    }
    
    cout << sum - count << endl;
    
    return 0;
}
