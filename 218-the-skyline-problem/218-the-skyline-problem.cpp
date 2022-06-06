class Solution {
public:
	void append(vector<vector<int>>& skyline, int x, int h) {
		if(!skyline.empty()) {
			if(skyline.back()[0] == x) {
				skyline.back()[1] = std::max(skyline.back()[1], h);
				return;
			}
			if(skyline.back()[1] == h)
				return;
		}
		skyline.push_back({x, h});
	}
	vector<vector<int>> skyline(vector<vector<int>>& blds, int l, int r) {
		if(l == r)
			return { {blds[l][0], blds[l][2]}, {blds[l][1], 0} };
		int m = (l+r)/2;
		auto left  = skyline(blds, l  , m);
		auto right = skyline(blds, m+1, r);
		vector<vector<int>> out;
		out.reserve(left.size() + right.size());
		int i = 0, j = 0;
		int hl = 0, hr = 0;
		while(i < left.size() && j < right.size()) {
			int x;
			if(left[i][0] < right[j][0]) {
				x = left[i][0];
				hl = left[i][1];
				i++;
			} else if(left[i][0] > right[j][0]) {
				x = right[j][0];
				hr = right[j][1];
				j++;
			} else {
				x = left[i][0];
				hl = left[i][1];
				hr = right[j][1];
				i++, j++;
			}
			int h = std::max(hl, hr);
			append(out, x, h);
		}
		for(; i < left.size(); i++)
			append(out, left[i][0], left[i][1]);
		for(; j < right.size(); j++)
			append(out, right[j][0], right[j][1]);
		return out;
	}
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		return skyline(buildings, 0, buildings.size() - 1);
	}
};