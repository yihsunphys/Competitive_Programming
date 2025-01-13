#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    int M, A, B;
    cin >> N >> M >> A >> B;

    vector<pair<long long, long long>> intervals;
    for (int i = 0; i < M; ++i) {
        long long L, R;
        cin >> L >> R;
        intervals.emplace_back(L, R);
    }

    // 加入邊界，確保考慮整個範圍
    intervals.emplace_back(1, 0);     // 虛擬起點（左邊界外）
    intervals.emplace_back(N + 1, N); // 虛擬終點（右邊界外）
    sort(intervals.begin(), intervals.end());

    long long reachable = 1; // 當前最遠可到達的格子
    for (auto &[L, R] : intervals) {
        // 如果壞格子的左邊界超過最遠可到達範圍，直接結束
        if (L > reachable + B) {
            cout << "No" << endl;
            return 0;
        }

        // 更新最遠可到達範圍（在壞格子範圍之外嘗試跳躍）
        if (L > reachable) {
            reachable = max(reachable + A, L); // 嘗試跨過空隙
        }

        // 如果最遠可到達範圍進入壞格子的範圍，限制最大可跳到的位置
        if (reachable >= L) {
            reachable = max(reachable, R + 1);
        }

        // 如果已經到達或超過終點，輸出 Yes
        if (reachable >= N) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // 無法到達終點
    cout << "No" << endl;
    return 0;
}
