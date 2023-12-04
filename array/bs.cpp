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

    return 0;
}