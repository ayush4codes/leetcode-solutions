class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_c = 0;
        int ten_c = 0;
        for (int i : bills){
            if (i == 5) {
                five_c++;
            } 
            else if (i == 10){
                if (five_c == 0){
                    return false;
                }
                five_c--;
                ten_c++;
            } 
            else if (i == 20){
                if (ten_c > 0 && five_c > 0){
                    ten_c--;
                    five_c--;
                } 
                else if (five_c >= 3){
                    five_c -= 3;
                } 
                else{
                    return false;
                }
            }
        }
        return true;
    }
};