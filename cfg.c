// ============================================================================
// PURE GRAMMAR MACHINE - Typed Version with Explicit Pole Separation
// ============================================================================
// This version makes the three poles (Grammar, Aactions, Traversal) explicit
// through type signatures. Each function signature encodes what pole it belongs
// to and what it can call.
//
// we are composing ambiguous system using more fundamental unint of composition step.
// step is defin
// 
// The context is evolution | A step is the machine | A grammar is the world
// ============================================================================
//
typedef struct α α;
typedef struct γ γ;
typedef struct ρ ρ;
typedef struct τ τ;
typedef struct ταγ ταγ;
typedef struct τγ τγ;
typedef struct τγγ τγγ;
typedef struct ϋ ϋ;

// # The context is evolution.
// ## Traversal step context types:
#define Traversal(  name) void name(                  ρ *r8, long r9)
#define TraversalG( name) void name(         γ unit2, ρ *r8, long r9)
#define TraversalAG(name) void name(α unit1, γ unit2, ρ *r8, long r9)
#define TraversalGG(name) void name(γ unit1, γ unit2, ρ *r8, long r9)
// ## Grammar step context type
#define Grammar(name) void name( \
    τ end, τγγ definition, ταγ action, τγγ reference, ρ *r8, long r9)
// ## Action step context type
#define Action(name) void name( \
    τ ascend, τγ and, ϋ  or, γ  unit2, ρ *r8, long r9)

struct γ   {     Grammar((*step)); };
struct α   {      Action((*step)); };
struct τ   {   Traversal((*step)); };
struct τγ  {  TraversalG((*step)); };
struct τγγ { TraversalGG((*step)); };
struct ταγ { TraversalAG((*step)); };
struct ϋ   {        void (*step)();};

// ## Medullary ray
// Linked list like branching chain to record descend.
// Used for ascending and detecting left recusion.
// We can visualize it casted from current position (r8)
// to starting symbol, Pink branch, as strait line.
struct ρ {
  Grammar((*unit1));
  Grammar((*unit2));
  struct ρ *upper;
  char color;
};

void b(τ ascend, τγ and, ϋ or, γ unit2, ρ *r8, long r9) {
  r9 = 1, and.step(unit2, r8, r9);
}
Action(a) {
  int prev = (int)(r9 >> 32);
  int current = (int)(r9 & 0xFFFFFFFF);
  int next = prev + current;
  r9 = ((long)current << 32) | next;
  if (next < 144) and.step(unit2, r8, r9);
  else ascend.step(r8, r9);
}
/*     S -> b | S a
             ┌──────────┐                     
   ╔════════╗│     ┌────┴────┐               
  ┌╢1< S0 >2╟┘ █b█─┤1< S01 >2├┐              
  │╚════╤═══╝      └─────────┘│              
  │     └─────┐               │              
  └─────┬─────┼───────────────┘              
        │    ┌┼─────┐     ┌──────────┐       
   ╔════╧═══╗││┏━━━━┷━━━━┓│     ┌────┴────┐ 
  ┌╢1< S1 >2╟┘└┨1< S11 >2┠┘ █a█─┤1< S12 >2├┐
  │╚════════╝  ┗━━━━━━━━━┛      └─────────┘│
  └─────┬──────────────────────────────────┘
   ╔════╧═══╗                                 
   ║   End  ║                                 
   ╚════════╝ */
void S0(τ end, τγγ definition, ταγ action, τγγ reference, ρ *r8, long r9);
Grammar(End) {        end.step(r8, r9); }
Grammar(S12) {     action.step((α){a  }, (γ){End}, r8, r9); }
Grammar(S11) {  reference.step((γ){S0 }, (γ){S12}, r8, r9); }
Grammar(S1 ) { definition.step((γ){End}, (γ){S11}, r8, r9); }

Grammar(S01) {     action.step((α){b  }, (γ){S1 }, r8, r9); }
Grammar(S0 ) { definition.step((γ){S1 }, (γ){S01}, r8, r9); }

extern int printf(const char *__restrict __format, ...);
Grammar(accept) {
  int prev = (int)(r9 >> 32);
  int current = (int)(r9 & 0xFFFFFFFF);
  printf("%d x %d = %d\n", prev, current, prev * current);
}

typedef γ op1_t;
typedef α op2_t;
typedef γ op3_t;
#define Γ(name)                                                               \
  void name(struct   τ op0, struct τγγ op1, struct ταγ op2,                   \
            struct τγγ op3, struct ρ *r8, long r9)
#define Δ(unit2, opcode, unit1, name)                                         \
    Γ(name) { op##opcode.step((op##opcode##_t){unit1}, (γ){unit2}, r8, r9); }
#include"grammar.h"

D(S, 2, b,         A)D(A,
     3, S, 2, a, End)


TraversalGG(Pink_3);
int main() {
  Pink_3((γ){S0}, (γ){accept}, 0, 0);
  Pink_3((γ){S}, (γ){accept}, 0, 0);
}

  Traversal(Red_0   ); TraversalGG(Red_01  );
TraversalGG(Red_1   );
TraversalGG(Red_3   );
TraversalGG(Yellow_1);
TraversalGG(Yellow_3);
  Traversal(Green_0 ); TraversalGG(Green_01);
TraversalAG(Green_2 );
TraversalGG(Green_3 );
  Traversal(Blue_0  ); TraversalGG(Blue_01 );
TraversalAG(Blue_2  );
TraversalGG(Blue_3  );


enum { Pink, Blue, Green, Yellow, Red };

Traversal(ret_t) {}
TraversalGG(Pink_3) {
  unit1.step( (τ){ret_t},
            (τγγ){Red_1},
            (ταγ){Green_2},
            (τγγ){Red_3},
           &(ρ){unit1.step, unit2.step, r8, Pink}, r9);
}
TraversalGG(Red_1) {
  unit2.step( (τ){Red_0},
            (τγγ){Red_01},
            (ταγ){Green_2},
            (τγγ){Red_3},
            r8, r9);
  unit1.step( (τ){ret_t},
            (τγγ){Red_1},
            (ταγ){Green_2},
            (τγγ){Red_3},
            r8, r9);
}
TraversalGG(Red_01) { Red_0(r8, r9); }
Traversal(Red_0) {
  if (r8->color == Red)
    r8->unit2((τ){Red_0},
            (τγγ){Red_01},
            (ταγ){Green_2},
            (τγγ){Red_3},
            r8->upper, r9);
  else if (r8->color == Blue)
    r8->unit2((τ){Blue_0},
            (τγγ){Blue_01},
            (ταγ){Blue_2},
            (τγγ){Blue_3},
            r8->upper, r9);
  else
    r8->unit2((τ){Green_0},
            (τγγ){Green_01},
            (ταγ){Green_2},
            (τγγ){Green_3},
            r8->upper, r9);
}

TraversalGG(Red_3) {
  ρ *d = r8;
  while (1) {
    if (d->unit1 == unit1.step)
      return ret_t(r8, r9);
    if (d->color != Red)
      return unit1.step((τ){ret_t},
                      (τγγ){Red_1},
                      (ταγ){Green_2},
                      (τγγ){Red_3},
                      &(ρ){unit1.step, unit2.step, r8, Red}, r9);
    d = d->upper;
  }
}

TraversalGG(ret_tgg) {}
TraversalAG(ret_tag) {}
TraversalGG(Yellow_1) {
  unit2.step( (τ){ret_t},
            (τγγ){ret_tgg},
            (ταγ){ret_tag},
            (τγγ){Yellow_3},
            r8, r9);
  unit1.step( (τ){ret_t},
            (τγγ){Yellow_1},
            (ταγ){ret_tag},
            (τγγ){Yellow_3},
            r8, r9);
}

TraversalGG(Yellow_3) {
  ρ *d = r8;
  for (; d->color == Yellow; d = d->upper)
    if (d->unit1 == unit1.step)
      return ret_t(r8, r9);
  if (d->unit1 == unit1.step)
    unit2.step( (τ){Blue_0},
              (τγγ){Blue_01},
              (ταγ){Blue_2},
              (τγγ){Blue_3},
              r8, r9);
  else
    unit1.step( (τ){ret_t},
              (τγγ){Yellow_1},
              (ταγ){ret_tag},
              (τγγ){Yellow_3},
              &(ρ){unit1.step, unit2.step, r8, Yellow}, r9);
}

Traversal(Green_not) {
  if (r8->color == Blue)
    r8->unit2(  (τ){Blue_0},
              (τγγ){Blue_01},
              (ταγ){Blue_2},
              (τγγ){Blue_3}, r8->upper, r9);
  else
    r8->unit2(  (τ){Green_0},
              (τγγ){Green_01},
              (ταγ){Green_2},
              (τγγ){Green_3}, r8->upper, r9);
}
TraversalGG(Green_01) {
  Green_0(r8, r9);
}
TraversalG(Green_and) {
  unit2.step((τ){Green_0},
           (τγγ){Green_01},
           (ταγ){Green_2},
           (τγγ){Green_3}, r8, r9); }
Traversal(Green_0) {
  Green_not(r8, r9);
  r8->unit1((τ){ret_t},
          (τγγ){Yellow_1},
          (ταγ){ret_tag},
          (τγγ){Yellow_3}, r8, r9);
}
void ret_v( ) {}
TraversalAG(Green_2) {
  unit1.step( (τ){Green_not},
          (τγ){Green_and},
           (ϋ){ret_v}, unit2, r8, r9);
}
TraversalGG(Green_3) {
  unit1.step( (τ){ret_t},
            (τγγ){Red_1},
            (ταγ){Green_2},
            (τγγ){Red_3},
            &(ρ){unit1.step, unit2.step, r8, Green}, r9);
}
Traversal(Blue_not) {
  if (r8->color == Yellow || r8->color == Blue)
    (r8->unit2)((τ){Blue_0},
              (τγγ){Blue_01},
              (ταγ){Blue_2},
              (τγγ){Blue_3},
              r8->upper, r9);
  else
    (r8->unit2)((τ){Green_0},
              (τγγ){Green_01},
              (ταγ){Green_2},
              (τγγ){Green_3},
              r8->upper, r9);
}
TraversalG(Blue_and) {
  unit2.step((τ){Blue_0},
           (τγγ){Blue_01},
           (ταγ){Blue_2},
           (τγγ){Blue_3},
           r8, r9); }
TraversalGG(Blue_01) { Blue_0(r8, r9); }
Traversal(Blue_0) {
  Blue_not(r8, r9);
  if (r8->color == Yellow) return ret_v();
  (r8->unit1)((τ){ret_t},
            (τγγ){Yellow_1},
            (ταγ){ret_tag},
            (τγγ){Yellow_3},
            r8, r9);
}
TraversalAG(Blue_2) {
  unit1.step((τ){Blue_not},
            (τγ){Blue_and},
             (ϋ){ret_v}, unit2, r8, r9);
}
TraversalGG(Blue_3) {
  unit1.step( (τ){ret_t},
            (τγγ){Red_1},
            (ταγ){Green_2},
            (τγγ){Red_3},
            &(ρ){unit1.step, unit2.step, r8, Blue}, r9);
}
