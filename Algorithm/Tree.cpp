//BFS를 이용한 부모배열과 각 노드의 깊이값 채우기
vector<int> adj[10];
int p[10];
int depth[10];
void BFS(int root){
	queue<int> q; //BFS는 queue를 사용함을 기억하자
	q.push(root);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int nxt : adj[cur]){
			//특정 노드의 인접정점이 부모노드일 경우
			if(p[cur] == nxt) continue;
			//부모노드가 아닌경우 모두 자식이므로
			p[nxt] == cur; //nxt는 cur의 자식노드임을 알린다
			depth[nxt] = depth[cur]+1; //자식노드 nxt는 부모노드 cur보다 1씩 깊이를 더해준다
			q.push(nxt);
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------
//DFS를 이용한 부모배열과 각 노드의 깊이값 채우기
vector<int> adj[10];
int p[10];
int depth[10];
void DFS(int root){
	stack<int> s;  //DFS는 stack을 사용함을 기억하자
	s.push(root);
	while(!s.empty()){
		int cur = s.top(); s.pop();
		for(int nxt : adj[cur]){
			//특정 노드의 인접정점이 부모노드일 경우
			if(p[cur] == nxt) continue;
			//부모노드가 아닌경우 모두 자식이므로
			p[nxt] == cur; //nxt는 cur의 자식노드임을 알린다
			depth[nxt] = depth[cur]+1; //자식노드 nxt는 부모노드 cur보다 1씩 깊이를 더해준다
			s.push(nxt);
		}
	}
}
//---------------------------------------------------------------------------------------------------------------------------
//DFS와 재귀를 이용한 부모배열과 각 노드의 깊이값 채우기 (스택 메모리가 1MB로 제한되어 있을 경우 주의 요함)
vector<int> adj[10];
int p[10];
int depth[10];
void DFS(int cur){
	for(int nxt : adj[cur]){
		//특정 노드의 인접정점이 부모노드일 경우
		if(p[cur] == nxt) continue;
		p[nxt] = cur;
		depth[nxt] = depth[cur]+1;
		DFS(nxt);
	}
}
//---------------------------------------------------------------------------------------------------------------------------
//단순 순회
vector<int> adj[10];
//현재 노드와 부모노드를 매개변수로 지정 (root 노드부터 시작하면 (1, 0))
void DFS(int cur, int par){
	for(int nxt : adj[cur]){
		//부모노드와 cur의 인접노드가 같다면 (즉 인접노드가 부모노드라면)
		if(par == nxt) continue;
		//nxt는 자식노드가 되고 cur는 부모노드가 되므로 아래와 같이 재귀
		DFS(nxt, cur);
	}
}
