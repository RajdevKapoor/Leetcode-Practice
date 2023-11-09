class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        // Intution
        // The idea in here is really very simple. We will maintain the id of the creater along with the total number of views and also the creator and then id of the creator along with the name of the creator.

        unordered_map<string, long long> mp1;
        unordered_map<string, pair<string, long long>> mp2;

        int n = creators.size();

        for(int i = 0 ; i < n ; i++){
            string creator = creators[i];
            string id = ids[i];
            int view = views[i];

            if(mp1.find(creator) == mp1.end()){
                mp1[creator] = view;
                mp2[creator] = {id, view};
            }

            else{
                if(view > mp2[creator].second){
                    mp2[creator] = {id, view};
                }
                else if(view == mp2[creator].second){
                    string currentId = mp2[creator].first >= id ? id : mp2[creator].first;
                    mp2[creator] = {currentId, view};
                }
                mp1[creator] += view;
            }
        }

        long long maxViews = INT_MIN;
        for(auto itr = mp1.begin() ; itr != mp1.end() ; itr++)
            maxViews = max(maxViews, itr->second);

        vector<vector<string>> answer;

        for(auto itr = mp1.begin() ; itr != mp1.end() ; itr++){
            if(itr->second == maxViews){
                answer.push_back({itr->first, mp2[itr->first].first});
            }
        }

        return answer;
    }
};