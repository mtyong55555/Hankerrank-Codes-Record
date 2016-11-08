#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    stack<long int> heights;
    map<long int,int> height_map;
    long int equal_count = 0;
    long int count = 0;
    for(int ai = 0; ai < n; ai++){
        long int height;
        cin >> height;
        if(heights.empty() || heights.top() > height)
            heights.push(height);
        else{
             bool flag = true;
             while(!heights.empty() && heights.top() < height)
             {
                 if(height_map.find(heights.top()) != height_map.end())
                     height_map[heights.top()] = 0;
                 heights.pop();
             }
             if(!heights.empty() && heights.top() == height){
                 flag = false;
                if(height_map.find(height) == height_map.end()){
                     height_map.insert(make_pair(height,1));
                    count += 2;
                 }
                 else{             
                     height_map[height]++;
                     count += height_map[height] * 2;                   
                 }
             }
            if(flag)
                heights.push(height);
        }
    }
    cout << count << endl;
    return 0;
}
