class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answers(2, vector<int>(0));
        map<int, int> map;

        for(auto tuple : matches){
            if(map.find(tuple[0]) == map.end())
                map[tuple[0]] = 0;
            map[tuple[1]]+=1;
        }

        for(const auto & [ key, value ] : map){
            if(value == 0) answers[0].push_back(key);
            else if(value == 1) answers[1].push_back(key);
        }

        return answers;   
    }
};