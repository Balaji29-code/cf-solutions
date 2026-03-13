## 📌 Observation on Difficulty

I was a bit surprised that this problem is rated 1700. Conceptually, it feels closer to a 1300-level problem once the key identity is known.

However, there is a small catch involving bit overlap, which likely explains the higher rating.

---

## 🔑 Key Idea

We use the well-known identity:

$$
x + y = (x \oplus y) + 2 \cdot (x & y)
$$

Where:

- $\oplus$ → XOR operation  
- $&$ → AND operation  

---

## 📘 Given

$$
x + y = A
$$

$$
x \oplus y = B
$$

---

## 🧮 Step 1: Compute $x & y$

Substitute the identity:

$$
A = B + 2 \cdot (x & y)
$$

So,

$$
x & y = \frac{A - B}{2}
$$

---

## 🎯 Step 2: Find the Minimum $x$

The smallest possible value of $x$ that satisfies the above is:

$$
x = \frac{A - B}{2}
$$

---

## ⚠️ Validity Conditions

Before computing the answer, we must check some constraints.

### 1️⃣ Non-negative Difference

$$
A - B \ge 0
$$

If $A < B$, no solution exists.

---

### 2️⃣ Even Difference

$$
(A - B) \bmod 2 = 0
$$

If the difference is odd, $(x & y)$ cannot be an integer.

---

### 3️⃣ Bit Overlap Check

The AND result and XOR result cannot share common bits.

So we must ensure:

$$
(x & B) = 0
$$

If this condition fails, the construction is impossible.

---

## 🔎 Step 3: Compute $y$

Using the XOR property:

$$
y = x \oplu