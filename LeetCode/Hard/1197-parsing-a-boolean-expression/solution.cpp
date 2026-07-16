class Solution {
public:
    bool parse(string& ex, int &i){
        
        if(ex[i]=='t'){
            i++;
            return true;
        }
        if(ex[i]=='f'){
            i++;
            return false;
        }
        if(ex[i]=='!'){
            i+=2;

            bool temp = !parse(ex,i);
            i++;

            return temp;
        }
        if(ex[i]=='|'){
            bool ans = false;
            i+=2;

            while(ex[i]!=')'){
                bool value = parse(ex,i);
                
                ans = ans || value;

                if(ex[i]==','){
                    i++;
                }
            }
            i++;
            return ans;
        }
        if(ex[i]=='&'){
            bool ans = true;
            i+=2;

            while(ex[i]!=')'){
                bool value = parse(ex,i);
                
                ans = ans && value;

                if(ex[i]==',') i++;
            }
            i++;
            return ans;
        }
        return false;
    }
    bool parseBoolExpr(string expression) {
        int i=0;
        return parse(expression,i);
    }
};