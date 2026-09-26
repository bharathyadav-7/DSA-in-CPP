class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> digits;
        int remaining=k;
        for(char digit:nums){
                while(remaining>0 && !digits.empty() && digits.top()>digit){
                    digits.pop();
                    remaining--;
                }
            digits.push(digit);
        }
        while(remaining >0 && !digits.empty()){
            digits.pop();
            remaining--;
        }
        string result;
        while(!digits.empty()){
            result.push_back(digits.top());
            digits.pop();
        }
        reverse(result.begin(),result.end());
        int start =0;
        while(start<result.size() && result[start]=='0'){
            start++;
        }
        if(start==result.size()){
            return "0";
        }
        return result.substr(start);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna