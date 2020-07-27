---
title: NYU Bridge to Tandon - Week 4
date: "2020-07-27T11:24:07+0000"
description: C++ Control Flow - Iterative Statements (for loops, while loops)
---

## Module 6 - Iterative Statements

To recap, we've covered data, expressions, and basic control flow.

Now we're going to try to count the numbers from 1 to n where n is an input number. So for n = 4,  	return "1 2 3 4". We have no sequential behavior for this. We also can't if-else our way to the solution. Unless we try to make it work for all inputs in the universe (if n = 9999, print 9999,  n -= 1)

We can use a **while** statement to **iterate** over behavior and repeat for some condition. The syntax is 

```cpp
while (CONDITION IS TRUE) {
  // behavior
  // potentially change condition to false
}
```

Let's try our problem again. Given an input positive integer N, cout from 1 to N. How would we do this? Maybe some counter. Start it as 1. Begin looping logic: Is counter > N? Print, increment, repeat.

```cpp
#include <iostream>
using namespace std;
int main () {
	int max;
	cout << "Input a positive integer";
	cin >> max;
	
	int counter = 1;
	while (counter <= max) {
		cout << counter << endl;
		counter++;
	}
	return 0;
}
```

We also **for loops** with a different syntax that looks something like


```cpp
for (INITIALIZE_VARIABLE; CONDITION_CHECK; CHANGE_VARIABLE_VALUE) {}
```

The module calls the first position "increment" but we could add, subtract, divide by 2 (eg binary search) so better to just consider it as a value change.

Now let's solve the same problem:

```cpp
#include <iostream>
using namespace std;
int main () {
	int max;
	cout << "Input a positive integer";
	cin >> max;
	
	for (int counter = 1; counter <= max; counter++) { 
		cout << counter << endl;
	}
	return 0;
}
```

Because for-loops have their variable changing logic declared at the top, the module makes the case it is easier for a programmer to read.

Let's try taking a positive integer, then summing the digits and returning number of digits and sum. eg 375 = sum 15, count 3.

```cpp
#include <iostream>
using namespace std;
int main () {
	int num;
	cout << "Input a positive integer";
	cin >> num;
	int tmp = num;
	int sum = 0;
	int digitCount = 0;
	
	while (num > 0) {
		int onesDigit = tmp % 10;
		sum += onesDigit;
		digitCount++;
		tmp /= 10;
	}
	
	cout << "the sum of the digits of " << num << " is " << sum;
	cout << " and the number of digits is " << digitCount << endl;
	
	return 0;
}
```

Now we can try to average some numbers. Assume user inputs a sequence of grades, return the average. Inputs are number of users, then space-separated grades, then return class average.

```cpp
#include <iostream>
using namespace std;
int main () {
	int studentCount;
	cout << "Please enter the number of students: "
	cin >> studentCount;
	
	float sum = 0f;
	cout << "Please enter a space-separated list of grades";
	for (int i = 0; i > studentCount; i++) {
		float grade;
		cin >> grade;
		sum += grade;
	}
	
	float average = sum / studentCount;
	
	cout << "The average grade of the class is: " << average << endl;
	return 0;
}
```


Let's enter a caveat. Rather than ask for number of students, lets take a stream of integers and use the value -1 as a **terminal value** to denote that it's over. The module uses this idea of a **flag variable** initialized to the **down** (off) position and **raise** it when a condition is hit

```cpp
#include <iostream>
using namespace std;
int main () {
	int studentCount;
	float sum = 0f;
	bool seenTerminalValue = false;
	cout << "Please enter a space-separated list of grades and finish with -1";
	
	while (!seenTerminalValue) {
		cin >> currDigit;
		if (currDigit == -1) {
			seenTerminalValue = true;
		} else {
			sum += currDigit;
			studentCount++;
		}
	}
	
	float average = sum / studentCount;
	
	cout << "The average grade of the class is: " << average << endl;
	return 0;
}
```


## Problem Solving with C++ Section 2.4 - 2.5

A **while loop** has a **condition** and a **body**. The body is a (series of) statement(s) that get executed *while* the condition is true. Therefore there needs to be some adjustments that could change the condition to false, or get closer to false. That is, "print x while x is less than 4" means we need to make changes to x on each iteration to get closer to 4. Each repetition is called an **iteration**. Sample code

```cpp
while (countDown > 0) {
	std::cout << countDown << std::endl;
	countDown--;
}
```

If a loop body has a single statement, braces can be omitted;

```cpp
while (countDown > 0)  countDown--;
```

I just introduced the **unary** (that is, one argument) operator for decrementing. There are unary increment and decrements. The book doesn't cover this yet, but they can be **prefix** (`--count`) or **postfix** (`count++`) which changes precedence and execution time. Postfix has lower precedence than almost everything else, so you can do stuff like

```cpp
	sum += counter++;
```

Which says "add counter to sum, then increment counter"

```cpp
	sum += ++counter;
```

says "increment counter, then add to sum"

**Pitfall** - since a while loop doesn't terminate until the condition is false, and the user is on the hook for condition adjustments, it's easy to forget to change a variable or condition, and get stuck in an infinite loop.

Let's write a program to return how many periods of time it takes for a balance of 50 dollars and 2% interest to hit 100 dollars or more

```cpp
int main() {
	double balance = 50.0;
	int periods = 0;
	
	while (balance < 100) {
		balance = balance * 1.02;
		periods++;
	}
	
	std::cout << periods;
	return 0;
}
```

Indenting - do it in loops to express semantics and add readability. I'm using braces a la K&R style (that is, open brace on same line as condition).

Comments - line comments with `//` and block comments with `/* */`

Constants  - all caps,  declared as `const` please and thank you.

## Problem Solving with C++ Section 3.3

A **loop** is a construct to repeat a sequence of statements. We also introduce `do...while` loops which will FIRST execute the loop, THEN check condition. This changes the behavior to make sure the loop runs at least once.

```cpp
// first
int count = 0
while (count != 0) doStudd; // never runs

do {
	doStuff
} while (count != 0) // runs once
```

Since our condition is checking for some match, it must be a boolean expression. Something that can be evaluated as false, otherwise we get stuck in a loop forever.

We introduce **postfix** vs **prefix** incrementing - see above for clarity.

For problems where we need sequential integers or values (eg summing nums from 1 to N, array access) we can use a **for-loop**

The book refers to the structure of a for-loop as **(Initialization_Action; Boolean_Expression; Update_Action)** - the language of Update_Action is clearer that it's not just incrementing, but some sort of variable adjustment. 

The initialized variable has block scope, so it isn't accessible outside of a loop. Additionally any variables declared inside the body will be inaccessible outside. As a result, if your loop needs to impact the outside world you'll need to declare it outside the loop.

Be careful of semis

```cpp
for (int x = 0; x < 10; x++);
	doStuff()
```

This will terminate before doStuff happens in the loop so it'll only run once. It makes our for-loop a **null statement** which does nothing.

Choose for loops when the variable will change by a fixed amount. Else, a while loop might be easier to read.

We can use the `break` keyword to end a loop when we reach some terminal value or error state.

```cpp

int main() {
	std::cout << "please enter a list of positive values followed by -1" << endl;
	int x;
	
	while (true) {
		std::cin >> x;
		if (x < 0) break;
		
		std: cout << "You entered: " << x << endl;
	}
	
	return 0;
	
}
```

A break will only break the innermost (nearest) loop. So for nested loops we can run back up

```cpp
for (int x = 0; x < 10; x++) {
	for (int y = 0; y < 10; y++) {
		if (x == y) break;
		std::cout << y;
	}
}
```


## Problem Solving with C++ Section 3.4

When we design a loop we need to handle:

* The body
* The initialization
* The terminating condition

A for loop can be expressed in pseudocode as 

* repeat the following THIS_MANY times
	* take a new value
	* do something

We can terminate with the following conditions

**List headed by size** - take some value N and run N times from 1 to N

**Ask before iterating** - take an input on each loop run and determine if we keep going or stop

**Sentinel value** - a value marked as the flag to terminate. AKA "give me a list of numbers and when you're done, send me -1". Reading from files sends a terminal EOF to determine that the file is done.

**Count-controlled loop** - just run COUNT times

**Flag condition** - set a flag to false, loop until you have a reason to set to true. The trap is that you might never toggle the flag.

**Nested loops** - sometimes each value in a list needs its own looping behavior. Imagine the following pseudocode:

```cpp
for birdWatcher in birdWatchers
	for bird in birdWatcher.photoAlbum
		cout << bird
```

**Debugging** - gotta be careful of **off by one** errors, **infinite loops**, **failed equality** (eg comparing two doubles, since approximations can introduce rounding error).

When we test, we should use values that can invalidate our assumptions about the world in order to handle gracefully. eg if we ask a user for a list of positive ints and they send a negative, does this break our looping exit condition?