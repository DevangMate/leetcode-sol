class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ham=start^goal;
    int cnt=0;
    while(ham>0){
        if(ham&1){
            cnt++;
        }
        ham=ham>>1;
    }
    return cnt;
    }
};