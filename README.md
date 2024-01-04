# Algorithm Design and Analysis Laboratory

本仓库抄自 灵茶山艾府 💭💡🎈[算法竞赛模板库](https://github.com/EndlessCheng/codeforces-go)

## Algorithm Catalog

- [位运算](template/bitwise_operations.md)
- 数据结构
  - [堆（优先队列） heap.cpp](copypasta/cpp/heap.cpp)
  - [并查集 union_find.cpp](copypasta/cpp/union_find.cpp)
  - [树状数组 fenwick_tree.cpp](copypasta/cpp/fenwick_tree.cpp)
- [字符串 strings.cpp](copypasta/cpp/strings.cpp)
  - KMP
  - [字典树 trie.cpp](copypasta/cpp/trie.cpp)
  - [异或字典树 trie01.cpp](copypasta/cpp/trie01.cpp)

- 数学
  - [数论 math.cpp](copypasta/cpp/math.cpp)
    - 埃氏筛（埃拉托斯特尼筛法）

- [动态规划 dp.cpp](copypasta/cpp/dp.cpp)
  - 背包
    
    - 0-1背包

  - 线性DP
    
    - 最大子段和
    - LCS（最长公共子序列）
  - 树形DP
- [图论 graph.cpp](copypasta/cpp/graph.cpp)
  - 欧拉路径
    - 有向图

  - 最短路
    - Dijkstra
    - SPFA（队列优化的 Bellman-Fords）
    - Floyd-Warshall
  - 最小生成树（MST）
    - Kruskal
    - Prim
  - 二分图判定（染色）
  - 二分图最大匹配
    - 匈牙利算法
  - 拓扑排序
  - 强连通分量（SCC）
    - Kosaraju

  - 基环树

- 其他

  - [二分 sort.cpp](copypasta/cpp/sort.cpp)
    - 整体二分
    - 归并排序
    
  - [搜索 search.cpp](copypasta/cpp/search.cpp)
    - 康托展开
  - [基础算法 common.cpp](copypasta/cpp/common.cpp)

## Examination

滚动数组不考

### Written test

考的都是ppt

不会考内存优化

可以当数据结构复习

直接给代码的不考

图多的容易考

### Online test

stl

枚举

搜索（理论不好考）

图论

## Problems

### C++字符串输入问题

`cin >> string`无法用来判断是否输入空行从而退出循环。使用`getline(cin, string)`配合`string.empty()`判断输入的空行。