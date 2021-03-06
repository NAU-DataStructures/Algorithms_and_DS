//https://www.hackerrank.com/challenges/dijkstrashortreach
#include <cstring>
#include <iostream>
#include <algorithm>
#define inf 0x7fffffff
using namespace std;
int arr[3001][3001];
bool was[3001];
int d[3001];
int main() {
    
    int t;
    cin >> t;
    while(t--){
        
        int n, m, s, a ,b, k;
        cin >> n >> m;
        
        
        for(int i = 1 ; i <= n ; ++i){
            d[i] = inf;
            was[i] = false;
        }
        
        memset(arr, -1, sizeof arr);
        
        for(int i = 0; i < m ; ++i){
            cin >> a >> b >> k;
            if(arr[a][b] > k || arr[a][b] == -1){
                arr[a][b] = k;
                arr[b][a] = k;
            }
            
        }
        cin >> s;
        
        d[s] = 0;
        int ct = n;
        
        while(ct--){
            
            for(int i = 1; i <= n; ++i)
                if(arr[s][i] != -1 && d[i] > d[s] + arr[s][i])
                    d[i] = d[s] + arr[s][i];
            
            was[s] = true;
            int min = inf;
            
            for(int i = 1; i <= n; ++i)
                if(min > d[i] && !was[i]){
                    min = d[i];
                    s = i;
                }
            
        }
        
        for(int i = 1 ; i <= n ; ++i){
            if(d[i] == 0);
            else if(d[i] == inf) cout << "-1 ";
            else cout << d[i] << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}
