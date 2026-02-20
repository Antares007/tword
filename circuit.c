#define S(name)
#define OP1(next, opcode, unit, name)               \
  name@{ shape: circle, label: #name } -.-> next;   \
  name@{ shape: circle, label: #name } ---> unit;
#define OP2(next, opcode, unit, name)               \
  name@{ shape: subproc, label: #name } -.-> next;  \
  name@{ shape: subproc, label: #name } ---> unit;
#define OP3(next, opcode, unit, name)               \
  name@{ shape: tri, label: #name } -.-> next;      \
  name@{ shape: tri, label: #name } ---> unit;
#define Δ_(next, opcode, unit, name) OP##opcode(next, opcode, unit, name)
#define Δ(...) Δ_(__VA_ARGS__)

#include "programmer.h"

D(constant,       2, lex_1, A)D(A,
                  2, lex_2, A)D(A,
                  2, lex_3, not);
S(expression);
D(primary,        3, constant, A)D(A,
                  2, lex_op, 3, expression, 2, lex_cp, not);
D(unary,          3, primary, A)D(A,
                  2, lex_minus, 3, unary, A)D(A,
                  2, lex_bang, 3, unary, not)
D(multiplicative, 3, unary, A)D(A,
                  3, multiplicative, 2, lex_mul, 3, unary, A)D(A,
                  3, multiplicative, 2, lex_div, 3, unary, not)
D(additive,       3, multiplicative, A)D(A,
                  3, additive, 2, lex_plus, 3, multiplicative, A)D(A,
                  3, additive, 2, lex_minus, 3, multiplicative, not)
D(expression,     3, additive, not)
D(expression_stm, 3, expression, 2, lex_semi, not)
