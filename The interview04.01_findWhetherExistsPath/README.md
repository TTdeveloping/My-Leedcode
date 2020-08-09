#### [面试题 04.01. 节点间通路](https://leetcode-cn.com/problems/route-between-nodes-lcci/)

**题目：**节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

**示例1:**

```
 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
```

**示例2:**

```
 输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 输出 true
```

**提示：**

    节点数量n在[0, 1e5]范围内。
    节点编号大于等于 0 小于 n。
    图中可能存在自环和平行边。

**代码：**

```c++
//使用的BFS思想，对我来说BFS更好理解。
class Solution {
public:
    vector<bool> examine;
    vector<vector<int>> path;
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        examine = vector<bool>(n,false);
        path = vector(n,vector<int>(1,-1));
        for(int i=0;i<graph.size();i++){
            path[graph[i][0]].push_back(graph[i][1]);
        }
        return search(start,target);
    }
    bool search(int start, int target){
        queue<int> q;
        int v;
        q.push(start);
        while(!q.empty()){
            v=q.front();
            q.pop();
            for(int i=1;i<path[v].size();i++){
                if(examine[path[v][i]]==false){
                    examine[path[v][i]] = true;
                    if(path[v][i] == target) return true;
                    else q.push(path[v][i]);
                }
            }
        } 
        return false; 
    }
};
//尝试写了一下DFS
class Solution {
public:
    vector<bool> examine;
    vector<vector<int>> path;
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        examine = vector<bool>(n,false);
        path = vector(n,vector<int>(1,-1));
        for(int i=0;i<graph.size();i++){
            path[graph[i][0]].push_back(graph[i][1]);
        }
        return search(start,target);
    }
     bool search(int start, int target){
        bool result = false;
        for(int i=1;i<path[start].size();i++){
            if(examine[path[start][i]] == false){
                examine[path[start][i]] = true;
                if(path[start][i] == target) return true;
                result = search(path[start][i],target);
                if(result==true) break;
            }
        }
        return result; 
    }  
};
```

