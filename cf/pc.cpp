#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; // number of test cases
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Sort the array
        sort(a.begin(), a.end());

        // Sliding window approach
        int max_cards = 0;
        map<int, int> freq;
        int distinct_count = 0;
        int left = 0;
        int tmp = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > a[i-1]+1) {
                ans = max(ans, tmp);
                tmp = 0;  
            }
            else {
                
                if(a[i] == a[i-1]) {
                    distinct_count++;
                    if(distinct_count > k) {
                        ans = max(ans, tmp);
                        tmp = 0;
                    }
                }
                tmp++;
            }
        }
        // Output the result for the current test case
        cout << ans << '\n';
    }

    return 0;
}
