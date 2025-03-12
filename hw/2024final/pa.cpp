#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_COORD = 2000000;
const int OFFSET = 1000000;

struct SegmentTree {
    vector<int> count, length;
    
    SegmentTree(int n) {
        count.assign(4 * n, 0);
        length.assign(4 * n, 0);
    }

    void update(int node, int start, int end, int l, int r, int value) {
        if (r <= start || end <= l) return;
        if (l <= start && end <= r) {
            count[node] += value;
        } else {
            int mid = (start + end) / 2;
            update(2 * node + 1, start, mid, l, r, value);
            update(2 * node + 2, mid, end, l, r, value);
        }

        if (count[node] > 0) {
            length[node] = end - start;
        } else {
            length[node] = (start == end - 1) ? 0 : (length[2 * node + 1] + length[2 * node + 2]);
        }
    }

    int query() {
        return length[0];
    }
};

int main() {
    int n;
    cin >> n;

    SegmentTree segTree(MAX_COORD);
    
    for (int i = 0; i < n; ++i) {
        int l, r, t;
        cin >> l >> r >> t;
        l += OFFSET;
        r += OFFSET;

        if (t == 1) {
            segTree.update(0, 0, MAX_COORD, l, r, 1);
        } else if (t == -1) {
            segTree.update(0, 0, MAX_COORD, l, r, -1);
        }

        cout << segTree.query() << "\n";
    }

    return 0;
}
