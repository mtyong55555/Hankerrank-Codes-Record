#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        long copy = x;
        // your code goes here
        long base = 1;
        while(x > 1){
            x >>= 1;
            base <<= 1;
        }
        cout << (base - 1) - (copy - base) << endl;
    }
    return 0;
}

