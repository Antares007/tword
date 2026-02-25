// playground to preporcess grammar macro DSL into methagraph
#define Γ(name)
#define OP1(next, opcode, unit, name)               \
  name@{ shape: stadium, label: #name } -.-> next;  \
  name@{ shape: stadium, label: #name } ---> unit;
#define OP2(next, opcode, unit, name)               \
  name@{ shape: rect, label: #name } -.-> next;     \
  name@{ shape: rect, label: #name } ---> unit;     \
  unit@{ shape: subprocess, label: #unit } ---> next;   
#define OP3(next, opcode, unit, name)               \
  name@{ shape: trap-t, label: #name } -.-> next;   \
  name@{ shape: trap-t, label: #name } ---> unit;

#define Δ_(next, opcode, unit, name) OP##opcode(next, opcode, unit, name)
#define Δ(...) Δ_(__VA_ARGS__)

#include "grammar.h"

D(S, 2, b,        A)D(A,
     3, S, 2, a, End)
//D(constant,       2, lex_1, A)D(A,
//                  2, lex_2, A)D(A,
//                  2, lex_3, End);
//S(expression);
//D(primary,        3, constant, A)D(A,
//                  2, lex_op, 3, expression, 2, lex_cp, End);
//D(unary,          3, primary, A)D(A,
//                  2, lex_minus, 3, unary, A)D(A,
//                  2, lex_bang, 3, unary, End)
//D(multiplicative, 3, unary, A)D(A,
//                  3, multiplicative, 2, lex_mul, 3, unary, A)D(A,
//                  3, multiplicative, 2, lex_div, 3, unary, End)
//D(additive,       3, multiplicative, A)D(A,
//                  3, additive, 2, lex_plus, 3, multiplicative, A)D(A,
//                  3, additive, 2, lex_minus, 3, multiplicative, End)
//D(expression,     3, additive, End)
//D(expression_stm, 3, expression, 2, lex_semi, End)
