# Ambiguous Step Graph
> In the beginning was the Step

Context-sensitive parsing without a lexer hack

## The Problem

The same word `if` is a keyword in one position and an identifier in
another. That role exists only in context, and context is only known
mid-walk. The decision must be made during traversal, and when it turns out
wrong, the traversal must swap on the spot to retry with a different role
assignment. A static traversal committed upfront has no recovery path.

## The Idea

Turn the grammar into a computation that is pausable, incremental,
and dynamically traversable. Represent your grammar as an [Ambiguous Step Graph](https://gist.github.com/Antares007/ca25e91e3fa340fc74b517a18f193902):
pure void tail-recursive functions that receive their entire
instruction set from the traversal as parameters.

[S -> "b" | S "a"](https://mermaid.live/edit#pako:eNqdk0lvhCAYhv8K-c5q1FlEDk3T5djT9NSQTFBxSRUMQtqpmf9enKU6XWeaYALhfXjkA3pIZcaBgOu6VKRS5FVBqECoZhtpNEG8fqZiN5nX8iUtmdLo8cYmVuvgukddyVpOkOKpdiyT8JogCnaOAtoi13OvkBGVDvC5hGuJxIaTMdqZpFUy5V03AZIxPgomjGZZZZqpYfyjQXZe-mR52_b9dfjjPo6BUXYvssvBwcssxv6oAhvjJ55JobVirfuN6csJWfc_-EG9-gB_K-mhjp-twcXwYbfgQKGqDIhWhjvQcNWwYQj9cH8p6JI3nMJAZzxnptYUqNharGXiScrmSCppihJIzurOjkybMc3vKlYoNka4yLi6lUZoIIvdCkB6eAUS-jPPD3AQhWGI5z6Olw5sgMSBh-NouYiW0XzhxzO8deBt5_Q97Ic4igL7hRjjADvAs0pL9bB_ibsHuX0HXe4dcg)

```c
void S(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) {
  op1.step(o, (γ){unit18}, (γ){S_1});
}
```

Each step declares its role to the traversal by selecting an opcode and
presenting exactly two continuations: what I am, what I hold, and what comes
after me. The traversal listens and decides what to do with what it has been
offered. The grammar step does not know who traverses it; the traversal does not
know the grammar's intent. This mutual delegation is what makes them composable.

The opcodes presented by traversal to grammar step

| opcode |trversal role | meaning      | a continuation        | b continuation            |
|--------|--------------|--------------|-----------------------|---------------------------| 
| `op0`  | descend      | end of rules | —                     | —                         |
| `op0`  | walk         | end of rule  | —                     | —                         |
| `op1`  | descend      | choice point | alternative branch    | next step in current rule |
| `op1`  | walk         | end of rule  | alternative branch    | next step in current rule |
| `op2`  | descend/walk | action node  | action to execute     | next grammar step         |
| `op3`  | descend/walk | reference    | entry of another rule | next step in current rule |

The same grammar steps (`S0, S0_1, ..., a, b`) can then be walked by
entirely different traversal strategies — backtracking, exhaustive forward,
type-check, interpret — all without touching the grammar.

## Why This Eliminates the Attack Surface

The ROP attack vulnerability surface is the implicit "what happens next." Typed tail-recursive steps make "what happens next" explicit in the type, so there's nothing left to corrupt.

When we force our thinking to solve the problem with only a typed, void, tail-recursive function, essentially with typed steps, we will get a [circuit-like](https://gist.github.com/Antares007/ca25e91e3fa340fc74b517a18f193902), organically grown control flow graph.

To preserve natural structure (modularity, composability, scalability, and encapsulation), pass only flat values and typed step pointers.

In the [example](rooted_tm.e.c), the observer ρ receives a state and an instruction set containing two options: left ω and right ω.

Essentially, the observer ρ receives the state and possible continuations offered by the state locus ξ.

So, state locus ξ is a typed ambiguous step, i.e., it carries forward more than one possible continuation.

Ambiguity can be composed, for example, between two abstract ambiguous steps, Yin and Yang:

Yin defines admissible continuations and selects one defined by Yang. Yang's chosen continuation defines its admissible continuations and chooses one defined by Yin.

We can invite other roles to grow the terrain of more sophisticated interactions.

![img](ss_300.png "This is what \"no attack surface\" looks like in assembly")

## Security

Type is security. We need not verify the whole control flow graph each time,
only the type of the machine we want to interact with. Typed machines can be
compiled separately and composed structurally.

In practice, each cell lays out in binary as a structured type:

```
ωξω, ωξω, ωξω, ... ωξω
```

This is the crystallized, hashable form of the circular tape machine.
Index into it as a universal interface. By structurally aligning and composing
small machines, you get a binary hash of richer operational semantics while
preserving that universal interface.

Compilers need to align with this reality: produce typed machine binaries with
a guaranteed universal interface. How typed machine output changes the compilation
pipeline and grows operational semantics is the most engaging road ahead.

## Status

These ideas are under active development. The roles of grammar steps, actions,
and traversals are being shaped in real battle.
