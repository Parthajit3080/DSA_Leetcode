class Solution {
public:
    int nCr(int n,int r){
        int val=1;
        for(int i=0;i<r;i++){
            val=val*(n-i);
            val=val/(i+1);
        }
        return val;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascals;

         for(int i=1;i<=numRows;i++){
            vector<int> row;
            for(int j=1;j<=i;j++){
                row.push_back(nCr(i-1,j-1));
            }    
            pascals.push_back(row);
        } 
        return pascals;
    }
};