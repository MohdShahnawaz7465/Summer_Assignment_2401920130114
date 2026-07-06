class Solution {
public:
    int strStr(string h, string n) {
        if( h.size() < n.size() ){
            return -1;
        }
        int j=0;
        for(int i=0; i<= h.size()-n.size(); i++){
            if(h[i]==n[0]){
                int I=i;
                while(j < n.size() && h[I]==n[j]){
                    I++;
                    j++;
                }
                if(j==n.size()){
                    return i;
                }
            }
            j=0;
        }
         return-1;
    }
};
