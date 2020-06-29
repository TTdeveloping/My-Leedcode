#### [面试题 10.01. 合并排序的数组](https://leetcode-cn.com/problems/sorted-merge-lcci/)

**题目：**给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

**示例:**

```
输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
```

**说明:**

```
A.length == n + m
```

**思路：**

可以用两个方法去做。

- 这一种方法应该是很多人能够想到的，就是把B中的元素全部加入到数组A中，然后再对整个数组A进行排序（用sort函数）。但是也要注意的是，题目中已经提示A 的末端有足够的缓冲空间容纳 B，所以不能用push_back的方式直接添加B中的元素，而只能在相应的位置赋值。排序长度为m+n，如果用快排的话，时间复杂度也为O((m+n)log(m+n))，空间复杂度为O(log(m+n))。可见代码如下：

  ```
  class Solution {
  public:
      void merge(vector<int>& A, int m, vector<int>& B, int n) {
          for(int i=0;i<n;i++){
              A[m+i]=B[i];//在对应位置赋值。
          }
          sort(A.begin(),A.end());
      }
  };
  ```

  

- 第二种方法，就是用双指针方法，指向数组A的是a指针，指向数组B的是b指针。两个数组都是倒着一一比较大小，因为两个数组都是有序的，根据示例数组（升序），最大的放在A数组之后。没有占用额外空间，只是在数组A上进行修改的，所以空间复杂度为O(1)，因为指针最多挪动m+n次，所以，时间复杂度为O(m+n)。代码如下：

  ```
  class Solution {
  public:
      void merge(vector<int>& A, int m, vector<int>& B, int n) {
          int a = m-1,b = n-1;
          int tail = m+n-1;
          while(a>=0||b>=0){
              if(a==-1){
                  A[tail] = B[b];
                  b--;
                  tail--;
              }
              else if(b==-1){
                  A[tail] = A[a];
                  a--;
                  tail--;
              }
              else if(A[a]<B[b]){
                  A[tail] = B[b];
                  b--;
                  tail--;
              }
              else {
                  A[tail] = A[a];
                  a--;
                  tail--;
              }
          }
      }
  };
  ```