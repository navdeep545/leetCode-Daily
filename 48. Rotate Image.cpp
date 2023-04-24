class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        vector<vector<int>> v(n,vector<int>(n)) ;
        for(int i=n-1;i>=0;i--)
        for(int j=0;j<n;j++)
        v[j][i] = matrix[i][j] ;
        matrix.clear() ;
        matrix = v ;
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end()) ;
        }
        return ;
    }
};