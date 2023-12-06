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

    int mySqrt(int x) 
    {
        int n = 0;
        if(x == 0)
        {
            return 0;
        }
        while (n*n<=x)
        {
            if(n*n<=x && (long long)(n+1)*(n+1)>x)
            {
                return n;
            }
            n++;
        }
        return n;
        
    }

    int mySqrt_change(int x) 
    {
        int left , right , middle;
        left = 0;
        right = x;
        int res = 0;
        while (left<=right)
        {
            middle = left + (right-left)/2;
            if((long long)middle*middle<=x)
            {
                res = middle;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return res;
    }
    bool isPerfectSquare(int num) 
    {
        int left , right , middle;
        left = 0;
        right = num;
        while(left<=right)
        {
            middle = left + (right-left)/2;
            if((long long)middle*middle == num)
            {
                return true;
            }
            else if((long long)middle*middle < num)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return false;
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
    Solution solution;
    /* 704 */
    /* Solution solution;
    vector<int> test = {0,1,2,6,7,11,66,89,94,102};
    int index = solution.search2(test,102);
    cout<<index<<endl; */
    /* 35 */
    /* int index2 = solution.searchInsert2(test,-2);
    cout<<index2<<endl; */
    /* 34 */
    /* vector<int> test2 = {5,7,7,8,8,10};
    vector<int> res = solution.searchRange(test2,8);
    for(auto &a : res)
    {
        cout<<a;
    } */
    /* 69 */
    /* int n = 4;
    int res = solution.mySqrt(n);
    int res2 = solution.mySqrt_change(n);
    cout<<res<<res2<<endl; */
    /* 367 */
    int num = 16;
    bool res = solution.isPerfectSquare(num);
    cout<<res<<endl;

    return 0;
}