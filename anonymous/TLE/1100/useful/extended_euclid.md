I'll explain the Extended Euclidean Algorithm step by step with clear mathematical notation.

The Extended Euclidean Algorithm finds the GCD (Greatest Common Divisor) of two numbers $$a$$ and $$b$$, AND also finds the coefficients $$x$$ and $$y$$ that satisfy:

$$ax + by = \gcd(a,b)$$

Let's solve it step by step:

1) The equation form is:
   $$ax + by = d$$ where $$d = \gcd(a,b)$$

2) Let's work through an example with $$a=48$$ and $$b=18$$

Step 1: Set up the division steps:
```
48 = 2 × 18 + 12    (First division)
18 = 1 × 12 + 6     (Second division)
12 = 2 × 6 + 0      (Third division)
```

Step 2: Work backwards to express GCD (6) in terms of original numbers:

From second division:
$$6 = 18 - 1 × 12$$

Substitute 12 from first division:
$$12 = 48 - 2 × 18$$

Therefore:
$$6 = 18 - 1 × (48 - 2 × 18)$$
$$6 = 18 - 48 + 2 × 18$$
$$6 = 3 × 18 - 48$$
$$6 = -1 × 48 + 3 × 18$$

So we found:
$$-1 × 48 + 3 × 18 = 6$$

Therefore:
- $$x = -1$$
- $$y = 3$$
- $$\gcd(48,18) = 6$$

To verify: $$48(-1) + 18(3) = -48 + 54 = 6$$

General Algorithm:
1) Perform regular Euclidean division steps
2) Keep track of quotients
3) Work backwards substituting each remainder
4) Collect coefficients of original numbers

Key Applications:
1) Finding multiplicative inverses in modular arithmetic
2) Solving linear Diophantine equations
3) Chinese Remainder Theorem
4) Public key cryptography (like RSA)

Would you like me to show another example with different numbers or explain one of these applications in detail?