class Solution {
    public int maximumWealth(int[][] accounts) {
        int n= accounts.length;
        int m= accounts[0].length;
        int sum[]= new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum[i]=sum[i]+accounts[i][j];
            }
        }
        int max_sum=0;
        for(int i=0;i<n;i++){
            if(max_sum<sum[i]){
                max_sum=sum[i];
            }
        }
        return max_sum;
    }
}