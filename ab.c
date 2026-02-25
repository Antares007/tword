typedef struct α α;
typedef struct γ γ;
typedef struct τε τε;
typedef struct ταγ ταγ;
typedef struct τγ τγ;
typedef struct τγγ τγγ;
typedef int* ο;
struct   γ { void (*step)(ο, τε, τγγ, ταγ, τγγ); };
struct   α { void (*step)(ο, τε, τγ, τε, γ); };
struct  τε { void (*step)(ο); };
struct  τγ { void (*step)(ο, γ); };
struct τγγ { void (*step)(ο, γ, γ); };
struct ταγ { void (*step)(ο, α, γ); };

#define EAX 0
#define EBX 1
#define ESP 2
#define EBP 3

void b(ο o, τε ascend, τγ and, τε or, γ unit2) {
  o[EAX] = 0, o[EBX] = 1, and.step(o, unit2);
}
void a(ο o, τε ascend, τγ and, τε or, γ unit2) {
  int prev = o[EAX];
  int current = o[EBX];
  int next = prev + current;
  o[EAX] = current;
  o[EBX] = next;
  if (next < 144) and.step(o, unit2);
  else ascend.step(o);
}
void  S0(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3);
void End(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) { op0.step(o); }
void S12(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) { op2.step(o, (α){a},  (γ){End}); }
void S11(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) { op3.step(o, (γ){S0}, (γ){S12}); }
void  S1(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) { op1.step(o, (γ){End},(γ){S11}); }
void S01(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) { op2.step(o, (α){b},  (γ){S1}); }
void  S0(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) { op1.step(o, (γ){S1}, (γ){S01}); }
extern int printf(const char *__restrict __format, ...);
void accept(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) {
  int prev = o[EBX];
  int current = o[EAX];
  printf("%d x %d = %d\n", prev, current, prev * current);
}

typedef γ op1_t;
typedef α op2_t;
typedef γ op3_t;
#define Γ(name)                                                               \
  void name(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3)
#define Δ(unit2, opcode, unit1, name)                                         \
    Γ(name) { op##opcode.step(o, (op##opcode##_t){unit1}, (γ){unit2}); }
#include"grammar.h"

D(S, 2, b,         A)D(A,
     3, S, 2, a, End)

void Pink_3(ο o, γ unit1, γ unit2);
int main() {
  int o[1023];
  o[EBP] = o[ESP] = sizeof(o) / sizeof(*o);
  Pink_3(o, (γ){S0}, (γ){accept});
  Pink_3(o, (γ){S}, (γ){accept});
}
void Red_0(ο o);
void Red_01(ο o, γ a, γ b);
void Red_1(ο o, γ a, γ b);
void Red_3(ο o, γ a, γ b);
void Yellow_1(ο o, γ a, γ b);
void Yellow_3(ο o, γ a, γ b);
void Green_0(ο o);
void Green_01(ο o, γ a, γ b);
void Green_2(ο o, α a, γ b);
void Green_3(ο o, γ a, γ b);
void Blue_0(ο o);
void Blue_01(ο o, γ a, γ b);
void Blue_2(ο o, α a, γ b);
void Blue_3(ο o, γ a, γ b);

enum { Pink, Blue, Green, Yellow, Red };
void anchor(ο o, τε op0, τγγ op1, ταγ op2, τγγ op3) {}
void ret_t(ο o) {}
ο branch(ο o, γ a, γ b, int color) {
  int i = o[ESP] -= 4;
  o[i + 3] = a.step - anchor;
  o[i + 2] = b.step - anchor;
  o[i + 1] = o[EBP];
  o[i + 0] = Pink;
  o[EBP] = i;
  return o;
}
γ get_a(ο o, int iptr) { return (γ){anchor + o[iptr + 3]}; }
γ get_b(ο o, int iptr) { return (γ){anchor + o[iptr + 2]}; }
int get_upper(ο o, int iptr) { return o[iptr + 1]; }
int get_color(ο o, int iptr) { return o[iptr + 0]; }
void Pink_3(ο o, γ a, γ b) {
  a.step(branch(o, a, b, Pink), (τε){ret_t}, (τγγ){Red_1}, (ταγ){Green_2},
         (τγγ){Red_3});
}
void Red_1(ο o, γ a, γ b) {
  int esp = o[ESP]; int ebp = o[EBP];
  b.step(o, (τε){Red_0}, (τγγ){Red_01}, (ταγ){Green_2}, (τγγ){Red_3});
  o[ESP] = esp; o[EBP] = ebp;
  a.step(o, (τε){ret_t}, (τγγ){Red_1}, (ταγ){Green_2}, (τγγ){Red_3});
}
void Red_01(ο o, γ a, γ b) { Red_0(o); }
ο move_up(ο o) { return o[EBP] = get_upper(o, o[EBP]), o; }
void Red_0(ο o) {
  if (get_color(o, o[EBP]) == Red)
    get_b(o, o[EBP]).step(move_up(o), (τε){Red_0}, (τγγ){Red_01},
                          (ταγ){Green_2}, (τγγ){Red_3});
  else if (get_color(o, o[EBP]) == Blue)
    get_b(o, o[EBP]).step(move_up(o), (τε){Blue_0}, (τγγ){Blue_01},
                          (ταγ){Blue_2}, (τγγ){Blue_3});
  else
    get_b(o, o[EBP]).step(move_up(o), (τε){Green_0}, (τγγ){Green_01},
                          (ταγ){Green_2}, (τγγ){Green_3});
}
void Red_3(ο o, γ a, γ b) {
  int d = o[EBP];
  while (1) {
    if (get_a(o, d).step == a.step)
      return ret_t(o);
    if (get_color(o, d) != Red)
      return a.step(branch(o, a, b, Red), (τε){ret_t}, (τγγ){Red_1},
                    (ταγ){Green_2}, (τγγ){Red_3});
    d = get_upper(o, d);
  }
}
void ret_tgg(ο o, γ a, γ b) {}
void ret_tag(ο o, α a, γ b) {}
void Yellow_1(ο o, γ a, γ b) {
  int esp = o[ESP];
  int ebp = o[EBP];
  b.step(o, (τε){ret_t}, (τγγ){ret_tgg}, (ταγ){ret_tag}, (τγγ){Yellow_3});
  o[ESP] = esp;
  o[EBP] = ebp;
  a.step(o, (τε){ret_t}, (τγγ){Yellow_1}, (ταγ){ret_tag}, (τγγ){Yellow_3});
}
void Yellow_3(ο o, γ a, γ b) {
  int d = o[EBP];
  for (; get_color(o, d) == Yellow; d = get_upper(o, d))
    if (get_a(o, d).step == a.step)
      return ret_t(o);
  if (get_a(o, d).step == a.step)
    b.step(o, (τε){Blue_0}, (τγγ){Blue_01}, (ταγ){Blue_2}, (τγγ){Blue_3});
  else
    a.step(branch(o, a, b, Yellow), (τε){ret_t}, (τγγ){Yellow_1},
           (ταγ){ret_tag}, (τγγ){Yellow_3});
}
void Green_not(ο o) {
  if (get_color(o, o[EBP]) == Blue)
    get_b(o, o[EBP]).step(move_up(o), (τε){Blue_0}, (τγγ){Blue_01},
                          (ταγ){Blue_2}, (τγγ){Blue_3});
  else
    get_b(o, o[EBP]).step(move_up(o), (τε){Green_0}, (τγγ){Green_01},
                          (ταγ){Green_2}, (τγγ){Green_3});
}
void Green_01(ο o, γ a, γ b) { Green_0(o); }
void Green_and(ο o, γ b) {
  b.step(o, (τε){Green_0}, (τγγ){Green_01}, (ταγ){Green_2}, (τγγ){Green_3});
}
void Green_0(ο o) {
  int esp = o[ESP];
  int ebp = o[EBP];
  Green_not(o);
  o[ESP] = esp;
  o[EBP] = ebp;
  get_a(o, o[EBP]).step(o, (τε){ret_t}, (τγγ){Yellow_1}, (ταγ){ret_tag},
                        (τγγ){Yellow_3});
}
void ret_v(ο o) {}

void Green_2(ο o, α a, γ b) {
  a.step(o, (τε){Green_not}, (τγ){Green_and}, (τε){ret_v}, b);
}
void Green_3(ο o, γ a, γ b) {
  a.step(branch(o, a, b, Green), (τε){ret_t}, (τγγ){Red_1}, (ταγ){Green_2},
         (τγγ){Red_3});
}
void Blue_not(ο o) {
  if (get_color(o, o[EBP]) == Yellow || get_color(o, o[EBP]) == Blue)
    get_b(o, o[EBP]).step(move_up(o), (τε){Blue_0}, (τγγ){Blue_01},
                          (ταγ){Blue_2}, (τγγ){Blue_3});
  else
    get_b(o, o[EBP]).step(move_up(o), (τε){Green_0}, (τγγ){Green_01},
                          (ταγ){Green_2}, (τγγ){Green_3});
}
void Blue_and(ο o, γ b) {
  b.step(o, (τε){Blue_0}, (τγγ){Blue_01}, (ταγ){Blue_2}, (τγγ){Blue_3});
}
void Blue_01(ο o, γ a, γ b) { Blue_0(o); }
void Blue_0(ο o) {
  int esp = o[ESP];
  int ebp = o[EBP];
  Blue_not(o);
  if (get_color(o, o[EBP]) == Yellow)
    return ret_v(o);
  o[ESP] = esp;
  o[EBP] = ebp;
  get_a(o, o[EBP]).step(o, (τε){ret_t}, (τγγ){Yellow_1}, (ταγ){ret_tag},
                        (τγγ){Yellow_3});
}
void Blue_2(ο o, α a, γ b) {
  a.step(o, (τε){Blue_not}, (τγ){Blue_and}, (τε){ret_v}, b);
}
void Blue_3(ο o, γ a, γ b) {
  a.step(branch(o, a, b, Blue), (τε){ret_t}, (τγγ){Red_1}, (ταγ){Green_2},
         (τγγ){Red_3});
}
