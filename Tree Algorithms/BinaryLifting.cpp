struct BinaryLifting {
	int n;
	int mxLog;
	int maxRequirement;
	vector<vector<int>>parent;

	BinaryLifting(int n1, vector<int> *edges, int requirement, int root) {
		n = n1;
		mxLog = log2(requirement + 1);
		maxRequirement = requirement;
		parent.resize(n1);

		for (int i = 0; i < n; i++) {
			parent[i].resize(mxLog + 1);
			for (int j = 0; j <= mxLog; j++) {
				parent[i][j] = -1;
			}
		}
		fillParentTable(root, edges);
	}

	void fillParentTable(int root, vector<int> *edges) {
		vector<bool>visited(n);
		dfsBinaryLifting(root, edges, visited);

		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= mxLog; j++) {
				int intermediate = parent[i][j - 1];
				if (intermediate != -1) {
					parent[i][j] = parent[intermediate][j - 1];
				}
			}
		}
	}

	void dfsBinaryLifting(int root, vector<int> *edges, vector<bool>&visited) {
		visited[root] = true;

		for (auto i : edges[root]) {
			if (!visited[i]) {
				parent[i][0] = root;
				dfsBinaryLifting(i, edges, visited);
			}
		}
	}

	int kthParent(int u, int k) {
		for (int i = 0; i <= mxLog; i++) {
			if ((k >> i) & 1) {

				if (u == -1)return u;
				u = parent[u][i];
			}
		}
		return u;
	}
};
