#include <bits/stdc++.h>
using namespace std;

const int X[3][4] = {{18, 21, 9, 1}, {16, 23, 11, 3}, {12, 13, 15, 14}};
const int Y[3][4] = {{16, 12, 8, 4}, {17, 13, 9, 5}, {0, 1, 3, 2}};
const int Z[3][4] = {{2, 12, 21, 7}, {3, 14, 20, 5}, {8, 9, 11, 10}};

// 壓縮的狀態表示
using State = bitset<48>;

// 字符到數字的映射
char colorToDigit(char c) {
    switch(c) {
        case 'R': return '0';
        case 'G': return '1';
        case 'B': return '2';
        case 'Y': return '3';
        case 'O': return '4';
        case 'W': return '5';
        default: return '.';
    }
}

State Input() {
    vector<string> in(6);
    for(auto &i : in) cin >> i;
    State res;
    int bitPos = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            if(in[i*2][j*2] == '.') continue;
            for(int a = 0; a < 2; a++) {
                for(int b = 0; b < 2; b++) {
                    char c = in[i*2 + a][j*2 + b];
                    res[bitPos] = colorToDigit(c) - '0';
                    bitPos += 4;
                }
            }
        }
    }
    return res;
}

void Swap(State &s, const int C[3][4]) {
    for(int i = 0; i < 3; i++) {
        int temp = s[C[i][0]];
        for(int j = 0; j < 3; j++) s[C[i][j]] = s[C[i][j + 1]];
        s[C[i][3]] = temp;
    }
}

bool Check(const State &s) {
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 3; j++)
            if(s[i * 4 + j] != s[i * 4 + j + 1]) return false;
    return true;
}

int BiBFS(const State &start) {
    unordered_set<State> visitedStart, visitedEnd;
    queue<pair<State, int>> qStart, qEnd;

    // 初始狀態和目標狀態
    qStart.push({start, 0});
    visitedStart.insert(start);

    State goal;
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 4; j++)
            goal[i * 4 + j] = i;
    
    if(start == goal) return 0;
    
    qEnd.push({goal, 0});
    visitedEnd.insert(goal);

    const int (*ops[3])[4] = {X, Y, Z};

    // 雙向 BFS
    while(!qStart.empty() && !qEnd.empty()) {
        // 每次擴展較小的一邊
        if(qStart.size() > qEnd.size()) swap(qStart, qEnd), swap(visitedStart, visitedEnd);

        int size = qStart.size();
        while(size--) {
            auto [current, depth] = qStart.front(); qStart.pop();
            
            for(const int (*C)[4] : ops) {
                State next = current;
                Swap(next, C);

                if(visitedEnd.count(next)) return depth + 1 + qEnd.front().second;
                if(!visitedStart.count(next)) {
                    visitedStart.insert(next);
                    qStart.push({next, depth + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        State s = Input();
        if(s.none()) break;
        int res = BiBFS(s);
        cout << res << "\n";
    }
    return 0;
}
