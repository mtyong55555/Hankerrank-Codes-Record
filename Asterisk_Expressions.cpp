#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

unsigned long long int M = 1000000007;

unsigned long long int cal(unsigned long long int pow, unsigned long long int val, unsigned long long int MOD){
   if(pow == 0)
      return 1;
   unsigned long long int v = cal(pow/2, val, MOD);
   if(pow % 2 == 0)
       return ((v % MOD) * (v % MOD)) % MOD;
   else
       return (((v % MOD)*(val % MOD) % MOD) * (v % MOD)) % MOD;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        unsigned long long int factor = 1; 
        string evo;    
        cin >> evo;
        int length = evo.size();
        
        bool flag_nim = true;
        
        if(length == 0){
            cout << "Syntax Error" << endl;
            break;
        }
        
        queue<unsigned long long int> nums;
        
        int flag = 0;
        int j = 0; 
        while(j < length){
            if(isdigit(evo[j])){
                unsigned long long int fac = 0;
                while(j < length && isdigit(evo[j])){                   
                    fac = fac * 10;
                    fac = (fac + (unsigned long long int)(evo[j] - '0'));
                    j++;
                }
             
                if(flag == 0 || flag == 2){
                    factor = fac % M;
                }
                else if(flag == 3){                
                    factor = cal(fac,factor,M);
                }
                
                flag = 1; 
            }
            else{
                if(flag == 0 || j >= length - 1){
                    cout << "Syntax Error" << endl;
                    flag_nim = false;
                    break;
                }
                else{
                    if(flag == 1){
                        if(isdigit(evo[j+1])){
                            nums.push(factor % M);
                            factor = 1;
                            flag = 2; //one *
                        }
                        else if(evo[j+1] == '*' && j <= length - 2 && isdigit(evo[j+2])){
                            flag = 3; //two *
                        }
                        else{
                            cout << "Syntax Error" << endl;
                            flag_nim = false;
                            break;
                        }
                    }
                    j++;
                }
            }
        }
        
        if(flag_nim == true){
        while(!nums.empty()){
            factor = ((factor % M) * (nums.front() % M)) % M;
            nums.pop();
        }
        
        cout << factor % M << endl;
        }
    }
    return 0;
}
