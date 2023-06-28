#include <bits/stdc++.h>
using namespace std;

const int TOTAL = 5e5;
const int N = 3e5;
const int TC = 5e4;

int SUM = 0;

vector<vector<int>> ans;
int res;

void Delete(vector<int> a){
    // for(int i = 0; i < a.size(); i++) cout<<a[i]<<" ";
    // cout<<"\n";
    int n = a.size();

    int j = n - 1, k = n;
    vector<int> c;
    int cur_rem = 0;

    for(int i = 0; i < n - 2; i++){
        if(a[i] > a[n - 2]){
            ans.push_back({2, i + 1 - cur_rem, j - cur_rem, k - cur_rem});
            cur_rem++;
        }
        else c.push_back(a[i]);
    }

    //now all the elements > an-1 are removed

    c.push_back(a[n - 2]);
    c.push_back(a[n - 1]);

    a = c;
    int removed = 0;

    n = a.size();

    vector<array<int,2>> stk;

    for(int i = 0; i < n - 2; i++){
        while(stk.size() > 0 && stk.back()[0] > a[i]){
            ans.push_back({2, stk.back()[1], i - removed + 1, n - removed});
            stk.pop_back();
            removed++;
        }
        stk.push_back({a[i], i - removed + 1});
    }

    cout<<"YES\n";
    cout<<ans.size()<<" "<<res<<"\n";
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}


void solve(){
    ans.clear();
    int n; cin>>n;
    assert(3 <= n && n <= N);

    SUM += n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    set<int> s;
    
    vector<int> m(n + 1);
    
    for(int i = 0; i < n; i++){
        assert(a[i] >= 1 && a[i] <= n);
        s.insert(a[i]);
        m[a[i]] = i;
    }

    assert(s.size() == n);

    if(a[n - 2] < a[n - 1]){
        res = 0;
        Delete(a);
        return;
    }

    if(a[n - 2] != n){
        res = 1;
        ans.push_back({1, m[n] + 1, n});
        swap(a[m[n]], a[n - 1]);
        Delete(a);
        return;
    }

    if(n == 3){
        cout<<"NO\n";
        return;
    }

    if(a[n - 3] == 1){
        if(a[n - 1] == 2){

            // .... x, n
            res = 2;
            ans.push_back({1, 1, n - 1});
            ans.push_back({1, 1, n});
            swap(a[0], a[n - 2]);
            swap(a[0], a[n - 1]);
            Delete(a);
            return;
        }

        //  ... 1, 2, x (x > 2)
        res = 1;
        ans.push_back({1, m[2] + 1, n - 1});
        swap(a[m[2]], a[n - 2]);
        Delete(a);
        return;
    }

    if(a[n - 1] != 1){
        // .... 1, x (x > 1)
        res = 1;
        ans.push_back({1, m[1] + 1, n - 1});
        swap(a[m[1]], a[n - 2]);
        Delete(a);
        return;
    }

    //... 1, x (x > 1)
    res = 2;    
    ans.push_back({1, 1, n - 1});
    ans.push_back({1, 1, n});

    swap(a[0], a[n - 2]);
    swap(a[0], a[n - 1]);

    Delete(a);
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int t; cin>>t;
    assert(1 <= t && t <= TC);

    while(t--)
        solve();

    assert(SUM <= TOTAL);
}   
