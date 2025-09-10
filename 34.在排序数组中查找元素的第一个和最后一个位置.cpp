class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        int l=-1,r=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
//left
            if(nums[mid]==target){
                right=mid-1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }
        }
        
        l=(left<nums.size()&&nums[left]==target)?left:-1;
//right
        left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                left=mid+1;
            }else if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]<target){
                left=mid+1;
            }
        }
        
        r=(left>0&&nums[left-1]==target)?(left-1):-1;
        
        return {l,r};
    }
};
