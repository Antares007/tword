# 1 Grammar Machine: Two Poles of Programming

This repository is a proof of concept showing how to divide the
interpretation step into two poles of evolution and conquer, using
executable specifications directly rooted in the host language.

A Step is the fundamental unit of composition.

An ambiguous Step, ორაზროვანი ნაბიჯი, is a two-meaning Step
that defines a bounded space of admissible continuations.

We can carry this bounded space of admissible continuations forward in
time, Step by Step, by *aStep* and by *bStep*, enabling the evolution
of two distinct polar sides of programming without incidental state
coupling.

Each pole operates independently; they feed each other.
Both live inside one host language, which alone owns control flow.

The algorithm can handle any form of grammar, including direct and
indirect left recursion.

Left is tail recursion by construction.

# 2 Definitions

* `Step`: tail-optimized void functions with fixed parameters representing execution context.
A Step is the primary continuation chooser through `Sac`.
* `Sac`: space of admissible continuations.
* `Ray`: colored branching chain; part of the execution context (used for descent/ascent).

# 3 Status

This is experimental, stack-hungry, and intentionally minimal.
It exists to demonstrate the model.
![](./ss_225.png);
