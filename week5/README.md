---
title: NYU Bridge to Tandon - Week 5
date: "2020-08-02T11:24:07+0000"
description: Functions in discrete mathematics
---

## Discrete Math Section 4.1

We understand sets, which are unordered unique collections of items. A **function** is a mapping from one set to another. Common functions in mathemetics are concerned with numbers, such as the function x^2 which takes a set of integers and maps each value to another value in a set of integers. We can also think about sets of tasks, or abstractions in general. For example, if we were to take the set of all students and assign them to study groups, that would be a function. 

A function from X to Y can also be viewed as a subset of X x Y (that is, the Cartesian product) since a function will give is pairs of values from X and Y. We can more formally define this as X × Y: (x, y) ∈ f if f maps x to y. If X and Y are the same set, then f is a subset of X x X.

Strictly, for a function f that maps X to Y, for every element x ∈ X there is EXACTLY ONE y ∈ Y for which (x, y) ∈ f. Another way, functions cannot map a value in X to many Ys. If the function is x^2, 3^2 cannot have two or more possible values.

We use the notation f: X → Y where we call X the **domain** and Y the **target**. We can also denote as f(x) = y

For a function f mapping X to Y and a finite set X, the function f can be specified as the set of pairs mapping X to Y. We can also use a graphical representation called an **arrow diagram** which just draws lines from a left column showing all values of X to a right column showing all values of Y. A line will be drawn from  x ∈ X to some y ∈ Y only if (x, y) ∈ f. This also means only one arrow can be drawn OUT of an element in the domain.

We say that an element in y is in the **range** of the function if and only if there is a line drawn from some value x to that element. Put another way, every y in the set of f is in range, but not every element in Y is in range. How?

Imagine the set X = {-1, 0, 1} and Y = {-1, 0, 1} and the function x^2. If you square every number in X, you get the set {0, 1} (-1 squared is 1). Therefore, the range of the function is smaller than the target of the function.

Concretely: Range of f = { y: (x, y) ∈ f, for some x ∈ X }

A function definition is not just its behavior. A definition is not complete until the domain of f is specified

f(x) = x^2 **incomplete**

f: **N** -> **N**, where f(x) = x^2 **complete**

We say that two functions f and g are **equal** or have **function equality** if and only if f and g have the same domain and target, AND for every x ∈ X, f(x) = g(x). If this holds then we say f = g.

## Discrete Math Section 4.2

A function is called **one-to-one** or **injective** if, formally, x1 ≠ x2 implies that f(x1) ≠ f(x2). An example, f(x) = x + 1. For any two values of x called **a** and **b**, f(a) ≠ f(b). That is, f maps different elements in X to different elements in Y.

A function is called **onto** or **surjective** if, formally, the range of f is equal to the target Y. That is, for every y ∈ Y, there is an x ∈ X such that f(x) = y. An example, f: **R** -> **R**, where f(x) = x + 1. For EVERY real number, there exists a number x such that x + 1 = y. 

If a function is both injective and surjective, we call it **bijective**. To repeat, a bijective function is one where both no two x values map to the same y AND every y in the target is reached by some x. A bijective function is also called a **bijection** or a **one-to-one correspondence**.

If we know whether a function is one-to-one or onto, then we can make inferences about the relative sizes of the domain and targets.

If f: D → T is onto, then for every element in the target, there is at least one element in the domain: |D| ≥ |T|. That is, if every element in T is reachable, we know that at the least ONE element in D must be able to reach it. Therefore, the cardinality of D must be at LEAST equal to T. It's possible multiple elements in D reach an element in T, so |D| ≥ |T|.

If f: D → T is one-to-one, then for every element in the domain, there is at least one element in the target: |D| ≤ |T|. That is, if every element in D has a unique mapping in T, then there must be at LEAST the same number of elements in both. Since it's possible there are unreachable elements in T in a one-to-one function, it's possible that the cardinality of T is greater. Thus |D| ≤ |T|

If f: D → T is a bijection, then f is one-to-one and onto: |D| ≤ |T| and |D| ≥ |T|, which implies that |D| = |T|.

If we know these rules, then we can make other inferences. For example, if we have a set of unknown size, and we want to count the elements we can do so by defining a bijection between this set and another set that we DO know the size of.

## Discrete Math Section 4.3

If a function f: X -> Y is a bijection (a function that has a unique y for every x and every y value in Y is reached) then the **inverse** of f is obtained by exchanging the first and second entries of each pair in f. We denote the inverse of f as f^-1 (wow that's annoying).

f^-1 = { (y, x) : (x, y) ∈ f }

Or, the inverse function f^-1 is the set of all (y, x) such that (x, y) exists in f.

Reversing each pair does not always result in a well-defined function (no x has multiple outputs, the domain and target are known). Therefore some functions just don't have an inverse. A function f: X → Y has an inverse if and only if reversing each pair in f results in a well-defined function from Y to X. f^-1 is a well-defined function if every element in Y is mapped to exactly one element in X.

Put another way, if the range of f has elements with multiple incoming arrows (that is, the function f is not one-to-one) then the inverse is not valid.

**A function f has an inverse if and only if f is a bijection.**

## Discrete Math Section 4.4

The process of applying a function to the result of another another function is called **composition**. For example. Let f be the function that determines what a person orders at Mcdonalds. Let g be the function that determines how long it takes to eat that order. g(f(Nikhil)) is how long it takes me to each 10 chicken McNuggets.

We use the character `o` to denote composition. That is if f: X --> Y and g: Y --> Z, (g o f): X --> Z. Note that composition is right to left, since it's akin to unwrapping parentheses. For all x in X, (g o f) (x) = g(f(x)).

We can compose multiple functions.

The **identity function** is the function defined f(x) = x, or the function that just returns the same element given. The identity function on A, denoted Ia: A → A, is defined as Ia(a) = a, for all a ∈ A. (Ia is I subscript A).

If a function f has an inverse, then composing f and its inverse yields the identity function. That is, if f(x) = x + 1, the inverse is f^-1(x) = x-1. Therefore (f o f^-1)(x) = x



