class ZigzagIterator {
public:
    unordered_map<int, int> p;
    unordered_map<int, vector<int>> v_map;
    int iter;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        p = {{0, 0}, {1, 0}};
        v_map[0] = v1;
        v_map[1] = v2;
        iter = 0;
    }

    int next() {
        int res;
        if(p[iter] < v_map[iter].size()){
            res = v_map[iter][p[iter]];
            p[iter]++;
            iter += 1 % 2;
            iter %= 2;
        } else {
            iter += 1;
            iter %= 2;
            res = v_map[iter][p[iter]];
            p[iter]++;
        }
        return res;
    }

    bool hasNext() {
        if(p[0] < v_map[0].size() || p[1] < v_map[1].size()) return true;
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */