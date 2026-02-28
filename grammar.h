#pragma once
#define A GRAMMAR_CONCAT(unit, __LINE__)
#define D(...) GRAMMAR(__VA_ARGS__)
#define Γ(n) void n(ο s, δ d, β b, τ t)
#define Δ_1(next, unit, name) Γ(name) { b.step(s, (γ){unit}, (γ){next}); }
#define Δ_2(next, unit, name) Γ(name) { t.step(s,     unit , (γ){next}); }
#define Δ_(next, op, unit, name) Δ_##op(next, unit, name)
#define Δ(...) Δ_(__VA_ARGS__)
#define GRAMMAR(...) GRAMMAR_DISPATCH(GRAMMAR_NARG(__VA_ARGS__), __VA_ARGS__)
#define GRAMMAR_DISPATCH(n, ...) GRAMMAR_DISPATCH_(n, __VA_ARGS__)
#define GRAMMAR_DISPATCH_(n, ...) GRAMMAR_##n(__VA_ARGS__)

#define GRAMMAR_1(head) Γ(head);
#define GRAMMAR_2(head,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, 1, tail, head)
#define GRAMMAR_4(head,o1,a1,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_6(head,o1,a1,o2,a2,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_8(head,o1,a1,o2,a2,o3,a3,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_10(head,o1,a1,o2,a2,o3,a3,o4,a4,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_12(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_14(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_16(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_18(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_20(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o9, a9, head##_9) \
    Δ(head##_9, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_22(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o10, a10, head##_10) \
    Δ(head##_10, o9, a9, head##_9) \
    Δ(head##_9, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_24(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o11, a11, head##_11) \
    Δ(head##_11, o10, a10, head##_10) \
    Δ(head##_10, o9, a9, head##_9) \
    Δ(head##_9, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_26(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o12, a12, head##_12) \
    Δ(head##_12, o11, a11, head##_11) \
    Δ(head##_11, o10, a10, head##_10) \
    Δ(head##_10, o9, a9, head##_9) \
    Δ(head##_9, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_28(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o13, a13, head##_13) \
    Δ(head##_13, o12, a12, head##_12) \
    Δ(head##_12, o11, a11, head##_11) \
    Δ(head##_11, o10, a10, head##_10) \
    Δ(head##_10, o9, a9, head##_9) \
    Δ(head##_9, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_30(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,o14,a14,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o14, a14, head##_14) \
    Δ(head##_14, o13, a13, head##_13) \
    Δ(head##_13, o12, a12, head##_12) \
    Δ(head##_12, o11, a11, head##_11) \
    Δ(head##_11, o10, a10, head##_10) \
    Δ(head##_10, o9, a9, head##_9) \
    Δ(head##_9, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define GRAMMAR_32(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,o14,a14,o15,a15,tail) \
    Γ(head);Γ(tail); \
    Δ(dot, o15, a15, head##_15) \
    Δ(head##_15, o14, a14, head##_14) \
    Δ(head##_14, o13, a13, head##_13) \
    Δ(head##_13, o12, a12, head##_12) \
    Δ(head##_12, o11, a11, head##_11) \
    Δ(head##_11, o10, a10, head##_10) \
    Δ(head##_10, o9, a9, head##_9) \
    Δ(head##_9, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)

#define GRAMMAR_NARG(...) GRAMMAR_NARG_(__VA_ARGS__, GRAMMAR_RSEQ_N())
#define GRAMMAR_NARG_(...) GRAMMAR_ARG_N(__VA_ARGS__)
#define GRAMMAR_ARG_N(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,N,...) N
#define GRAMMAR_RSEQ_N() 32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
#define GRAMMAR_CONCAT_IMPL(x, y) x##y
#define GRAMMAR_CONCAT(x, y) GRAMMAR_CONCAT_IMPL(x, y)

