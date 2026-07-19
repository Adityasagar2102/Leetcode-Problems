struct Node{
    Node* links[26] = {nullptr};
    bool containskey(char ch){
        return links[ch - 'a']!= nullptr;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }

};
class Solution{	
	public:
		int countSubs(string& s) {
			//your code goes here
            Node* root = new Node();
            int cnt = 0;

            for(int i=0; i<s.size(); i++){
                Node* node = root;
                for(int j=i; j<s.size(); j++){
                    if(!node->containskey(s[j])){
                        node->put(s[j],new Node());
                        cnt++;
                    }
                    node = node->get(s[j]);
                }
            }
            return cnt;
		}
};

