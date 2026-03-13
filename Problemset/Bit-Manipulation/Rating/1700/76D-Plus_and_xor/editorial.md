## 📌 Observation on Difficulty

I was a bit surprised that this problem is rated **1700**. Conceptually, it feels closer to a **1300-level** problem once the key identity is known.

However, there is a small catch involving bit overlap, which likely explains the higher rating.

---

## 🔑 Key Identity

We use the well-known identity:

x + y = (x ⊕ y) + 2 · (x AND y)

Where:
- ⊕ → XOR operation  
- AND → Bitwise AND operation  

---

## 📘 Given

x + y = A  
x ⊕ y = B

---

## 🧮 Step 1: Compute (x AND y)

Substitute the identity:

A = B + 2 · (x AND y)

So,

x AND y = (A − B) / 2

---

## 🎯 Step 2: Find the Minimum x

The smallest possible value of x that satisfies the above is:

x = (A − B) / 2

---

## ⚠️ Validity Conditions

Before computing the answer, we must check some constraints.

### 1️⃣ Non-negative Difference

A − B ≥ 0

If A < B, no solution exists.

---

### 2️⃣ Even Difference

(A − B) % 2 = 0

If the difference is odd, the AND result cannot be an integer.

---

### 3️⃣ Bit Overlap Check

The AND result and XOR result cannot share common bits.

So we must ensure:

(x AND B) = 0

If this condition fails, the construction is impossible.

---

## 🔎 Step 3: Compute y

Using the XOR property:

y = x ⊕ B