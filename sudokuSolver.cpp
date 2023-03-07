#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sudoku(9);
vector<set<int>> row(9), col(9), box(9);

bool check(int i, int j, int x){
    return (row[i].count(x) == 0 && col[j].count(x) == 0 && box[(i/3)*3+j/3].count(x) == 0);
}

int solve(int inX, int inY){
    int x = inX, y = inY;
    if(x == 8 && y == 9){
        return 1;
    }

    if(y == 9){
        y = 0;
        x += 1;
    }
    
    if(sudoku[x][y] != 0){
        return solve(x, y+1);
    }

    for(int i = 1;i<=9;i++){
        if(check(x,y,i)){
            row[x].insert(i);
            col[y].insert(i);
            box[(x/3)*3+y/3].insert(i);
            sudoku[x][y] = i;
            if(solve(x,y+1) == 1){
                return 1;
            }
            sudoku[x][y] = 0;
            row[x].erase(i);
            col[y].erase(i);
            box[(x/3)*3+y/3].erase(i);
        }
    }

    return 0;
}

int main(){
    freopen("input.txt", "r", stdin);
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            int x;cin >> x;
            sudoku[i].push_back(x);
            if(x != 0){
                row[i].insert(x);
                col[j].insert(x);
                box[(i/3)*3 + j/3].insert(x);
            }
        }
    }
    if(solve(0,0)){
        cout << "Solved!" << '\n';
    }
    else{
        cout << "Unsolvable" << '\n';
        return 0;
    }
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}