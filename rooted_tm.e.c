typedef struct ξ ξ;
typedef struct ρ ρ;
typedef struct ω ω;
typedef struct δ δ;
struct ρ { void (*step)(ω, char, ω); };
struct ξ { void (*step)(ρ); };
struct ω { void (*step)(char, δ); };
struct δ { void (*step)(ξ); };

void c0p(ρ);
void c8p(ρ);
char c9 = 0;
void c9l(char s, δ move) { c9 = s, move.step((ξ){c0p}); }
void c9r(char s, δ move) { c9 = s, move.step((ξ){c8p}); }
void c9p(ρ read) { read.step((ω){c9l}, c9, (ω){c9r}); }
void c7p(ρ);
char c8 = 0;
void c8l(char s, δ move) { c8 = s, move.step((ξ){c9p}); }
void c8r(char s, δ move) { c8 = s, move.step((ξ){c7p}); }
void c8p(ρ read) { read.step((ω){c8l}, c8, (ω){c8r}); }
void c6p(ρ);
char c7 = 0;
void c7l(char s, δ move) { c7 = s, move.step((ξ){c8p}); }
void c7r(char s, δ move) { c7 = s, move.step((ξ){c6p}); }
void c7p(ρ read) { read.step((ω){c7l}, c7, (ω){c7r}); }
void c5p(ρ);
char c6 = 0;
void c6l(char s, δ move) { c6 = s, move.step((ξ){c7p}); }
void c6r(char s, δ move) { c6 = s, move.step((ξ){c5p}); }
void c6p(ρ read) { read.step((ω){c6l}, c6, (ω){c6r}); }
void c4p(ρ);
char c5 = 0;
void c5l(char s, δ move) { c5 = s, move.step((ξ){c6p}); }
void c5r(char s, δ move) { c5 = s, move.step((ξ){c4p}); }
void c5p(ρ read) { read.step((ω){c5l}, c5, (ω){c5r}); }
void c3p(ρ);
char c4 = 0;
void c4l(char s, δ move) { c4 = s, move.step((ξ){c5p}); }
void c4r(char s, δ move) { c4 = s, move.step((ξ){c3p}); }
void c4p(ρ read) { read.step((ω){c4l}, c4, (ω){c4r}); }
void c2p(ρ);
char c3 = 0;
void c3l(char s, δ move) { c3 = s, move.step((ξ){c4p}); }
void c3r(char s, δ move) { c3 = s, move.step((ξ){c2p}); }
void c3p(ρ read) { read.step((ω){c3l}, c3, (ω){c3r}); }
void c1p(ρ);
char c2 = 0;
void c2l(char s, δ move) { c2 = s, move.step((ξ){c3p}); }
void c2r(char s, δ move) { c2 = s, move.step((ξ){c1p}); }
void c2p(ρ read) { read.step((ω){c2l}, c2, (ω){c2r}); }
void c0p(ρ);
char c1 = 0;
void c1l(char s, δ move) { c1 = s, move.step((ξ){c2p}); }
void c1r(char s, δ move) { c1 = s, move.step((ξ){c0p}); }
void c1p(ρ read) { read.step((ω){c1l}, c1, (ω){c1r}); }
void c9p(ρ);
char c0 = 0;
void c0l(char s, δ move) { c0 = s, move.step((ξ){c1p}); }
void c0r(char s, δ move) { c0 = s, move.step((ξ){c9p}); }
void c0p(ρ read) { read.step((ω){c0l}, c0, (ω){c0r}); }

void head(ω l, char v, ω r);
void move(ξ cell) { cell.step((ρ){head}); }

#include <stdio.h>
#include <unistd.h>
void head(ω l, char v, ω r) {
  printf("%c\n", v++), usleep(20000), l.step(v >= 127 ? '0' : v, (δ){move});
}
int main() {
  c0 = '4', c1 = '6', c2 = '1', c3 = '2', c4 = '3', c5 = '5', c6 = '1',
  c7 = '2', c8 = '3', c9 = '0', c0p((ρ){head});
}
