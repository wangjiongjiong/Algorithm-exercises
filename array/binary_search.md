# 二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

```text
输入: nums = [-1,0,3,5,9,12], target = 9     
输出: 4       
解释: 9 出现在 nums 中并且下标为 4 
```

```text
输入: nums = [-1,0,3,5,9,12], target = 2     
输出: -1        
解释: 2 不存在 nums 中因此返回 -1 
```

提示：

* 你可以假设 nums 中的所有元素是不重复的。

* n 将在 [1, 10000]之间。

* nums 的每个元素都将在 [-9999, 9999]之间。

[力扣链接](https://leetcode.cn/problems/binary-search/)

## 思路

二分查找的思路比较简单，首先二分查找的适用范围为一个有序的数组，同时还要求了数组中的元素是不重复的，这一点很关键，如果数组中的元素存在着重复情况那么我们返回的下标就毫无意义因为我们返回的下标就不是唯一的了，当满足这两个基本条件，是不是我们就可以考虑使用二分查找来解决问题了。

二分查找本质逻辑比较简单，简单来说就是每次我们查找数组`middle`位置的值是否与我们的`target`相等，如果大于`middle`则在数组右部分继续进行查找，如果小于`middle`则在数组左部分继续进行查找。咋一看二分查找的思路确实比较简单，但是这里面有很大的一个坑，就是边界的选择。我们的边界条件到底是`left<right`还是`left<=right`呢？同时`right=middle`还是`right=middle-1`呢？这一部分就是二分查找最大的坑所在。之所以会有这样的想法是因为我们对区间的定义没有思考好，**区间的定义就是不变量**，在二分查找的过程中我们每一步对于边界的判断都是要根据区间的定义来思考，这就是**循环不变量**规则(这里的思想来自代码随想录，嘻嘻)。

因此在写二分查找的时候，区间的定义一般就有两种，一种是区间定义为左闭右闭`[left,right]`和左闭右开`[left,right)`这两种情况。

### 情况一

情况一，定义区间为左闭右闭，`[left,right]`。这就决定了二分查找最重要的两个点，首先是`while(left<=right)`这一部分，因为此时我们的区间是左闭右闭的，因此我们对于`right`是有可能取到的因此此使要取等号，其次是`num[middle] > target` 时 `right = middle -1`，因为此时`num[middle]`的值此时一定不是`target`,因此之后的循环区间右侧赋予 `middle-1`即可。

```cpp
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
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
};
```



### 情况二

情况二，定义区间为左闭右开，`[left，right)`。如果我们区间选择左闭右开的区间，首先`while(left<right)`这里就无需取等号，因此区间右侧是开区间，我们对于`right`是无法取到的。其实是当`num[middle]>target`时我们取`right = middle`即可，还是因为区间的原因，右侧始终我们是取不到的因此下一次查询是不会搜索`num[middle]`的。

```cpp
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
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
};
```

题目汇总

[搜索插入位置](https://leetcode.cn/problems/search-insert-position/description/)

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

- 输入: [1,3,5,6], 5
- 输出: 2

示例 2:

- 输入: [1,3,5,6], 2
- 输出: 1

示例 3:

- 输入: [1,3,5,6], 7
- 输出: 4

示例 4:

- 输入: [1,3,5,6], 0
- 输出: 0

这个问题其实并不算难，其实就是二分查找的一个小延伸，如果我们查找失败就是将`target`目标值顺序插入原数组中。

可以利用二分查找实现。

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

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
};
```

前面如果查到的话返回`middle`是可以理解的，最后返回`right+1`需要简单的理解一下。

这里其实仔细想一想有四种情况

1. 数组中存在查找的数，直接返回下标，返回`middle`
2. 数组中不存在查找的数，且数组中的数都比`target`大，在退出循环的最后一次赋值时，因为数组中的值都大于target所以最后一次依然是`right = middle -1` 但此时`middle`已经是0了因此，只要是数组中的数都大于target那么最后`left`和`right`的值就为`0，-1`。因此最后我们返回`right+1`，也就是数组下标0
3. 数组中不存在查找的数，且数组中的数都比`target`小，此时`right`就为数组最后因此返回`right+1`
4. 数组中不存在查找的数，`target`插入数组之间，循环最后退出时right就为此时区间的右值，又因为这种情况我们考虑了左闭右闭区间，因此需要`+1`

