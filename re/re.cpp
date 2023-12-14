#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

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
    void moveZeroes1(vector<int>& nums) 
    {
        //双指针思想
        int size = nums.size();
        int fast = 0 , low = 0;
        while (fast < size)
        {
            if(nums[fast] != 0)
            {
                std::swap(nums[fast],nums[low]);
                low++;
            }
            fast++;
        }
    }
    void moveZeroes2(vector<int>& nums) 
    {
        //两次遍历
        int j = 0;
        for(int i = 0; i<nums.size();++i)
        {
            if(nums[i] != 0)
            {
                nums[j] = nums[i];
                ++j;
            }
        }
        for(int k = j;k<nums.size();++k)
        {
            nums[k] = 0;
        }
    }
    void moveZeroes3(vector<int>& nums) 
    {
        //快速排序思想,类似双指针但是更简洁
        int left = 0;
        int size = nums.size();
        for(int i = 0; i<size;++i)
        {
            if(nums[i] != 0)
            {
                std::swap(nums[left],nums[i]);
                left++;
            }
        }
    }
    bool backspaceCompare1(string s, string t) 
    {
        //使用栈的思想
        string s_stack;
        string t_stack;
        for(auto a :s)
        {
            if(a!='#')
            {
                s_stack.push_back(a);
            }
            else if(!s_stack.empty())
            {
                s_stack.pop_back();
            }
        }
        for(auto b :t)
        {
            if(b!='#')
            {
                t_stack.push_back(b);
            }
            else if(!t_stack.empty())
            {
                t_stack.pop_back();
            }
        }
        if(t_stack == s_stack)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool backspaceCompare2(string s, string t) 
    {
        //使用双指针思路
        int s_point = s.length() - 1;
        int t_point = t.length() - 1;
        int s_skip = 0;
        int t_skip = 0;
        while (s_point >= 0 || t_point >= 0)
        {
            while (s_point >= 0)
            {
                if(s[s_point] == '#')
                {
                    s_skip++;
                    s_point--;
                }
                else if (s_skip > 0)
                {
                    s_skip--;
                    s_point--;
                }
                else
                {
                    break;
                }
                
            }
            while (t_point >= 0)
            {
                if(t[t_point] == '#')
                {
                    t_skip++;
                    t_point--;
                }
                else if (t_skip > 0)
                {
                    t_skip--;
                    t_point--;
                }
                else
                {
                    break;
                }
            }
            if(s_point >= 0 && t_point >= 0)
            {
                if(s[s_point] != t[t_point])
                {
                    return false;
                }
            }
            else
            {
                if(s_point >= 0 || t_point >= 0)
                {
                    return false;
                }
            }
            s_point--;
            t_point--; 
        }
        return true;      
    }
    bool backspaceCompare3(string s, string t)
    {
        //也是双指针但是感觉要优于官解
        return equal_string(s) == equal_string(t);

    }
private:
    string equal_string(string str)
    {
        int fast = 0;
        int low = 0;
        int size = str.length();
        while (fast < size)
        {
            if(str[fast] != '#')
            {
                str[low++] = str[fast++];
            }
            else
            {
                fast++;
                if(low > 0)
                {
                    low--;
                }
            }
        }
        return str.substr(0,low);
        
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
    /* vector<int> vec = {0,0,1,2,2,3,3,4};
    int size1 = solution.removeDuplicates1(vec);
    int size2 = solution.removeDuplicates2(vec);
    for(int i = 0; i<size1;++i)
    {
        cout<<vec[i]<<" ";
    }
    for(int i = 0; i<size2;++i)
    {
        cout<<vec[i]<<" ";
    } */
    /* 283 */
    /* vector<int> vec = {1,3,0,0,0,12};
    solution.moveZeroes3(vec);
    for(auto e : vec)
    {
        cout<<e<<" ";
    } */
    /* 844 */
    string s = "a#dc";
    string t = "#a#c";
    cout<<solution.backspaceCompare3(s,t);

}