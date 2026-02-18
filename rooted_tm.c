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

#include<stdio.h>
#include<unistd.h>

void head(ω l, char v, ω r);

void move(ξ cell) { cell.step((ρ){head}); }

void head(ω l, char v, ω r) {
  printf("%c\n", v++),
    usleep(20000),
      l.step(v >= 127 ? '0' : v, (δ){move});
}

int main() {
  c0 = '4', c1 = '6', c2 = '1', c3 = '2', c4 = '3',
  c5 = '5', c6 = '1', c7 = '2', c8 = '3', c9 = '0',
  c0p((ρ){head});
}
