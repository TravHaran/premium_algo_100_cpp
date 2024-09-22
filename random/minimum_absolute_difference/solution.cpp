class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDif = INT_MAX;
        vector<vector<int>> res;
        for(int i = 1; i < arr.size(); i++){
            int cur_dif = abs(arr[i]-arr[i-1]);
            if(cur_dif < minDif){
                res = {{arr[i-1], arr[i]}};
                minDif = cur_dif;
            } else if(cur_dif==minDif){
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};