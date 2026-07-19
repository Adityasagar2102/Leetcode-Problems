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

class Solution {
public:

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;

        int maxValue = 0;

        for(int i=0; i<n; i++){
            trie.insert(nums[i]);
        }
        for(int i=0; i<n; i++){
            int temp = trie.maxNum(nums[i]);
            maxValue = max(maxValue, temp);
        }

        return maxValue;
        
    }
};