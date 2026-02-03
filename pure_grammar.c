#define N(argo) void argo(void *rdi, void *rsi, void *rdx, void *rcx, struct ray_t *r8, long r9)
#define S static N
#define Context rdi, rsi, rdx, rcx, r8, r9
enum { Pink, Blue, Green, Yellow, Red };
typedef struct ray_t { N((*rdi)); N((*rsi)); struct ray_t *r8; char color; } ray_t;
typedef N((*s_t));

S(not) { ((s_t)rdi)(Context); }
S(and) { ((s_t)rsi)(Context); }
S(or) { ((s_t)rdx)(Context); }

extern int printf(const char *__restrict __format, ...);
S(S0);
S(b) { r9 = 1, and(Context); }
S(a) { 
  int prev = (int)(r9 >> 32);           // Extract high 4 bytes
  int current = (int)(r9 & 0xFFFFFFFF); // Extract low 4 bytes
  int next = prev + current;            // Calculate next Fibonacci
  r9 = ((long)current << 32) | next;
  (next < 144 ? and : not)(Context);
}

N(S12) { ((s_t)rdx)(a,   not, rdx, rcx, r8, r9); }
N(S11) { ((s_t)rcx)(S0,  S12, rdx, rcx, r8, r9); }
N(S1 ) { ((s_t)rsi)(S11, not, rdx, rcx, r8, r9); }

N(S01) { ((s_t)rdx)(b,   S1,  rdx, rcx, r8, r9); }
N(S0 ) { ((s_t)rsi)(S01, S1,  rdx, rcx, r8, r9); }

S(gram);
S(accept) { 
  int prev = (int)(r9 >> 32);            // Extract high 4 bytes
  int current = (int)(r9 & 0xFFFFFFFF);  // Extract low 4 bytes
  printf("%d x %d = %d\n", prev, current, prev * current);
}
int main() { gram(S0, accept, 0, 0, 0, 0); }

S(Red_1); S(Red_0); S(Red_3);
S(Yellow_1); S(Yellow_3);
S(Green_0); S(Green_2); S(Green_3);
S(Blue_0); S(Blue_2); S(Blue_3);
S(bktrk) {}

S(gram) {
  ((s_t)rdi)(bktrk, Red_1, Green_2, Red_3, &(ray_t){rdi, rsi, r8, Pink}, r9);
}

S(Red_1) {
  ((s_t)rdi)(Red_0, Red_0, Green_2, Red_3, r8, r9);
  ((s_t)rsi)(bktrk, Red_1, Green_2, Red_3, r8, r9);
}
S(Red_0) {
  if (r8->color == Red) r8->rsi(Red_0, Red_0, Green_2, Red_3, r8->r8, r9);
  else if (r8->color == Blue) r8->rsi(Blue_0, Blue_0, Blue_2, Blue_3, r8->r8, r9);
  else r8->rsi(Green_0, Green_0, Green_2, Green_3, r8->r8, r9);
}
S(Red_3) {
  ray_t *d = r8;
  while (1) {
    if (d->rdi == rdi) return bktrk(Context);
    if (d->color != Red)
      return ((s_t)rdi)(bktrk, Red_1, Green_2, Red_3, &(ray_t){rdi, rsi, r8, Red}, r9);
    d = d->r8;
  }
}
S(Yellow_1) {
  ((s_t)rdi)(bktrk, bktrk, bktrk, Yellow_3, r8, r9);
  ((s_t)rsi)(bktrk, Yellow_1, bktrk, Yellow_3, r8, r9);
}
S(Yellow_3) {
  ray_t *d = r8;
  for (; d->color == Yellow; d = d->r8) if (d->rdi == rdi) return bktrk(Context);
  if (d->rdi == rdi) ((s_t)rsi)(Blue_0, Blue_0, Blue_2, Blue_3, r8, r9);
  else ((s_t)rdi)(bktrk, Yellow_1, bktrk, Yellow_3, &(ray_t){rdi, rsi, r8, Yellow}, r9);
}
S(Green_not) {
  if (r8->color == Blue)
    r8->rsi(Blue_0, Blue_0, Blue_2, Blue_3, r8->r8, r9);
  else r8->rsi(Green_0, Green_0, Green_2, Green_3, r8->r8, r9);
}
S(Green_and) { ((s_t)rcx)(Green_0, Green_0, Green_2, Green_3, r8, r9); }
S(Green_0) {
  Green_not(Context);
  ((s_t)r8->rdi)(bktrk, Yellow_1, bktrk, Yellow_3, r8, r9);
}
S(Green_2) { ((s_t)rdi)(Green_not, Green_and, bktrk, rsi, r8, r9); }
S(Green_3) {
  ((s_t)rdi)(bktrk, Red_1, Green_2, Red_3, &(ray_t){rdi, rsi, r8, Green}, r9);
}
S(Blue_not) {
  if (r8->color == Yellow || r8->color == Blue)
    ((s_t)r8->rsi)(Blue_0, Blue_0, Blue_2, Blue_3, r8->r8, r9);
  else ((s_t)r8->rsi)(Green_0, Green_0, Green_2, Green_3, r8->r8, r9);
}
S(Blue_and) {
  ((s_t)rcx)(Blue_0, Blue_0, Blue_2, Blue_3, r8, r9);
}
S(Blue_0) {
  Blue_not(Context);
  if (r8->color == Yellow) return bktrk(Context);
  ((s_t)r8->rdi)(bktrk, Yellow_1, bktrk, Yellow_3, r8, r9);
}
S(Blue_2) {
  ((s_t)rdi)(Blue_not, Blue_and, bktrk, rsi, r8, r9);
}
S(Blue_3) {
  ((s_t)rdi)(bktrk, Red_1, Green_2, Red_3, &(ray_t){rdi, rsi, r8, Blue}, r9);
}
