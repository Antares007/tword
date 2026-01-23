#define N(argo) void argo(struct Sac gram, struct Sac o, struct Ray *s, const char*in, int pos)
#define S static N
#define StepCon gram, o, s, in, pos
enum { Pink, Blue, Green, Yellow, Red };
struct Ray;
typedef struct Sac { N((**c)) ; } Sac;
typedef struct Ray { Sac gram; struct Ray *upper; char color; } Ray;
typedef N((*Step));

S(not) { o.c[0](StepCon); }
S(and) { o.c[1](StepCon); }
S(or ) { o.c[2](StepCon); }

S(Sa);
S(b) { (in[pos] == 'b' ? and : or)(gram, o, s, in, pos + 1); }
S(a) { (in[pos] == 'a' ? and : or)(gram, o, s, in, pos + 1); }
S(unit18_2) { static Step v[] = {not,      a};      gram = (Sac){v}, o.c[2](StepCon); }
S(unit18_1) { static Step v[] = {unit18_2, Sa};     gram = (Sac){v}, o.c[3](StepCon); }
S(unit18  ) { static Step v[] = {unit18_1, not};    gram = (Sac){v}, o.c[1](StepCon); }
S(Sa_1    ) { static Step v[] = {unit18,   b};      gram = (Sac){v}, o.c[2](StepCon); }
S(Sa      ) { static Step v[] = {Sa_1,     unit18}; gram = (Sac){v}, o.c[1](StepCon); }
S(expression);
S(gram);
S((*srart));
extern int printf (const char *__restrict __format, ...);
S(accept) { printf("true in: %s pos: %d\n", in, pos); }
int main() {
  gram((Sac){(Step[]){accept, Sa}},             (Sac){0}, 0, "baaaaaa",  0);
  gram((Sac){(Step[]){accept, expression}},     (Sac){0}, 0, "(1+2)*3", 0);
} 
S(lex_1     ) { Step n = (in[pos++] == '1' ? and : or); n(StepCon); }
S(lex_2     ) { Step n = (in[pos++] == '2' ? and : or); n(StepCon); }
S(lex_3     ) { Step n = (in[pos++] == '3' ? and : or); n(StepCon); }
S(lex_op    ) { Step n = (in[pos++] == '(' ? and : or); n(StepCon); }
S(lex_cp    ) { Step n = (in[pos++] == ')' ? and : or); n(StepCon); }
S(lex_plus  ) { Step n = (in[pos++] == '+' ? and : or); n(StepCon); }
S(lex_minus ) { Step n = (in[pos++] == '-' ? and : or); n(StepCon); }
S(lex_bang  ) { Step n = (in[pos++] == '!' ? and : or); n(StepCon); }
S(lex_mul   ) { Step n = (in[pos++] == '*' ? and : or); n(StepCon); }
S(lex_div   ) { Step n = (in[pos++] == '/' ? and : or); n(StepCon); }
S(lex_semi  ) { Step n = (in[pos++] == ';' ? and : or); n(StepCon); }
S((*_[])) = { 
  ['1'] = lex_1, ['2'] = lex_2,
  ['3'] = lex_3, ['('] = lex_op,
  [')'] = lex_cp, ['+'] = lex_plus,
  ['-'] = lex_minus, ['!'] = lex_bang,
  ['*'] = lex_mul, ['/'] = lex_div,
  [';'] = lex_semi,
};
#include "programmer.h"
#define Δ(next, opcode, unit, name) S(name) { gram = (Sac){(Step[]){next, unit}}, o.c[opcode](StepCon); }
D(constant,       2, _['1'], A)D(A,
                  2, _['2'], A)D(A,
                  2, _['3'], not);
S(expression);
D(primary,        3, constant, A)D(A,
                  2, _['('], 3, expression, 2, _[')'], not);
D(unary,          3, primary, A)D(A,
                  2, _['-'], 3, unary, A)D(A,
                  2, _['!'], 3, unary, not)
D(multiplicative, 3, unary, A)D(A,
                  3, multiplicative, 2, _['*'], 3, unary, A)D(A,
                  3, multiplicative, 2, _['/'], 3, unary, not)
D(additive,       3, multiplicative, A)D(A,
                  3, additive, 2, _['+'], 3, multiplicative, A)D(A,
                  3, additive, 2, _['-'], 3, multiplicative, not)
D(expression,     3, additive, not)
D(expression_stm, 3, expression, 2, _[';'], not)
// below is choice machine algorith
// which runs grammar and runs
// actions too.
// lets imagine root/grammar
// namespace which can evolution
// in time as one bounded set and
// actions namespace as
// crown/growing branches and
// furits
S(reTurn) { return (void)0; }
S((*Red_descend_steps[]));
S((*Yellow_descend_steps[]));
S((*Red_walk_steps[]));
S((*Yellow_walk_steps[]));
S((*Green_walk_steps[]));
S((*Green_NotAndOr_steps[]));
S((*Blue_walk_steps[]));
S((*Blue_NotAndOr_steps[]));
S(Blue_not) {
  Step c = s->gram.c[0];
  if      (s->color == Yellow)        o = (Sac){Blue_walk_steps},  s = s->upper, c(StepCon);
  else if (s->color == Blue)          o = (Sac){Blue_walk_steps},  s = s->upper, c(StepCon);
  else                                o = (Sac){Green_walk_steps}, s = s->upper, c(StepCon);
}
S(Blue_and) { o = (Sac){Blue_walk_steps}, gram.c[0](StepCon); }
S((*Blue_NotAndOr_steps[])) = {
  Blue_not,
  Blue_and,
  reTurn
};
S(Blue_dot) {
  Blue_not(StepCon);
  if      (s->color == Yellow) return;
  o = (Sac){Yellow_descend_steps}, s->gram.c[1](StepCon);
}
S(Blue_walk_dispatch) {
  o = (Sac){Blue_NotAndOr_steps}, gram.c[1](StepCon);
}
S(Blue_branch_Red_descend) {
  o = (Sac){Red_descend_steps}, s = &(Ray){gram, s, Blue}, gram.c[1](StepCon);
}
S((*Blue_walk_steps[])) = {
    Blue_dot,
    Blue_dot,
    Blue_walk_dispatch,
    Blue_branch_Red_descend,
};
S(Green_not) {
  Step c = s->gram.c[0];
  if (s->color == Blue) o = (Sac){Blue_walk_steps},  s = s->upper, c(StepCon);
  else                  o = (Sac){Green_walk_steps}, s = s->upper, c(StepCon);
}
S(Green_and) { o = (Sac){Green_walk_steps}, gram.c[0](StepCon); }
S((*Green_NotAndOr_steps[])) = {
  Green_not,
  Green_and,
  reTurn
};
S(Green_dot) {
  Green_not(StepCon);
  o = (Sac){Yellow_descend_steps}, s->gram.c[1](StepCon);
}
S(Green_walk_dispatch) {
  o = (Sac){Green_NotAndOr_steps}, gram.c[1](StepCon);
}
S(Green_branch_Red_descend) {
  o = (Sac){Red_descend_steps}, s = &(Ray){gram, s, Green}, gram.c[1](StepCon);
}
S((*Green_walk_steps[])) = {
    Green_dot,
    Green_dot,
    Green_walk_dispatch,
    Green_branch_Red_descend,
};
S(Yellow_grow) {
  Ray *d = s;
  for (; d->color == Yellow; d = d->upper) if (d->gram.c[1] == gram.c[1]) return;
  if (d->gram.c[1] == gram.c[1]) o = (Sac){Blue_walk_steps}, gram.c[0](StepCon);
  else o = (Sac){Yellow_descend_steps}, s = &(Ray){gram, s, Yellow}, gram.c[1](StepCon);
}
S((*Yellow_walk_steps[])) = {
    reTurn,
    reTurn,
    reTurn,
    Yellow_grow,
};
S(Red_dot) {
  Step c = s->gram.c[0];
  if (s->color == Red)       o = (Sac){Red_walk_steps},   s = s->upper, c(StepCon);
  else if (s->color == Blue) o = (Sac){Blue_walk_steps},  s = s->upper, c(StepCon);
  else                       o = (Sac){Green_walk_steps}, s = s->upper, c(StepCon);
}
S(Red_branch_Red_descend) {
  Ray *d = s;
  while (1) {
    if (d->gram.c[1] == gram.c[1]) return;
    if (d->color != Red)
      return o = (Sac){Red_descend_steps}, s = &(Ray){gram, s, Red}, gram.c[1](StepCon);
    d = d->upper;
  }
}
S((*Red_walk_steps[])) = {
    Red_dot,
    Red_dot,
    Green_walk_dispatch,
    Red_branch_Red_descend,
};
S(Yellow_descend1) {
  o = (Sac){Yellow_walk_steps},   gram.c[0](StepCon);
  o = (Sac){Yellow_descend_steps},gram.c[1](StepCon);
}
S((*Yellow_descend_steps[])) = {
  reTurn,
  Yellow_descend1
};
S(Red_descend1) {
  o = (Sac){Red_walk_steps},    gram.c[0](StepCon);
  o = (Sac){Red_descend_steps}, gram.c[1](StepCon);
}
S((*Red_descend_steps[])) = {
  reTurn,
  Red_descend1
};
S(gram) { o = (Sac){Red_descend_steps}, s = &(Ray){gram, s, Pink}, gram.c[1](StepCon); }
