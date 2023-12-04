#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Solution 
{
public:
    int search1(vector<int>& nums, int target) 
    {
        int left , right , middle;
        left = 0;
        right = nums.size() - 1;
        while(left <= right)
        {
            middle = left + (right - left)/2;
            if(nums[middle] > target)
            {
                right = middle - 1 ;
            }
            else if (nums[middle] < target)
            {
                left = middle +1;
            }
            else
            {
                return middle;
            }
        }
        return -1;

    }
    int search2(vector<int>& nums, int target) 
    {
        int left , right , middle;
        left = 0;
        right = nums.size();
        while(left < right)
        {
            middle = left + (right - left)/2;
            if(nums[middle] > target)
            {
                right = middle;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
    int searchInsert1(vector<int>& nums, int target) {

        int left , right ,middle;
        left = 0;
        right = nums.size()-1;
        while(left <= right)
        {
            middle = left + (right - left)/2;
            if(nums[middle] > target)
            {
                right = middle - 1;
            }
            else if(nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return right + 1;

    }
    int searchInsert2(vector<int>& nums, int target) {

        int left , right ,middle;
        left = 0;
        right = nums.size();
        while(left < right)
        {
            middle = left + (right - left)/2;
            if(nums[middle] > target)
            {
                right = middle;
            }
            else if(nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return right;

    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = getleft(nums,target);
        int right = getright(nums,target);

        if(left == -2 || right == -2)
        {
            return {-1,-1};
        }
        else if(right - left > 1)
        {
            return {left + 1,right - 1};
        }
        else
        {
            return {-1,-1};
        }

    }
private:
    int getright(vector<int>& nums, int target)
    {
        int left , right , middle;
        left = 0;
        right = nums.size() - 1;
        int rightborder = -2;
        while(left <= right)
        {
            middle = left + (right - left)/2;
            if(nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
                rightborder = left;
            }
        }
        return rightborder;
    }

    int getleft(vector<int>& nums, int target)
    {
        int left , right , middle;
        left = 0;
        right = nums.size() - 1;
        int leftborder = -2;
        while(left <= right)
        {
            middle = left + (right - left)/2;
            if(nums[middle] >= target)
            {
                right = middle - 1;
                leftborder = right;
            }
            else
            {
                left = middle + 1;
            }
        }
        return leftborder;
    }
};

int main(int argc,char **argv)
{
    /* 704 */
    Solution solution;
    vector<int> test = {0,1,2,6,7,11,66,89,94,102};
    int index = solution.search2(test,102);
    cout<<index<<endl;
    /* 35 */
    int index2 = solution.searchInsert2(test,-2);
    cout<<index2<<endl;
    /* 34 */
    vector<int> test2 = {5,7,7,8,8,10};
    vector<int> res = solution.searchRange(test2,8);
    for(auto &a : res)
    {
        cout<<a;
    }


    return 0;
}