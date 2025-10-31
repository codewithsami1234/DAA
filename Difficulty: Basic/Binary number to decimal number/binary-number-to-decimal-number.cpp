class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int result = 0;
        int base = 1;
        for(int i = b.size()-1; i >= 0; i--){
            if(b[i] == '1'){
                result += base;
            }
            base *= 2;
        }
        return result;
    }
};