class DSU {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DSU(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	// rep node
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	// merge two
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	// same partition? 
	bool connected(int x, int y) { return find(x) == find(y); }
};


class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circle) {
        // dsu treat each point as disconnected
        int n = circle.size();
        DSU ds(n + 4);

        // whole box edges: bottom n, right n + 1, up n + 2, left n + 3
        for (int i = 0; i < n; ++i){
            int u = circle[i][1] + circle[i][2], d = circle[i][1] - circle[i][2], l = circle[i][0] - circle[i][2], r = circle[i][0] + circle[i][2];
            if (l <= 0) ds.unite(i, n + 3);
            if (d <= 0) ds.unite(i, n);
            if (u >= Y) ds.unite(i, n + 2);
            if (r >= X) ds.unite(i, n + 1);
        }

        // compare to other circles see intersect ?
        //  C1C2 = sqrt((x1 – x2)2 + (y1 – y2)2)
        // If C1C2 <= R1 – R2: Circle B is inside A.
        // If C1C2 <= R2 – R1: Circle A is inside B.
        // If C1C2 < R1 + R2: Circle intersects each other.
        // If C1C2 == R1 + R2: Circle A and B are in touch with each other.
        // Otherwise, Circle A and B do not overlap
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                double cc = sqrt(pow(circle[i][0] - circle[j][0], 2) + pow(circle[i][1] - circle[j][1], 2));
                if (cc > circle[i][2] + circle[j][2]) continue; // don't inter
                ds.unite(i, j);
            }
        }

        if (ds.connected(n + 2, n) || ds.connected(n + 1, n + 2) || ds.connected(n + 1, n + 3) || ds.connected(n, n + 3)) return false;
        return true;

    }
};
