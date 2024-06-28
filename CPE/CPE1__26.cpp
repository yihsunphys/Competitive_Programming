#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    getline(cin,s);
    while(n--){
        int sum=0;
        map <string,int> mp;
        while(getline(cin,s)&&s!=""){
            mp[s]++;
            sum++;
        }
        for(auto i: mp){
        cout<<i.first<<" "<<fixed<<setprecision(4)<<(double)i.second/sum*100<<endl;
        }
        cout<<endl;
    }
    return 0;
}
//
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    getline(cin, s) ;
    getline(cin, s) ;
    while(n--) {
        int total = 0;
        map<string, int> mp;
        string s;
        while(getline(cin, s)) {
            if(s == "") {
                for(auto it = mp.begin(); it != mp.end(); it++) {
                    cout << it->first << " " << fixed << setprecision(4) << (double)it->second/total*100 << '\n';
                }
                cout <<'\n';
                break;
            }
            mp[s]++;
            total++;
        }
        if(n == 0){
        for(auto it = mp.begin(); it != mp.end(); it++) {
                    cout << it->first << " " << fixed << setprecision(4) << (double)it->second/total*100 << '\n';
                }
          }
        }
    
}
