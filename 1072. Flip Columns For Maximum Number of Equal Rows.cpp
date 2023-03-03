#include <vector>
using namespace std ;

class Solution {
public:
    vector<int> flipper(vector<int> v){
        int n = v.size() ;
        vector<int> m(n) ;
        for(int i=0;i<n;i++)
            v[i]==1 ? m[i] = 0 : m[i] = 1 ;
        return m ;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int count = 0 ;
        int n = matrix.size() ;
        for(int i=0;i<n;i++){
            vector<int> v = flipper(matrix[i]) ;
            int temp = 0 ;
            for(int j=i+1;j<n;j++){
                    if(matrix[j] == matrix[i] ) temp++ ;
                    else if(matrix[j] == v) temp++ ;
            }
            count = max(count,temp) ;
        }
        return count+1 ;
    }
};


// all by myself 😏😏