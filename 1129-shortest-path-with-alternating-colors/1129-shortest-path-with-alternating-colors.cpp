#define vvi vector<vector<int>>
#define vi vector<int>
#define vvb vector<vector<bool>>

#define items1 answer, visited
#define items2 answer, visited, redGraph, blueGraph

class Solution {
public:
	
	vvi query;
	
	
	void goHere(vi& answer, vvb& visited, int id, int dis, bool prevRed) {
		if (visited[id][prevRed])
			return;
		
		if (answer[id] == -1)
			answer[id] = dis;
		else
			answer[id] = min(answer[id], dis);
		
		visited[id][prevRed] = true;
		query.push_back({id, dis, prevRed});
	}
	void bfs(vi& answer, vvb& visited, vvi& redGraph, vvi& blueGraph, int id, int dis, bool prevRed) {
		vvi& graph = prevRed ? blueGraph : redGraph;
		
		for (int destination : graph[id]) {    
			goHere(items1, destination, dis + 1, !prevRed);
		}
	}
	
	
	vi shortestAlternatingPaths(int n, vvi& redEdges, vvi& blueEdges) {
		vi answer(n, -1);
		
		vvb visited(n, {false, false});

		vvi redGraph(n);
		vvi blueGraph(n);
		
		
		// Initialize the graph
		for (vi edge : blueEdges) {
			blueGraph[edge[0]].push_back(edge[1]);
		}
		for (vi edge : redEdges) {
			redGraph[edge[0]].push_back(edge[1]);
		}
		
		// Start from the first node
		goHere(items1, 0, 0, false);
		goHere(items1, 0, 0, true);
		
		// Do all query
		int ptr = 0;
		while (ptr < query.size()) {
			bfs(items2, query[ptr][0], query[ptr][1], query[ptr][2]);
			++ptr;
		}

		return answer;
	}
};