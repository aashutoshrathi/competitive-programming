// April 4
void moveZeroes(vector<int>& nums) {
    int cnt = 0;
    // this is also called 2 pointer approach as per hints
    for(int i=0; i<nums.size(); i++) {
        if(nums[i]!=0){
            nums[cnt++] = nums[i];
        }
    }
    while(cnt < nums.size()) {
        nums[cnt++] = 0;
    }
}