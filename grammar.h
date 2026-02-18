#pragma once
#define A Γ_CONCAT(unit, __LINE__)
#define D(...) Γ_DISPATCH(Γ_NARG(__VA_ARGS__), __VA_ARGS__)

#define Γ_1(head) \
    Γ(head);
#define Γ_2(head,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, 1, tail, head)
#define Γ_4(head,o1,a1,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_6(head,o1,a1,o2,a2,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_8(head,o1,a1,o2,a2,o3,a3,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_10(head,o1,a1,o2,a2,o3,a3,o4,a4,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_12(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_14(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_16(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_18(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_20(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o9, a9, head##_9) \
    Δ(head##_9, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define Γ_22(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o10, a10, head##_10) \
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
#define Γ_24(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o11, a11, head##_11) \
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
#define Γ_26(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o12, a12, head##_12) \
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
#define Γ_28(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o13, a13, head##_13) \
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
#define Γ_30(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,o14,a14,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o14, a14, head##_14) \
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
#define Γ_32(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,o14,a14,o15,a15,tail) \
    Γ(head); Γ(tail); \
    Δ(tail, o15, a15, head##_15) \
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

#define Γ_DISPATCH(n, ...) Γ_DISPATCH_(n, __VA_ARGS__)
#define Γ_DISPATCH_(n, ...) Γ_##n(__VA_ARGS__)
#define Γ_NARG(...) Γ_NARG_(__VA_ARGS__, Γ_RSEQ_N())
#define Γ_NARG_(...) Γ_ARG_N(__VA_ARGS__)
#define Γ_ARG_N(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,N,...) N
#define Γ_RSEQ_N() 32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
#define Γ_CONCAT_IMPL(x, y) x##y
#define Γ_CONCAT(x, y) Γ_CONCAT_IMPL(x, y)

