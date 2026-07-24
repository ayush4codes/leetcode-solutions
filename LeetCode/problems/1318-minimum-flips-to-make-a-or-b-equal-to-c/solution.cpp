class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i=0;i<31;i++){
            int f=(a>>i) & 1;
            int s=(b>>i) & 1;
            int t=(c>>i) & 1;
            
            if ((s|f)!=t){
                if (t==1){
                    flips+=1;
                    }
                else{
                    flips+=f+s;
                }

                
            }
        }
        return flips;
        // make an int count
        // 32 bit
        // if 
        // calculate f,s,t 
    }
};