//coder: Luis Miguel Casan Gonzalez
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph; 
bool dom[105][105];
bool visited[105];
bool tmp[105];

void dfs(int u, int x)
{
    if(u == x) return;
    
    visited[u] = true;

    for(int v : graph[u])
        if(visited[v] == false) dfs(v, x);
    
    
}

int main()
{
    freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        //read:
        graph.resize(n);
        for(vector<int> &v : graph)
            for(int x, i = 0; i < n; i++)
            {
                cin >> x;
                if(x == 1) v.push_back(i);
            } 

        // //nodos conected with 0;
        dfs(0, -1);

        // //tmp == visited
        for(int i = 0; i < n; i++) {tmp[i] = visited[i];}

        
        for(int i = 0; i < n; i++)
        {
            for(bool & it : visited) it = false;

            dfs(0, i);
            for(int j = 0; j < n; j++) 
            {
                dom[i][j] = tmp[j]&(!visited[j]);
            }
        } 

        //printf: 
        for(int i = 0; i < n; i++)
        {
            cout << '+';
            for(int j = 1; j < 2*n; j++) cout << '-';
            cout << '+';
            cout << "\n";
            
            cout <<'|';
            for(int j = 0; j < n; j++) cout << dom[i][j] <<"|";
            cout << "\n"; 
        }

        cout << '+';
        for(int j = 1; j < 2*n; j++) cout << '-';
        cout << '+';
        cout << "\n";
    }
    
}
