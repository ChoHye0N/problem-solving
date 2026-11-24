#include <bits/stdc++.h>
using namespace std;

int m;
vector<int> matchOdd;
vector<bool> visited;
vector<vector<int>> adj;

bool dfs(int u){
    for (int v : adj[u]){
        if (visited[v]) continue;
        visited[v] = true;

        if (matchOdd[v] == -1 || dfs(matchOdd[v])){
            matchOdd[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int firstN = -1;
    vector<int> even, odd;

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;

        if (i == 0) firstN = tmp;

        (tmp & 1) ? odd.push_back(tmp) : even.push_back(tmp);
    }

    vector<bool> eratos(2001, true);
    eratos[0] = eratos[1] = false;

    for (int i = 2; i * i < 2001; i++){
        if (!eratos[i]) continue;

        for (int j = i * i; j < 2001; j += i){
            eratos[j] = false;
        }
    }

    if (even.empty() || odd.empty() || even.size() != odd.size()){
        cout << -1;
        return 0;
    }

    vector<int> res;

    if (!(firstN & 1)){
        for (int cnt = 0; cnt < odd.size(); cnt++){
            int partner = odd[cnt];
            if (!eratos[firstN + partner]) continue;

            vector<int> remEven, remOdd;
            for (int x : even){
                if (x != firstN) remEven.push_back(x);
            }
            for (int i = 0; i < odd.size(); i++){
                if (i != cnt) remOdd.push_back(odd[i]);
            }

            if (remEven.size() != remOdd.size()) continue;
            m = remEven.size();

            adj.assign(m, vector<int>());
            for (int a = 0; a < m; a++){
                for (int b = 0; b < m; b++){
                    if (eratos[remEven[a] + remOdd[b]]){
                        adj[a].push_back(b);
                    }
                }
            }

            matchOdd.assign(m, -1);
            int matched = 0;
            for (int a = 0; a < m; a++){
                visited.assign(m, false);
                if (dfs(a)) matched++;
            }

            if (matched == m) res.push_back(partner);
        }
    }
    else{
        for (int cnt = 0; cnt < even.size(); cnt++){
            int partner = even[cnt];
            if (!eratos[firstN + partner]) continue;

            vector<int> remOdd, remEven;
            for (int x : odd){
                if (x != firstN) remOdd.push_back(x);
            }
            for (int i = 0; i < even.size(); i++){
                if (i != cnt) remEven.push_back(even[i]);
            }

            if (remEven.size() != remOdd.size()) continue;
            m = remEven.size();

            adj.assign(m, vector<int>());
            for (int a = 0; a < m; a++){
                for (int b = 0; b < m; b++){
                    if (eratos[remEven[a] + remOdd[b]]){
                        adj[a].push_back(b);
                    }
                }
            }

            matchOdd.assign(m, -1);
            int matched = 0;
            for (int a = 0; a < m; a++){
                visited.assign(m, false);
                if (dfs(a)) matched++;
            }

            if (matched == m) res.push_back(partner);
        }
    }

    if (res.empty()){
        cout << -1;
        return 0;
    }

    sort(res.begin(), res.end());
    for (int p : res){
        cout << p << ' ';
    }

    return 0;
}