struct LCA {
	int n;
	vector<int>level;
	LCA(int n1, int root, vector<int> *edges) {
		n = n1;
		level.resize(n1);
		dfsLCA(root, -1, edges);
	}

	void dfsLCA(int root, int parent, vector<int> *edges) {
		for (auto i : edges[root]) {
			if (i != parent) {
				level[i] = level[root] + 1;
				dfsLCA(i, root, edges);
			}
		}
	}

	int getLCA(int u, int v, BinaryLifting &bl_object) {
		if (level[u] < level[v])swap(u, v);
		int diff = level[u] - level[v];
		u = bl_object.kthParent(u, diff);

		if (u == v)return u;

		for (int i = bl_object.mxLog; i >= 0; i--) {
			int parent1 = bl_object.parent[u][i];
			int parent2 = bl_object.parent[v][i];
			if (parent1 != parent2 && parent1 != -1 && parent2 != -1) {
				u = parent1;
				v = parent2;
			}
		}

		return bl_object.parent[u][0];
	}

};