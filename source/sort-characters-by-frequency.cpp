class Solution {
public:
    
    static bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    return a.second > b.second;
}
  
// Function to sort the map according
// to value in a (key-value) pairs
vector<pair<char, int>> sort(map<char, int>& M)
{
  
    // Declare vector of pairs
    vector<pair<char, int>> A;
  
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }
  
    // Sort using comparator function
    std::sort(A.begin(), A.end(), cmp);

    return A;
}
    
    string frequencySort(string s) {
        map<char, int> map;
        vector<pair<char, int>> v;
        string res("");

        for(char c : s)
            map[c]+=1;

        v = sort(map);

        for(auto &[key, value] : v){
            //cout << key << " " <<value << endl;
            for(int i=0; i<value; i++)
                res+=key;
        }

        return res;
    }
};