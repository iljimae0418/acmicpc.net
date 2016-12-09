// dfs memoization
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

char board[101][101]; 
int cache[101][101][81]; 
string word;  
int n,m,k;  

int dy[4] = {0,1,0,-1}; 
int dx[4] = {1,0,-1,0}; 

bool inRange(int y,int x){
	return (y >= 0 && y < n && x >= 0 && x < m);  
}

int solve(int y,int x,int pos){
	if (pos == word.size()) return 1;  
	int &ret = cache[y][x][pos];  
	if (ret != -1) return ret;  
	ret = 0;  
	for (int steps = 1; steps <= k; steps++){
		for (int i = 0; i < 4; i++){
			int ny = y+dy[i]*steps; 
			int nx = x+dx[i]*steps; 
			if (inRange(ny,nx) && board[ny][nx] == word[pos]){
				ret += solve(ny,nx,pos+1);  
			}
		}
	}
	return ret;  
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
	cin >> word; 
	memset(cache,-1,sizeof(cache)); 
	int ans = 0;  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (board[i][j] == word[0]){
				ans += solve(i,j,1);  
			}
		}
	}
	cout << ans << endl; 
	return 0; 
} 
