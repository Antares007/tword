# Every jmp, no ret: eliminating the return address attack surface by construction

The ROP attack vulnerability surface is the implicit "what happens next."
Typed tail-recursive steps make "what happens next" explicit in the type, so there's nothing left to corrupt.

When we force our thinking to solve the problem with only a typed, void, tail-recursive function, essentially with typed steps, we will get a [circuit-like](https://gist.github.com/Antares007/ca25e91e3fa340fc74b517a18f193902), organically grown control flow graph.

To preserve natural structure (modularity, composability, scalability, and encapsulation), pass only flat values and typed step pointers.

In the [example](rooted_tm.e.c), the observer ρ receives a state and an instruction set containing two options: left ω and right ω.

Essentially, the observer ρ receives the state and possible continuations offered by the state locus ξ.

So, state locus ξ is a typed ambiguous step, i.e., it carries forward more than one possible continuation.

Ambiguity can be composed, for example, between two abstract ambiguous steps, Yin and Yang:

Yin defines admissible continuations and selects one defined by Yang. Yang's chosen continuation defines its admissible continuations and chooses one defined by Yin.

We can invite other roles to grow the [terrain](ss_300.png) of more sophisticated interactions.
