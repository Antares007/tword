// The purest form for specifying traversal-pluggable grammar
// in a systems language by typed steps supports laizy evalyation
typedef struct γ γ;
typedef struct δ δ;
typedef struct β β;
typedef struct τ τ;
typedef void** ο;
struct  γ { void (*step)(ο s, δ dot, β branch,  τ terminal); };
struct  δ { void (*step)(ο s); };
struct  β { void (*step)(ο s, γ symbol, γ next_grammar_member); };
struct  τ { void (*step)(ο s, char car, γ next_grammar_member); };

     void dot(ο s, δ d, β b, τ t) { d.step(s); }
       void S(ο s, δ d, β b, τ t);
void unit28_2(ο s, δ d, β b, τ t) { t.step(s, 'a',         (γ){dot}); }
void unit28_1(ο s, δ d, β b, τ t) { b.step(s, (γ){S},      (γ){unit28_2}); }
  void unit28(ο s, δ d, β b, τ t) { b.step(s, (γ){dot},    (γ){unit28_1}); }
     void S_1(ο s, δ d, β b, τ t) { t.step(s, 'b',         (γ){dot}); }
       void S(ο s, δ d, β b, τ t) { b.step(s, (γ){unit28}, (γ){S_1}); }
// S -> 'b' | S 'a'

#include"grammar.h"

D(constant,       2, '1', A)D(A,
                  2, '2', A)D(A,
                  2, '3', dot);
D(expression);

D(primary,        1, constant, A)D(A,
                  2, '(', 1, expression, 2, ')', dot);
D(unary,          1, primary, A)D(A,
                  2, '-', 1, unary, A)D(A,
                  2, '!', 1, unary, dot)
D(multiplicative, 1, unary, A)D(A,
                  1, multiplicative, 2, '*', 1, unary, A)D(A,
                  1, multiplicative, 2, '/', 1, unary, dot)
D(additive,       1, multiplicative, A)D(A,
                  1, additive, 2, '+', 1, multiplicative, A)D(A,
                  1, additive, 2, '-', 1, multiplicative, dot)
D(expression,     1, additive, dot)
D(expression_stm, 1, expression, 2, ';', dot)
