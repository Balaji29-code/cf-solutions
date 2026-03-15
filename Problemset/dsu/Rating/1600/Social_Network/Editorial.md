# Editorial: Maximizing Acquaintances Problem

## Problem Overview

We are given **n persons**, initially unfamiliar with each other, and **d conditions**. Each condition specifies that a particular pair of people must be connected, either directly or indirectly.  

For each **i** from 1 to **d**, we are asked to output the **maximum number of acquaintances any person can have**, assuming we perform **exactly i introductions** that satisfy all conditions from 1 to i.  

> Note: For every i, the graph of introductions is considered fresh. Each condition must be satisfied, and additional introductions can be made if allowed.

---

## Key Observations

1. **Connected Components:**
   - Initially, every person is in their own isolated group.
   - Introductions between two people merge their groups into one larger group.
   - Within a connected group, a person can know everyone else in that group.  

   Therefore, the **maximum acquaintances a person can have in a group** is: max_acquaintances = size_of_group - 1

2. **Redundant Introductions (Extra Edges):**
- Sometimes, a condition requires two people who are already connected.  
  In this case, introducing them counts as a "redundant edge".
- These redundant edges can be used **strategically** to merge other components, increasing the size of the largest connected group, and thus increasing the maximum possible acquaintances.

3. **Independent Queries:**
- Each step i is independent: we assume the graph is empty at the start and consider only the first i conditions.  
- This requires us to carefully track connected groups and extra edges at each step.

---

## Solution Approach

1. **Track Connectivity:**
- Use a data structure like a **Disjoint Set Union (DSU)** to efficiently maintain connected groups as introductions happen.
- For each introduction, merge the two groups. If they are already connected, count it as a redundant edge.

2. **Maximize Acquaintances:**
- After processing the first i conditions:
  1. Collect the sizes of all current groups (connected components).
  2. Sort these sizes in descending order.
  3. Use the largest `1 + number_of_redundant_edges` groups to compute the total number of people one could be connected to.  
     - The idea is that redundant edges allow us to merge extra groups.
  4. Subtract 1 to get the maximum acquaintances of a single person (since a person cannot be acquainted with themselves).

3. **Step-by-step:**
- For each condition:
  1. Merge the two specified people.
  2. Update the count of redundant edges.
  3. Calculate the maximum possible acquaintances using the largest components plus extra edges.

---

## Complexity

- **DSU operations** (find and merge) are nearly O(1) amortized with path compression and union by size/rank.
- Sorting component sizes at each step gives **O(n log n)** per condition, resulting in **O(d * n log n)** overall.
- This is efficient for typical competitive programming constraints (n, d ≤ 10^3–10^4).

---