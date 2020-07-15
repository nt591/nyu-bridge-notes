---
title: NYU Bridge to Tandon - Week 2
date: "2020-07-11T11:24:07+0000"
description: C++ data types and expressions, representation internally, mathematical proving techniques
---

## Module 3: Hello Word

Process of executing a program - we'll focus on CPU and main memory (RAM), alongside secondary memory. Both memory devices contain a lot of 0s and 1s, or **bits**. These bits encode information and are collected into collection of 8 bits, called a **byte**. The first byte is located at a physical address of 0, then 1, 2, etc. A sequence of bytes will capture a program. What happens when we execute a program? Program is currently stored in secondary memory. First it gets copied into main memory for faster access to CPU. Then instructions get fetched by CPU one at a time. The CPU has a **program counter** (PC) instruction, initialized to location in memory where program begins. CPU fetches, decodes, executes steps, then increments PC.

We don't program with 0s and 1s, or **machine language**. We use a higher level language like C++, Java, Python, etc etc. We need a way to express closer to human thought and get it translated to machine code. This process of translation is called **compilation** or a build process. This is automated by tools like clang, gcc, javac. 

A sample program that reads two numbers from user and prints the sum: 

```cpp
/*
	intro comments that express the program task eg
	this program takes two numbers from stdin, finds the sum and returns it to stdout
*/
#include <iostream>
using namespace space;

int main() {
	int num1; // holds first input
	int num2; // holds second input
	int sum; // holds sum
	
	cout << "Please enter two numbers separated by a space:" << endl;
	cin >> num1 >> num2;
	
	sum = num1 + num2;
	
	cout << num1 << " + " <<num2 << " = " << sum << endl;
	
	return 0;
}
```

## Problem Solving with C++ sections 1.1-1.4

A set of instructions is called a program. A collection of programs for a computer is what we call the **software** for that computer (OS, Microsoft Office, VS Code). The physical parts are what we call **hardware**. Hardware is "conceptually very simple" but the breadth and complexity of software in a working system is what makes computers complicated and powerful.

#### Hardware

Three classes of computers - PCs, workstations and mainframes. A **PC (personal computer** is what it sounds like - relatively small, designed for one person at a home. A **workstation** is an industrial-strength PC (super powerful Dells). A **mainframe** is even larger that is shared between users and typically requires a support staff.

A **network** is a connection of computers that share resources (printers, for example) and even information). A work network could have multiple PCs, a few mainframes for shared compute, access to shared printers, etc.

The book classifies hardware into **input devices**, **output devices**, **processors**, **main memory** and **secondary memory**. CPU + main memory = integrated compute unit. Everything else connects to those two and operate under their direction.

Input devices - keyboards, mice, maybe voice-operated equipment?

Output devices - monitors, printer, something that CPU can write to externally. Keyboard + monitor = **terminal** (kinda)

Memory - two forms. **Main memory** is a long list of numbers locations called **memory locations** (the number or index is the **address**), each holding a string of **bits**. 8 bits = 1 **byte**. You can store data in a location, then find it by its address. A consecutive chain of bytes can form data types like numbers and letters. One concern - 01000001 is both the letter A and the number 65. How does the computer know what type it is? The book skips over this. We call main memory **Random Access Memory** since randomly accessing a byte location takes constant time. 

**Secondary storage** is for permanent (non volatile) storage. Writing to disk (HDD, SSD, etc) is for **file** storage. Memory access is usually sequential (that is, is this location X? No, go to next place. Is this location A? No, go to next place). 

**Processor** (our central processing unit) is the brain of the computer. The **chip** on the actual hardware item is the processor (buying a Ryzen 3600 means the chip is that, the rest is supportive hardware). The CPU can interpret instructions but those instructions are typically very simple, eg ADD two numbers and store the result somewhere, MUL two nums, MOV an item, JMP to another location.

#### Software

We communicate to hardware via an **operating system** interface (go see my notes from the CS class from Wisconsin). If you tell the computer "run Steam" what really happens is you tell the operating system, which is in charge of coordinating with the hardware to find the file, load into memory, etc.

**Program** = set of instructions. **Data** = conceptualized input to program. Niklaus Wirth said "Algorithms + Data Structures = Programs". 

High level languages vs machine language = covered above. We write closer to human-speak, but computers speak computer-speak. What do we do? We **compile** programs. A compiler takes source code and returns **object code** (a.out, main.o). A **linker** takes your programs object code, combines it with other code needed for some routines (like input/output) and returns a bundled version. Workflow is 

C++ program --> Compiler --> Object Code  --> linker --> Machine code

Object code for other routines ---------------- ^

**Algorithm** a series of precise instructions. A program lays out an algorithm, that is "get a list of names from the user, validate that there is at least 1, initialize a counter, for each name in list increment counter if name starts with X, then return counter."

**Program design** can be broken down into two phases. There is the *problem solving phase* (what data structures, what steps, what algorithms, what optimizatoins) and the *implementation phase* (the writing of code). Quote: "Experience has shown that the two-phase process will produce a correctly working program faster." 

**Object oriented programming** (or OOP) is a method to model your problem domain as a set of interacting objects. Each object can have their own internal algorithm for behavior. We care about OOP because it affords **encapsulation, inheritance and polymorphism** via **classes** (a combination of data and behavior / algorithm).

The **software life cycle** (SLC or SLDC if we insert *development*) is a set of 6 phases:

* Problem definition - analyzing the task
* Object and algorithm design
* Implementation
* Testing
* Maintenance and evolution
* Obsolescence

In C++ a *return statement* is a way of identifying that a program ends, and returning 0 is the usual way of returning successfully. We have **variable declaration** with prefix type annotations in C++ - `int bearCount;`C++ uses `cin` and `cout` for interacting with stdin and stdout. 

We often start a C++ program with `#include <iostream>` - this is called an **include directive**. iostream is joined by the linker at compile time. Directives always begin with the hash #.  C++ allows us to open a namespace with, for example  `using namespace std` which makes all methods in file scope. 

We can compile with `g++` or `clang++` and specify a language standard with the `--std` flag, eg `--std=c++17`.

## Module 4 : Data Types and Expressions - Part 1

We care about **data, expressions and control flow**. Data = types, classes, etc. Expressions = Arithmetic, IO, etc. Control flow = if/else, while, functions, etc. In the above C++ code from module 3, `int num1` is an example of data. `cin` and `cout` are expressions, and we had no control flow. Lines are default ordered sequentially. Everything has a type, because C++ is **strongly typed**. 

The `int` type holds integers. We fix the size to 4 bytes (32 bit ints), and in memory the address of the integer points to the first of the bytes. 32 bit ints means we can store 2^32 or a little north of 2 billion. Can't represent all ints. Numbers are stored in bytes presented in *Two's Complement*. 

Two forms of data - variables and constants. `int x` declares a variable. `6` is a constant, since it cannot be redefined. We call built-in constants **literals** (6 is a literal, we don't need to define it). User-defined or programmer-defined constants look more like `const int MAX = 5;`

Operators are type-constrained. Arithmetic operators like + require ints or floats. Note that division is integer-division, eg 5 / 2 = 2. If we want remainder, we need the **modulo** (or mod) operator. In C++ that would be `5 % 2`.

We can do multiple assignment with `y = x = 7` since the return value of assignment is the righthand side value.

Conventions - camelCase or snake_case? camelCase is more common for C++ so I'll go with that. 

## Module 4 : Data Types and Expressions - Part 2

Floats and doubles are for real numbers (potential fractionals). Also fixed size, floats are 4 bytes and doubles are 8 bytes. Doubles allow us to represent up to 2^64. How do we represent the decimal place? Just gotta learn from [Fabien Sanglard](https://fabiensanglard.net/floating_point_visually_explained/index.html) - the IEEE-754 spec. We call it floating point because the decimal point can "float around". 

We need to represent floats as `6.0f, 0.85f, 3.1415f` etc.  To mark as a float we add an `f`, otherwise it'll be a double. 

Write a program that reads from user the radius of a circle, then calculates and prints the area (radius * radius * PI).

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
 cout << "Enter the radius of your circle: " << endl;

 double radius;
 cin >> radius;
 double area = radius * radius * M_PI;

 cout << "the area of your circle is " << area << endl;

 return 0;
}

```

Sometimes we need **type casting** - when we mix types we need to maintain one. We need to convert the data's representation from one type to another. We type cast with the syntax, `VARIABLE = (newType)VALUE` eg `double y = (double) 6;` or `int x = (int) 3.14f`;

If we mix types in an expression, like `5 / 3.0` then the compiler will try to cast both operands to an appropriate type. This is an **implicit cast** and maintains accuracy, that is int -> double is safe but double -> int is not okay.

## Module 4 : Data Types and Expressions - Part 3

The **char** type is for representing characters. It's stored as 1 byte, since 2^8 (256) values is enough to represent lower case, upper case, digits, symbols. We call these representations the **ASCII values**. ASCII numbers are base-ten values that get converted to binary for storage. 

Write a program that takes a char and returns the ASCII value.

```cpp
#include <iostream>
using namespace std;

int main() {
  char letter;
  cout << "Please input one character." << endl;

  cin >> letter;

  cout << "The ASCII value is " << (int) letter << endl;

  return 0;
}

```

Char literals for C++ are single-quote letters, like `char x = 'a';`. Double quotes are reserved for strings (`std::string`). We can use backslash before chars for special characters, like `\n` for newline. The backslash is called the escape. We can use arithmetic to get the next char like `(char) ('a' + 1)`. We can convert to uppercase as well. Write a char that takes a letter (assume lower case) and returns its upper case letter.

```cpp
#include <iostream>
using namespace std;

int main() {
  
  char lowerCase;

  cout << "Please enter a letter. " << endl;
  cin >> lowerCase;
  
  int asciiCode = lowerCase - 32;
  cout << asciiCode << endl;
  char upperCase = (char)asciiCode;

  cout << "The upper case of your letter is " << upperCase << "." << endl;
  return 0;
}

```

The video uses offset, closer to 

```cpp
#include <iostream>
using namespace std;

int main() {
  
  char lowerCase;

  cout << "Please enter a letter. " << endl;
  cin >> lowerCase;
  
  int offset = 'A' - (int) lowerCase;

  char upperCase = (char) ('A' + offset);

  cout << "The upper case of your letter is " << upperCase << "." << endl;
  return 0;
}

```

The `string` class is not built into C++, but needs the `#include <string>` directive. Representation is a sequence of characters. Literals are defined with double quotes. We can declare `std::string x = "Hello " + "world!"`

## Module 4 : Data Types and Expressions - Part 4

The `bool` data type represents true or false, or boolean logic. Takes 1 byte (not 1 bit) so any non-zero value is true. That is `10000000` and `00001000` and `0110000` are all true, only all-zeroes will be false. Only operators are our usual logic operators. First is **not** or `!`. Next is **conjunction** or **and**, with binary operator `&&`. Last is **disjunction** or **or**, with binary operator `||`.

**Atomic boolean expressions** are true or false. We can use operators to make **compound boolean expressions**. We have arithmetic expressions compared with relational operators: `>, >=, <, <=, ==`.

## Problem Solving with C++ sections 2.1 - 2.3

#### Variables and assignment

We use variables to name and store data. A C++ variable can hold all types of data, from `int`s to `bool`s to custom classes. The data itself is called the variable's **value**. `cin >> variable_name` takes input from stdin and assigns it to the variable on the right side of `>>`. In practice, variables are implemented as memory locations by the compiler. 

The name of the variable is called the **identifier** (we learned this from (Bob Nystrom)[https://craftinginterpreters.com/statements-and-state.html]). Identifiers MUST start with a letter or underscore, and the rest of the characters can be letters, digits or underscore.

```c++
int _ignored; // valid
std::string firstName; // valid
bool 2_fast_2_furious; // invalid
```

**Keywords** or **reserved words** are words disallowed for variable use, eg `class`.

Every variable must be **declared**, and you can declare multiple variables with the same type with commas, like `std::string firstName, lastName;`. The first part of a declaration is a **type name**. Variable declarations are used to let the compiler know how to encode the data and how much memory to allocate.

To give a variable a value, we use **assignment statements**. The parts are the type name, variable identifier, assignment operator, value, and then a semi colon. For example, `int age = 30;`. The value can also be an expression which will get evaluated prior to assignment. For example, `int moonWeight = earthWeight / earthGravity * moonGravity;`. Some values cannot change, like ints. We call these **constants**.

A variable without an assigned value is called an **uninitialized** variable. When variables are uninitialized, their values will be whatever value was in that memory location prior to the program running. That is, if Microsoft Word stuffed some file into that memory location and my uninitialized variable is assigned that location, its value will be a set of bits that correspond to the file data.

An **input stream** is...the stream of input flowing into the program. Okay not a good definition. But specifically, we use the word stream because we don't worry about the source and only act on the incoming data itself. We also have **output streams**.

`cout` uses the insertion operator `<<`. 

An **include directive** looks like `#include <LIBRARY>` and tells the system to use code from that file. Akin to copying the code over into the current file. 

C++ also has **namespaces** and we can open a namespace for local resolution with a **using directive** like `using namespace std;`. Namespaces exist to let methods with the same name not clash.

The backslash operator `\` is to let users enter special characters in strings, such as `\n` for a newline or `\r\n` for "carriage return line feed".

`double` and `float` types allow decimal points but they must be neither the first nor last character (0.6, 1.0, 3.14f). There is a way to format `cout` to return for example 2 decimals with 

```cpp
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
```

When using `cin` to take in multiple inputs, like `cin >> var1 >> var2` the input from stdin must be separated by at least one whitespace.

It's considered good form to **echo the input** or write the input to stdout at some point before the program terminates. This allows the user to validate their input in case of weird or unexpected behavior.

Since doubles and floats have finite space, their values are approximations.

C++11 brought in the `auto` keyword for type inference, used as `auto whatIsThis = 5;`

**Boolean expressions** are expressions that return true or false. Boolean operations are relational operations like ==, >, <=. 

Boolean operators in C++ are the unary ! (not or negation) and equivalency checks.

| Symbol | Meaning|
|---------|---------|
|  ! | Negation, like !ateCheese |
| == | Equality check |
| && | boolean AND, conjunction |
| &#124;&#124; | boolean OR, disjunction |
| > | Greater than |
| >= | Greater than or equals |
| < | Less than |
| <= | Less than or equals |

Boolean logic in C++ follow laws of propositions, eg De Morgan's law says that `!(x && y) == !x || !y`

Precedence rules apply, where unary operators have highest precedence, boolean operators the lowest, everything else falls in the middle.

C++ boolean operation can "short circuit evaluate" - that is, for `x || y` if x is true then y doesn't evaluate, and the whole expression returns true. For `x && y` if x is false, the expression returns false before y evaluates.

C++ will coerce `int`s to work as `bool`s where any non-zero value is true.

**Enum** types are enumerations over constants. If not specified values, they are monotonically increasings ints starting from zero. For example `enum Direction { NORTH, SOUTH, WEST, EAST = 500}` . There is a stronger version called a **strong enum** or **enum class** defined as `enum class Days { Mon, Tues, Wed}` that does not coerce to ints.

## Discrete Math Section 1.11

We create a set of **hypotheses** we assume are true. An **argument** is a series of propositions, each of which are **hypotheses**, followed by a final proposition called the **conclusion**. An argument is **valid** if the conclusion is true when all hypotheses are true, else it is **invalid**. Denotation is:

![hypotheses denotation](./hypotheses.png)
*source: Discrete Math, Rosen*

p1...pn are the hypotheses, and c is the conclusion. The symbol ∴ is read as "therefore". When p1...pn are all true, then the argument is valid. That is if `(p1 ^ p2 ^ (p3 ^ ...pn) --> c` is a tautology then the argument is valid. Order doesn't matter for hypotheses due to commutative law of conjunction. 

The way we prove validity is with truth tables. We look at each in which ALL hypotheses are true. If the conclusion is true in each of those rows, the argument is valid. If there is a row in which all hypotheses are true but the conclusion is false, then the argument is invalid. Consider

(p --> q) ^ (p v q) ∴ q

|  p  |  q  |  p --> q | p v q |
|----|---|---------|------|
|  T  |  T |        T    |    T    |
|  T  |  F |        F    |    T    |
|  F  |  T |        T    |    T    |
|  F  |  F |         T   |    F    |

The only rows in which both hypotheses are true are rows 1 and 3. For both of those rows, q is true, so all the hypotheses are true and the conclusion is true so the argument is valid.

What if we went with the below?

¬p ^ (p --> q) ∴ ¬q

|  p  |  q  |      ¬p     | p --> q |
|----|---|---------|------|
|  T  |  T |        F    |    T    |
|  T  |  F |        F    |    F    |
|  F  |  T |        T    |    T    |
|  F  |  F |         T   |    F    |

The only row in which both hypotheses are true is 3, but the conclusion ¬q yields false so the argument is invalid.

The hypotheses and conclusion can be expressed in English as well, for something like "It is raining today AND if it is not raining then I will not ride my bike, therefore I will ride my bike".

Note that, in English, we might use propositions with known truth values, eg, 7 is an odd number, but the hypothesis MUST be expressed as a proposition over a domain and must be valid for all combinations of hypotheses. 

## Discrete Math Section 1.12

There are **rules of inference** that exist that we can use for hypotheses that we know to be true. Treat the SLASH operator (/) as a newline in a normally formatted argument (newline + conjunction)

| Rule of Inference |     Name     |
|------------------|-------------|
| p / (p --> q) ∴ q  | Modus ponens |
| ¬q / (p --> q) ∴ ¬p | Modus tollens |
| p ∴ p v q  | Addition |
| p ^ q ∴ p | Simplification | 
| p / q ∴ p ^ q | Conjunction |
| p --> q / q --> r ∴p --> r | Hypothetical Syllogism |
| p v q / ¬p ∴ q | Disjunctive Syllogism |
| p v q / ¬p v r ∴ q v r | Resolution | 

The process of applying the ruless of inference and laws of propositional logic is called a **logical proof**. A logical proof consistents of steps of pairing propositions with **justifications**. If the proposition in a step is a hypothesis, the justification is "Hypothesis" else it must follow from a previous step by applying one law of logic or rule of inference.

The structure of a proof is a list of numbered steps, where the left column is either the hypothesis and the right side Hypothesis, or the left side is a substitution and the right a rule of inference and line number representing input.

From the Rosen example

w: It is windy
r: It is raining
c: The game will be canceled

Then solve for 

```
If it is raining or windy or both, the game will be cancelled.
The game is not canceled
________
It is not windy
```

or 

```
(r v w)  --> c
¬c
_______
¬w
```


The table then looks like

| # |    Proposition       |  Rule   |
|--|-------------------|-------|
| 1 | (r ∨ w) → c           | Hypothesis|
| 2 | ¬c           | Hypothesis|
| 3 | ¬(r ∨ w) | Modus Tollens 1, 2 |
| 4 | ¬r ^ ¬w | De Morgan's Law 3 |
| 5 | ¬w ^ ¬r | Commutative 4 |
| 6 | ¬w       | Simplification 5|


## Discrete Math Section 1.13

We can apply the rules of inference to quantified statements, but we need to do so by substituting in one **element** from the domain. Eg "every employee who works hard got a bonus, Linda got a bonus, therefore some employee works hard". When an element has no special distinguishing characteristics from other elements in the domain we call it **arbitrary**. If it can be distinguished in some way, we call it **particular** (eg 3 is odd, so that is a particular element).

If the element is defined in a hypothesis, it is always a particular element and the definition of that element in the proof is labeled "Hypothesis". If an element is introduced for the first time in the proof, the definition is labeled "Element definition" and must specify whether the element is arbitrary or particular.

There are rules called **existential instantiation** and **universal instantiation** to replace a qualified variable with an element of the domain. To replace an element of the domain with a qualified variable we use **existential generalization** and **universal generalization**. This only works for non-nested quantifiers. 

#### Universal instantiation

c is an element (arbitrary or particular)
∀x P(x)
∴ P(c)

"Sam is a student in the class. Every student passed the class. Sam is a student. Therefore Sam passed the class". 

#### Universal Generalization

C is an arbitrary element
P(c)
∴ ∀x P(x)

"Let c be an arbitrary integer. c <= c^2. Therefore all integers are less than or equal to their square"

#### Existential Instantiation

∃x P(x)
∴ (c is a particular element) ∧ P(c)

"There is an integer that is equal to it's square. Therefore, for some C, c == c^2"

*Note: each use of Existential instantiation must define a new element with its own name (e.g., "c" or "d").


#### Existential Generalization

c is an element (arbitrary or particular)
P(c)        
∴ ∃x P(x)	

"Sam is a particular student in the class. Sam completed the assignment. Therefore there exists a student in the class that completed the assignment."

**IMPORTANT** - for every use of existential instantiation, we MUST use a different existential variable letter in order to avoid invalid proofs. EG if we say "c is a particular element" then later if we need another element, we must not use c again.

We can show an argument with quantified statements to be invalid by defining the domain and predicates which makes all hypotheses true but the conclusion false.

## Discrete Math Section 2.1

We want to prove things in mathemtics. A **theorem** is a statement that can be proven to be true. A **proof** consists of a series of steps each of which follows logically from assumptions or previously proven statements, and the final step should be the result of the theorem proving true.  

We might make use of **axioms** or statements we take to be true. A theorem might be something like "Every positive integer is less than or equal to its square."

How do we know where to start when writing proofs? We can apply known patterns to help break the problem down. Often we start by playing with different elements in the domain.

Rewriting the statement into precise mathematical language can help. Most theorems make assertions about all elements in a domain and are therefore universal statements, although the theorem may not explicitly state it as such. The first step is to name a **generic object** and prove the statement for that object. 

For a universal statement, checking every element is known as a **proof by exhaustion**. This is doable for small domains, eg { -1, 0, 1 }. For larger domains, it is easier to invalidate by finding a **counterexample**

## Discrete Math Section 2.2

Many theorems take the form of a conditional where the conclusion follows a set of hypotheses. These can be expressed as p --> c, where p is the conjunction of all hypotheses and c is the conclusion. In a **direct proof** we assume p to be true and the conclusion c is proven as a direct result of the hypotheses.

These hypotheses can also be universally qualified, like "for every integer x, if x is odd then x^2 is even"

## Discrete Math Section 2.3

A **proof by contrapositive** proves a conditional theorem p --> c by showing that ¬c --> ¬p: that is, ¬c is assumed to be true and ¬p is proven as a result of ¬c. An example. Imagine the theorem "For every integer n, if n^2 is odd then n is odd." This can be described with the universal quantifer for the domain of all integers as ∀n (D(n^2) → D(n)) - in other words, assume negative conclusion and show negative hypothesis.

The contrapositive proof starts with an arbitrary n, assumes D(n) is false and proves that D(n^2) is false. Or, ∀n (¬D(n) → ¬D(n^2)). Imagine this example: 3n + 7 is odd therefore n is even. If we prove by contrapositive, we test the case where n is odd. We can describe even numbers as `2k` and odd numbers as `2k + 1`. So if we replace n with the above, we get `3(2k + 1) + 7` which yields `6k + 3 + 7` or `6k + 10` or `2(3k + 5)`, and we said that `2k` is an even number, so if `k = (3k + 5)` then 2k must be even. Therefore we can assert that `3n + 7` is even. 

Another example:

Theorem: For every real number x, if x^3 + 2x + 1 ≤ 0, then x ≤ 0.

1) Negate the conclusion and assume x > 0
2) Since x > 0, 2x > 0 and x^3 > 0
3) Since x^3 > 0 and 2x >0 and 1 > 0, the sum is > 0
4) x^3 + 2x + 1 > 0 therefore the theorem is true

## Discrete Math Section 2.4

A **proof by contradiction** assumes the theorem is false and then tries to find some inconsistency that would lead this to be incorrect.  If t is the statement of the theorem, the proof begins with the assumption ¬t and leads to a conclusion r ∧ ¬r, for some proposition r. If the theorem being proven has the form p → q, then the beginning assumption is p ∧ ¬q which is logically equivalent to ¬(p → q). A proof by contradiction is sometimes called an **indirect proof**

The proof by contrapositive method is a special case of proof by contradiction. 

Example. Proof by contradiction that sqrt(2) is irrational

1) assume the negation, or sqrt(2) is rational
2) Express sqrt(2) as n / d, since it's rational (d != 0 and no integer > 1 can divide into n and d)
3) since `sqrt(2) = n / d` we can square both sides of the equation `2 = n^2 / (d  ^ 2)` and then multiply both sides by `d^2` to get `2d^2 = n^2`
4) Since n^2 can be represented as 2 times some number, we can claim n^2 is even and thus n is even
5) If n is even, then `n = 2k` and if `2k = 2(d^2)` then d^2 must be a multiple of 2 and therefore even
7)  if d^2 is even then d is even
8)  If n and d are even, there exists an integer n that divides into both n and d, so therefore `n / d` cannot be rational so it must be irrational

## Discrete Math Section 2.5

A **proof by cases** takes a univerally quantified statement, breaks it down into classes, and proves an example of each case to be true. Every value in the domain must belong to at least one of the classes. For example, for the theorem "for every integer x, x^2 - x is even" can be proven in two cases: x is odd or x is even.