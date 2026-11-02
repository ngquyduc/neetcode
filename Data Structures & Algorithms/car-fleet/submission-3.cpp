class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;
        for (int i = 0; i < position.size(); i++) {
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.rbegin(), ps.rend());
        stack<double> s;
        for (pair<int, int> p : ps) {
            double time = (double)(target - p.first) / p.second;
            cout << time << "\n";
            if (s.empty()) {
                s.push(time);
                continue;
            }
            if (s.top() < time) {
                s.push(time);
            }
        }
        return s.size();
    }
};
