#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ex,ey;
int dir[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
static int k_count = 0;
static int k_count_min = 0;

bool dfs(vector<vector<char>>& matrix, int i, int j){
    if(i == ex && j == ey){
        return true;
    }
    
    matrix[i][j] = 'X';
    int change = 0;
    for(int k = 0; k < 4; k++){
        int row = i + dir[k][0];
        int col = j + dir[k][1];
        if(row >= 0 && row < n && col >= 0 && col < m && matrix[row][col] == '.'){
            change++;
        }
    }
    
    for(int k = 0; k < 4; k++){
        int row = i + dir[k][0];
        int col = j + dir[k][1];
        if(row >= 0 && row < n && col >= 0 && col < m && matrix[row][col] == '.'){
            if(dfs(matrix,row,col) == true){
                if(change > 1)
                    k_count++;
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> n >> m;
        int sx,sy;
        k_count = 0;
        k_count_min = 0;
        vector<vector<char>> matrix;
        for(int i = 0; i < n; i++){
            vector<char> temp(m);
            for(int j = 0; j < m; j++){
                cin >> temp[j];
                if(temp[j] == 'M'){
                    sx = i;
                    sy = j;
                    temp[j] = '.';
                }
                if(temp[j] == '*'){
                    ex = i;
                    ey = j;
                    temp[j] = '.';
                }
            }
            matrix.push_back(temp);
        }
        int k_guess;
        cin >> k_guess;
        int i = sx, j = sy;
        bool ok = dfs(matrix,i,j);
        if(k_count == k_guess)
            cout << "Impressed" << endl;
        else
            cout << "Oops!" << endl;
    }
    return 0;
}
