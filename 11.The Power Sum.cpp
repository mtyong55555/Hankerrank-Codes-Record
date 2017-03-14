#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int powerCal(int base, int n, int x){
    int temp = base;
    for(int i = 1; i < n; i++){
        if(base < x)
            base *= temp;
        else
            return x + 1;
    }
    return base;
}

void powerHelper(int x,int offset,int& result,int n){
    if(x < 0)
        return;
    if(x == 0){
        result++;
        return;
    }
    for(int i = offset; i < x; i++){
        int sum = powerCal(i,n,x);
        powerHelper(x - sum,i + 1,result,n);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x,n;
    cin >> x >> n;
  
    int result = 0;
    
    powerHelper(x,1,result,n);
    
    cout << result;
    
    return 0;
}
