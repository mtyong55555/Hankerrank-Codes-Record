#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 201

int getMid(vector<int>& rank,int d){
    if(d % 2 != 0){
        int mid = (d + 1)/2;
        int count = 0;
        for(int i = 0; i < SIZE; i++){
            count += rank[i];
            if(count >= mid){
                return i * 2;
            }
        }
    }
    else{
        int mid_front = d/2;
        int mid_behind = d/2 + 1;
        int average_front = -1;
        int average_behind = -1;
        int count = 0;
        for(int i = 0; i < SIZE; i++){
            count += rank[i];
            if(count == mid_front){
                average_front = i;
            }
            else if(count >= mid_behind){
                if(average_front != -1){
                    return average_front + i;
                }
                else{
                    return i * 2;
                }
            }   
        }
    }
    return 0;
}

int main() {
    int n,d;
    cin >> n >> d;
    vector<int> vec(n);
    vector<int> rank(SIZE);
    
    for(int i = 0; i < d; i++){
        cin >> vec[i];
        rank[vec[i]]++;
    }
    
    int count = 0;
    
    if(n == d){
        cout << count << endl;
        return 0;
    }
    
    for(int i = 0; i < n - d; i++){
        cin >> vec[d + i];
        int med = getMid(rank,d);
        if(vec[d + i] >= med){
            count++;
        }
        rank[vec[i]]--;
        rank[vec[d + i]]++;
    }
    
    cout << count << endl;
    
    return 0;
}
