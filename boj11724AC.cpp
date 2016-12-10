#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
using namespace std; 

int graph[1001][1001];  
bool marked[1001]; 
int n,m; 

void mark(int u){
	if (marked[u]){
		return;  
	}
	marked[u] = true;  
	for (int i = 1; i <= n; i++){
		if (graph[u][i]){
			mark(i);  
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cin >> n >> m;  
	for (int i = 0; i < m; i++){
		int a,b; 
		cin >> a >> b;  
		graph[a][b] = graph[b][a] = 1;  
	}
	int components = 0;  
	for (int i = 1; i <= n; i++){
		if (!marked[i]){
			mark(i);  
			++components;  
		}
	}
	cout << components << endl;
	return 0;  
}
