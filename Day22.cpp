//problem name:-Single Number I
//take an example of 10 10 10 7 in bits 
class Solution {
public:
     Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int singleNumber(vector<int>& nums) {
        int result=0;
        
        for(int i=0;i<32;i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)){
                    count++;
                }
            }
            result+=(count%3<<i);
        }
        return result;
    }
};
