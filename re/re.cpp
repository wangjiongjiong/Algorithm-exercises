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
    /* 27 暴力求解法 */
    int removeElement1(vector<int>& nums, int val) 
    {
            int len = nums.size();
            //int res = 0;
            for(int i = 0; i < len;++i)
            {
                if(nums[i] == val)
                {
                    for(int j = i + 1;j < len; ++j)
                    {
                        nums[j - 1] = nums[j];
                    }
                    //res++;
                    len--;
                    i--;
                }
                
            }
            //return nums.size() - res;
            return len;
    }
    /* 27 双指针法 */
    int removeElement2(vector<int>& nums, int val)
    {
        int fastptr;
        int lastptr = 0;
        int size = nums.size();
        for (fastptr = 0;fastptr < size;++fastptr)
        {
            if(nums[fastptr] != val)
            {
                nums[lastptr] = nums[fastptr];
                lastptr++;
            }
        }
        return lastptr;
    }

    int removeElement3(vector<int>& nums, int val) 
    {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) 
        {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val)
            {
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) 
            {
                -- rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex) 
            {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
    }

    int removeDuplicates1(vector<int>& nums) 
    {
        //暴力解法
        int size = nums.size();
        for(int i = 0;i<size-1;)
        {
            if(nums[i] == nums[i+1])
            {
                for(int j = i + 1;j<size-1;++j)
                {
                    nums[j] = nums[j+1];
                    
                }
                size--;
            }
            else
            {
                i++;
            }
        } 
        return size;     

    }

    int removeDuplicates2(vector<int>& nums) 
    {
        //双指针方法
        int fast , low;
        int size = nums.size();
        if(size == 0)
        {
            return 0;
        }
        fast  = 1, low = 1;
        while (fast < size)
        {
            if(nums[fast - 1] != nums[fast])
            {
                nums[low] = nums[fast];
                low++;
            }
            fast++;
        }
        return low;

    }
};


int main(int argc , char* argv[])
{
    Solution solution;
    /* 27 */
    /* vector<int> vec = {0,1,2,2,3,0,4,2};
    int size1 = solution.removeElement1(vec,2);
    int size2 = solution.removeElement3(vec,2);
    for(int i = 0; i<size1;++i)
    {
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i<size2;++i)
    {
        cout<<vec[i]<<" ";
    } */
    /* 26 */
    vector<int> vec = {0,0,1,2,2,3,3,4};
    int size1 = solution.removeDuplicates1(vec);
    int size2 = solution.removeDuplicates2(vec);
    for(int i = 0; i<size1;++i)
    {
        cout<<vec[i]<<" ";
    }
    for(int i = 0; i<size2;++i)
    {
        cout<<vec[i]<<" ";
    }

}