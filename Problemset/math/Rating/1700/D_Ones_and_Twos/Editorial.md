## 📌 Observation on Subarray Sums

In this question, we must notice an important property:

> If there exists a subarray with sum $x$, then it is also possible to obtain a subarray with sum $x - 2$.

---

## 🛠️ Why This Works

Suppose a subarray $S[l, r]$ has sum:
$$S[l, r] = x$$

We can reduce the sum by **2** by trimming elements from the ends. This works because the elements in this specific problem are likely limited to **1s and 2s**.

### Case 1: One End Has 2
If either endpoint is $2$:
* $S[r] = 2 \rightarrow$ remove the right element
* $S[l] = 2 \rightarrow$ remove the left element

**Result:** $S[l, r-1] = x-2$ or $S[l+1, r] = x-2$

### Case 2: Both Ends Are 1
If $S[l] = 1$ and $S[r] = 1$:
Removing both ends reduces the sum by exactly **2**:
$$S[l+1, r-1] = x-2$$

---

## 🔑 Key Insight

Since every reduction changes the sum by $2$, the **parity** of the sum remains unchanged. Therefore, if the total array sum is $S$, we can generate every sum:
$$S, S-2, S-4, S-6, \dots$$

**Conclusion:** Any achievable subarray sum must have the same parity as the original sum.

---

## 📊 Handling Parity in Queries

Let the required sum be $v$.

### 1️⃣ Case 1: Same Parity
If $(S - v) \bmod 2 = 0$, then it is always possible to construct such a subarray.
**✅ Answer: YES**

### 2️⃣ Case 2: Different Parity
If the parity differs, we must remove exactly one **1** from the array to flip the parity. To maximize the remaining sum:

1. Find the **first** occurrence of $1 \rightarrow$ position $x$
2. Find the **last** occurrence of $1 \rightarrow$ position $y$

Now we consider the two largest possible subarrays with the flipped parity:
* **Remove prefix up to $x$:** $S[x+1, n]$
* **Remove suffix from $y$:** $S[1, y-1]$

The maximum possible sum with opposite parity becomes:
$$M = \max(S[x+1, n], S[1, y-1])$$

---

## ✅ Final Decision Rule

If the required sum $v$ satisfies:
$$v \le \max(S[x+1, n], S[1, y-1])$$
**Answer: YES**

Otherwise:
**Answer: NO**