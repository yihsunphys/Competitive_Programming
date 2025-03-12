#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct st{
  vector<int> v;
  ll tot = 0;
  int mx = 0;
  int size = 0;
  int u = 0;
};

bool cmp(st a, st b) {
  if(a.tot == b.tot){
    if(a.u == b.u){
      return a.size > b.size;
    }
    else return a.u > b.u;
  }
  else return a.tot > b.tot;
}
st gp[200005];
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      gp[i].v.clear();
      gp[i].tot = 0;
      gp[i].mx = 0;
      gp[i].size = 0;
      gp[i].u = 0;
    }
    int m = 0, id = 0;
    for(int i = 0; i < n; i++) {
      int num;
      cin >> num;
      gp[i].size = num;
      for(int j = 0; j < num; j++){
        int x; 
        cin >> x;
        gp[i].v.push_back(x);
        gp[i].tot += x;
        gp[i].mx = max(gp[i].mx, x);
        if(x > m) { m = x; id = i;
        }
      }
    }
    gp[id].u = 1;
    sort(gp, gp+n, cmp);
    for(int i = 0; i < n; i++){
      for(auto it: gp[i].v)
        cout << it << " "; 
      cout << '\n'; 
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Group {
    ll index;                   // Original index of the group
    ll total_milk;              // Total banana milk from the group
    ll max_milk;                // Max banana milk from a single person in the group
    ll people_count;            // Number of people in the group
    vector<ll> milk_list;       // Banana milk each person gives in the group

    // Custom comparator for sorting groups based on the problem's criteria
    bool operator<(const Group& other) const {
        if (total_milk != other.total_milk) {
            return total_milk > other.total_milk; // Sort by total_milk descending
        }
        if (max_milk != other.max_milk) {
            return max_milk > other.max_milk;     // Sort by max_milk descending
        }
        if (people_count != other.people_count) {
            return people_count > other.people_count; // Sort by people_count descending
        }
        return index < other.index;               // Sort by original index ascending
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll T;
    cin >> T;

    while (T--) {
        ll N;
        cin >> N;
        vector<Group> groups;

        for (ll i = 0; i < N; i++) {
            ll K;
            cin >> K;
            vector<ll> milk(K);
            ll total_milk = 0;
            ll max_milk = 0;
            for (ll j = 0; j < K; j++) {
                cin >> milk[j];
                total_milk += milk[j];
                max_milk = max(max_milk, milk[j]);
            }

            // Create the group with its attributes
            groups.push_back({i, total_milk, max_milk, K, milk});
        }

        // Sort the groups based on the custom comparator
        sort(groups.begin(), groups.end());

        // Output the sorted group indices and banana milk info
        for (const auto& group : groups) {
            for (const auto& milk : group.milk_list) {
                cout << milk << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
