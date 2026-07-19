struct Node{
    Node* links[2] = {nullptr};

    bool containsKey(int i){
        return links[i]!=nullptr;
    }
    void put(int i, Node* node){
        links[i] = node;
    }
    Node* get(int i){
        return links[i];
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int maxNum(int num){
        Node* node = root;
        int maxnum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)){
                maxnum = maxnum|(1<<i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxnum;
    }
};
struct query{
    int x;
    int m;
    int id;
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<query> offlineQueries;

        for(int i=0; i<queries.size(); i++){
            offlineQueries.push_back({queries[i][0],queries[i][1],i});
        }

        sort(offlineQueries.begin(),offlineQueries.end(),
        [](const query &a, const query &b){
            return a.m < b.m;
        });
        
        Trie trie;
        int ind = 0;
        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            query temp = offlineQueries[i];
            while( ind<n && nums[ind]<=temp.m ){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0){
                ans[temp.id] = -1;
                // cout<<temp
            }
            // else ans.push_back(trie.maxNum(temp.x));
            else ans[temp.id] = trie.maxNum(temp.x);

        }
        
        return ans;
    }
};