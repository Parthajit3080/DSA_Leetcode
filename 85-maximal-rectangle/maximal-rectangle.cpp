class Solution {
public:
    //find prev small element of pos
    int findpse(vector<int> &height,int pos){
        for(int i=pos-1;i>=0;i--){
            if(height[i]<height[pos])
                return i;
        }
        return -1;
    }
    //find next small element of pos
    int findnse(vector<int> &height,int pos){
        int n=height.size();
        for(int i=pos+1;i<n;i++){
            if(height[i]<height[pos])
                return i;
        }
        return n;
    }

    int max_rect_area(vector<int> &height){
        int n=height.size();
        int max_area=0;
        for(int i=0;i<n;i++){
            int pse=findpse(height,i);
            int nse=findnse(height,i);

            int width=nse-pse-1;
            int area= width*height[i];

            max_area=max(max_area,area);
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxarea=0;
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> height(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1')
                    height[j]++;
                else    
                    height[j]=0;
            }
            int ans=max_rect_area(height);
            maxarea=max(ans,maxarea);
        }
        return maxarea;
    }
};