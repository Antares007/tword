### Grammar Machine: Two Poles of Programming

## Problem

A tree does not grow without roots.

In most machine languages, the control flow of *language rules*
(grammar, interpretation) is entangled with the control flow of *actions*
(effects, execution).

As languages evolve, this entanglement grows:
small and cute at first,
then expanded into incidental state and committee-approved control flow,
owned by a few.

The reason is simple:
the evolution of roots (rules) and actions is coupled.

## Road to a Solution

Today, at the level of execution, all computing paradigms can be logically boiled down to a “one linear stack managed return-value oriented composition paradigm.”

The execution goes step by step, followed by a predefined continuation. After the instructions' core operation, the next step is the *fetch_decode_execute(PC)* step.

“nop” instruction will add its width value to the program counter to calculate the next PC.

“ret” instruction within its core operation will pop PC from the stack.

“if” and others will do something similar to resolve ambiguity locally,

But “div” is different; it chooses to resolve ambiguity differently. It depends on the globally defined structural invariant within the machine. i.e., the machine defines possible continuations within its bounds.

We can propose that a step is a machine, and a machine is a step to define ambigious step.

An ambiguous step defines the bounded space of admissible continuations, i.e. machine.

Ambiguity is a structure, not an error, and it is composable within the Step by resolving or carrying it forward.

We can directly specify the copy operator (https://github.com/Antares007/t-machine/blob/main/godel_copy.c) into machines controll flow graph, i.e., in the systems language without tables/data. “s1”, “s2”, …, “s5” are ambiguous steps, tiny machines, and are using data (o-tape, s-head) to choose. They are defining admissible continuations and, at the same time, are primary choosers.

We can go further and create more sophisticated (https://github.com/Antares007/tword) examples to divide ambiguous systems, such as grammar.

We can have grammar rules defined as tail recursive controll flow graphs directly rooted in the system's language and define a traversal algorithm as separatly evolutionable control flow graph too.

We can kick-start the dancing process as:

The A step defines admissible continuations and chooses one defined by the B step. The chosen continuation of the B step will define its admissible continuations and will choose the continuation defined by the A step.

I’am self tought programmer lack language of academic reasoning.

I’am more like a monkey on a tree, learning primarily from nature, but the division of amoeba seems to me like a split of one diagonal linear logic into orthogonal spaces, with the possibility of having many lines of logic.

So all of you greats, grounded in the soil of math, HELP.

## Choice Machine

The algorithm handles any grammar,
including direct and indirect left recursion.

Left recursion becomes tail recursion by construction.

![](./ss_225.png)
