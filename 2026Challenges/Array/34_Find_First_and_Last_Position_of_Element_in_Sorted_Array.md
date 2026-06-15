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
