class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int i=n-1,j=m-1;

        if(n==1 && m==1) return to_string((num1[0]-'0') + (num2[0]-'0'));

        string ans = "";

        int car = 0;
        while(i>=0 && j>=0){
            int temp = (num1[i]-'0') + (num2[j] - '0') + car;
            cout << temp << endl;
            if(temp >9){
                car = temp/10;
                temp = temp%10;
            }else{
                car = 0;
            }
            ans += to_string(temp);
            i--;
            j--;
        }
        cout << ans << endl;

        while(i>=0){
            int temp = (num1[i] - '0') + car;
            cout << temp << endl;
            if(temp >9){
                car = temp/10;
                temp = temp%10;
            }else{
                car=0;
            }
            ans += to_string(temp);
            i--;
        }
        while(j>=0){
           int temp = (num2[j] - '0') + car;
            cout << temp << endl;
            if(temp >9){
                car = temp/10;
                temp = temp%10;
            }else{
                car = 0;
            }
            ans += to_string(temp);
            j--;
        }

        if(car != 0) ans += to_string(car);

        reverse(ans.begin(), ans.end());
        return ans;

    }
};