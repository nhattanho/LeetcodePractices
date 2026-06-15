# 34. Find First and Last Position of Element in Sorted Array

> **LeetCode:** [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)  
> **Difficulty:** Medium | **Tags:** Array, Binary Search

---

## Step 1: Clarify the Problem

We are given:

- `nums` = sorted array
- `target` = value

Need to return `[first_index, last_index]` where `target` appears.

**Example:**

```text
nums   = [5, 7, 7, 8, 8, 10]
target = 8
Answer = [3, 4]
```

If `target` doesn't exist: `[-1, -1]`

**Important requirement:** **O(log n)**

Since the array is sorted, this immediately suggests **Binary Search**.

---

## Step 2: Think About Brute Force First

A common interview approach: start with the straightforward solution.

Scan entire array:

```text
first = -1
last  = -1

for each element:
    if nums[i] == target:
        update first
        update last
```

| | |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

**Problem:** Requirement is O(log n) — brute force is unacceptable.

---

## Step 3: Use Binary Search

Notice: array is sorted. Binary search can find `target` in **O(log n)**.

However, normal binary search only finds **one** occurrence.

```text
[5, 7, 7, 8, 8, 10]
```

`mid` may find index 3, but we still need:

- first occurrence = 3
- last occurrence  = 4

Finding one occurrence is not enough.

---

## Step 4: Key Insight

We actually need **two different searches**:

1. **Leftmost occurrence**
2. **Rightmost occurrence**

### Visual Example

```text
Index: 0  1  2  3  4  5
Value: 5  7  7  8  8  10
                  ^
               target
```

We want **first 8** and **last 8** — these are slightly different binary searches.

---

## Step 5: Find Left Boundary

**Idea:** When we find `target` (`nums[mid] == target`), don't stop. Instead:

1. Record answer
2. Continue searching **LEFT** — there may be another `target` earlier

### Example: `[5, 7, 7, 8, 8, 10]` — searching first 8

**Iteration 1**

```text
l = 0, r = 5
mid = 2, nums[mid] = 7  → need larger value
l = 3
```

**Iteration 2**

```text
l = 3, r = 5
mid = 4, nums[mid] = 8  → found target
answer = 4
continue left: r = mid - 1 = 3
```

**Iteration 3**

```text
l = 3, r = 3
mid = 3, nums[mid] = 8  → found again
answer = 3
continue left: r = 2
```

**Result:** `first = 3`

---

## Step 6: Find Right Boundary

Same idea. When `target` found:

1. `answer = mid`
2. Continue searching **RIGHT** → `l = mid + 1`

### Example

```text
mid = 4  → found, answer = 4
search right: l = 5
no more targets
```

**Result:** `last = 4`

---

## Step 7: Separate Helper Function

A good interviewer-friendly design:

- `findFirst()`
- `findLast()`

Each performs a modified binary search. This keeps code simple and readable.

---

## Step 8: Pseudocode

### First Occurrence

```text
ans = -1

while l <= r:
    mid = ...

    if nums[mid] == target:
        ans = mid
        r = mid - 1
    else if nums[mid] < target:
        l = mid + 1
    else:
        r = mid - 1

return ans
```

### Last Occurrence

```text
ans = -1

while l <= r:
    mid = ...

    if nums[mid] == target:
        ans = mid
        l = mid + 1
    else if nums[mid] < target:
        l = mid + 1
    else:
        r = mid - 1

return ans
```

---

## Step 9: Full C++ Solution

```cpp
class Solution
{
public:
    int findFirst(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int answer = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                answer = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return answer;
    }

    int findLast(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int answer = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                answer = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return answer;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        return {
            findFirst(nums, target),
            findLast(nums, target)
        };
    }
};
```

---

## Step 10: Complexity Analysis

| | |
|---|---|
| **Time** | O(log n) — two binary searches, still O(log n) |
| **Space** | O(1) |

### Why not O(k log n)?

A common doubt: if `target` appears **k** times, don't we need **k** passes, each costing O(log n)?

**No** — `findFirst` / `findLast` each run **one** `while` loop, not k separate binary searches.

When `nums[mid] == target`:

- `findFirst` → `right = mid - 1` (keep squeezing left)
- `findLast`  → `left = mid + 1`  (keep squeezing right)

Each loop iteration **shrinks the search range**. You are not re-starting binary search from scratch for every duplicate.

**Trace:** `nums = [8, 8, 8, 8, 8, 8, 8, 8]`, find last 8 (n = 8, k = 8)

```text
Iter 1: l=0, r=7, mid=3 → found, ans=3, l=4
Iter 2: l=4, r=7, mid=5 → found, ans=5, l=6
Iter 3: l=6, r=7, mid=6 → found, ans=6, l=7
Iter 4: l=7, r=7, mid=7 → found, ans=7, l=8
Done in 4 iterations — not 8
```

Even with k = n (all elements equal `target`), iterations stay **O(log n)**.

| Approach | Time | Why |
|----------|------|-----|
| `findFirst` / `findLast` | **O(log n)** | Single loop; range halves or advances each iteration |
| Recursive `findPos` (below) | **O(k log n)** | One BS call per occurrence found, then recurse left & right |
| Linear scan after one BS | **O(k)** or **O(n)** | Walk through every duplicate |

The O(k log n) concern applies to the **recursive alternative** in this doc — not to the boundary-search version.

---

## Follow-up: Even Better Interview Discussion

A senior-level candidate may mention: we can generalize this using `lower_bound` and `upper_bound` concepts.

| Concept | Meaning |
|---------|---------|
| `lower_bound` | First element **≥** target |
| `upper_bound` | First element **>** target |

- **First occurrence:** `lower_bound(nums.begin(), nums.end(), target)`
- **Last occurrence:** `upper_bound(nums.begin(), nums.end(), target) - 1`

### STL Solution

```cpp
vector<int> searchRange(vector<int>& nums, int target)
{
    auto first = lower_bound(nums.begin(), nums.end(), target);

    if (first == nums.end() || *first != target)
        return {-1, -1};

    auto last = upper_bound(nums.begin(), nums.end(), target);

    return {
        static_cast<int>(first - nums.begin()),
        static_cast<int>(last - nums.begin() - 1)
    };
}
```

This demonstrates that you understand the deeper concept behind binary search — **boundaries** rather than just memorizing a LeetCode solution. Many interviewers view that explanation as a sign of real understanding.

---

## Alternative Solution: Recursive Binary Search

**Idea:** Find one occurrence with standard binary search, then recursively search the left and right halves to collect all matching indices. Return the first and last from the collected results.

| | |
|---|---|
| **Time** | O(k log n) worst case — k = number of `target` occurrences |
| **Space** | O(k) for `res`, plus O(log n) recursion stack |

```cpp
class Solution {
public:
    vector<int> res;

    int findPos(int left, int right, vector<int>& nums, int target)
    {
        if (left > right) return -1;

        bool found = false;
        int mid = -1;
        int temp = -1;

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (nums[mid] == target)
            {
                found = true;
                break;
            }

            if (nums[mid] < target) left = mid + 1;
            if (nums[mid] > target) right = mid - 1;
        }

        if (!found) return -1;

        temp = findPos(left, mid - 1, nums, target);
        if (temp != -1) res.push_back(temp);

        res.push_back(mid);

        temp = findPos(mid + 1, right, nums, target);
        if (temp != -1) res.push_back(temp);

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1;

        findPos(left, right, nums, target);

        if (res.size() == 0) return {-1, -1};

        return {res[0], res[res.size() - 1]};
    }
};
```

> **Note:** This works but is less efficient than the two-pass boundary search when many duplicates exist. Prefer `findFirst` / `findLast` or `lower_bound` / `upper_bound` for the required O(log n) guarantee.