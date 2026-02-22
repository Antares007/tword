typedef struct ξ ξ;
typedef struct ρ ρ;
typedef struct ω ω;
typedef struct δ δ;

struct ρ { void (*step)(ω, char, ω); };
struct ξ { void (*step)(ρ);          };
struct ω { void (*step)(char, δ);    };
struct δ { void (*step)(ξ);          };

#define C(L, P, R)                                                             \
  void c##R##p(ρ);                                                             \
  char c##P = 0;                                                               \
  void c##P##l(char s, δ move) { c##P = s, move.step((ξ){c##L##p}); }          \
  void c##P##r(char s, δ move) { c##P = s, move.step((ξ){c##R##p}); }          \
  void c##P##p(ρ read) { read.step((ω){c##P##l}, c##P, (ω){c##P##r}); }

void c0p(ρ);
C(0, 9, 8) C(9, 8, 7) C(8, 7, 6) C(7, 6, 5) C(6, 5, 4)
C(5, 4, 3) C(4, 3, 2) C(3, 2, 1) C(2, 1, 0) C(1, 0, 9)

#define GOTO(n)                                 \
  void n(ω l, char s, ω r);                     \
  void goto_##n(ξ locus) { locus.step((ρ){n}); }
GOTO(s1) GOTO(s2) GOTO(s3) GOTO(s4) GOTO(s5)

void s5(ω l, char s, ω r) {
  if (s - '0') l.step('1', (δ){goto_s5});
  else         r.step('1', (δ){goto_s1});
}
void s4(ω l, char s, ω r) {
  if (s - '0') l.step('1', (δ){goto_s4});
  else         l.step('0', (δ){goto_s5});
}
void s3(ω l, char s, ω r) {
  if (s - '0') r.step('1', (δ){goto_s3});
  else         l.step('1', (δ){goto_s4});
}
void s2(ω l, char s, ω r) {
  if (s - '0') r.step('1', (δ){goto_s2});
  else         r.step('0', (δ){goto_s3});
}
void s1(ω l, char s, ω r) {
  if (s - '0') r.step('0', (δ){goto_s2});
}

extern int printf(const char *restrict __format, ...);
int main()
{
  c9='1', c8='1', c7='1', c6='0',
  c5='0', c4='0', c3='0', c2='0',
  c1='0', c0='0';
  printf("%c%c%c%c%c%c%c%c%c%c\n",c9,c8,c7,c6,c5,c4,c3,c2,c1,c0);
  c9p((ρ){s1});
  printf("%c%c%c%c%c%c%c%c%c%c\n",c9,c8,c7,c6,c5,c4,c3,c2,c1,c0);
}
