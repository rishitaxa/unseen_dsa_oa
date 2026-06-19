/*## Problem Statement

You are given an **undirected tree** consisting of `N` nodes rooted at node `1`. Each node `i` has an integer value `A[i]`.

You may perform the following operation **at most `K` times**:

* Choose any **leaf node** (a node having no children except its parent).
* Disconnect it from its current parent.
* Reattach it to **any other node** in the tree.

After performing all operations, replace the value of every node by the **sum of values of all nodes present in its subtree (including itself)**.

Your task is to determine the **minimum possible sum of the final values of all nodes**.

---

## Input Format

* First line contains an integer `T` — number of test cases.
* For each test case:

  * First line contains two integers `N` and `K`.
  * Second line contains `N` integers `A[1], A[2], ..., A[N]`.
  * The next `N - 1` lines contain two integers `u` and `v`, representing an edge between nodes `u` and `v`.

---

## Output Format

For each test case, print a single integer — the minimum possible sum of all node values after performing at most `K` operations optimally.

---

## Constraints

* `1 ≤ T ≤ 10`
* `1 ≤ N ≤ 2 × 10^5`
* `0 ≤ K ≤ N`
* `−10^9 ≤ A[i] ≤ 10^9`
* Sum of `N` over all test cases does not exceed `2 × 10^5`.

---

## Key Observation (Story → Code)

* In the final subtree-sum array, the value `A[i]` gets counted once for every ancestor of node `i` (including itself).
* Therefore,

[
\text{Answer}=\sum_{i=1}^{N} A[i]\times \text{depth}(i)
]

where `depth(root) = 1`.

* Moving a leaf only changes **its own depth**.
* Increasing the depth of a node by `d` changes the answer by

[
A[i]\times d
]

* Hence:

  * Negative values should be pushed as deep as possible.
  * Positive values should not be moved deeper.
  * Use a **leaf-peeling process (degree = 1 nodes)** and a **min-heap on `A[i]`** to greedily assign larger extra depths to the most negative available leaves.
*/

long long minimizeValue(
    int n,
    int k,
    vector<long long>& A,
    vector<vector<int>>& adj)
{
    g = adj;

    parent.assign(n + 1, 0);
    level.assign(n + 1, 0);

    dfs(1, 0);

    long long ans = 0;
    vector<int> deg(n + 1);

    for (int i = 1; i <= n; i++)
    {
        deg[i] = g[i].size();
        ans += A[i] * level[i];
    }

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    for (int i = 2; i <= n; i++)
    {
        if (deg[i] == 1)
            pq.push({A[i], i});
    }

    int extraDepth = 0;

    while (k-- && !pq.empty())
    {
        auto [val, u] = pq.top();
        pq.pop();

        if (val >= 0)
            break;

        extraDepth++;
        ans += val * extraDepth;

        int p = parent[u];
        deg[p]--;

        if (p != 1 && deg[p] == 1)
            pq.push({A[p], p});
    }

    return ans;
}