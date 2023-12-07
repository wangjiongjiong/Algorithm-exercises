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
};


int main(int argc , char* argv[])
{
    Solution solution;
    /* 27 */
    vector<int> vec = {0,1,2,2,3,0,4,2};
    int size1 = solution.removeElement1(vec,2);
    int size2 = solution.removeElement2(vec,2);
    for(int i = 0; i<size1;++i)
    {
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    for(int i = 0; i<size2;++i)
    {
        cout<<vec[i]<<" ";
    }

}