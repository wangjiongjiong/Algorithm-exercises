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

情况一
