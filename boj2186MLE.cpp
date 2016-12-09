#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <queue> 
#include <utility> 
using namespace std; 

int n,m,k;  
char board[101][101];  

int dy[4] = {0,1,0,-1}; 
int dx[4] = {1,0,-1,0}; 

bool inRange(int y,int x){
	return (y >= 0 && y < n && x >= 0 && x < m);  
}

int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);  
	cin >> n >> m >> k;  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> board[i][j];  
		}
	}
	string word; 
	cin >> word; 
	int ans = 0;  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (board[i][j] != word[0]) continue;  
			queue< pair< string, pair<int,int> > > que;    
			que.push(make_pair(string(1,board[i][j]),make_pair(i,j)));  
			while (!que.empty()){	
				pair< string,pair<int,int> > P = que.front(); que.pop();  
				string cur = P.first; 
				int y = P.second.first, x = P.second.second; 
				if (cur.size() > word.size()) continue;  
				if (cur == word){
					ans++; 
					continue;   
				}
				for (int steps = 1; steps <= k; steps++){
					for (int i = 0; i < 4; i++){
						int ny = y+dy[i]*steps;  
						int nx = x+dx[i]*steps; 
						if (inRange(ny,nx)){ 
							que.push(make_pair(cur+board[ny][nx],make_pair(ny,nx)));  
						}	
					}
				}
			}	
		}
	}
	cout << ans << endl; 
	return 0;  
}
