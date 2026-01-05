#pragma once
#define A PROGRAMMER_CONCAT(unit, __LINE__)
#define D(...) PROGRAMMER_DISPATCH(PROGRAMMER_NARG(__VA_ARGS__), __VA_ARGS__)

#define PROGRAMMER_2(head,tail) \
    S(head); S(tail); \
    Δ(tail, 1, tail, head)
#define PROGRAMMER_4(head,o1,a1,tail) \
    S(head); S(tail); \
    Δ(tail, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define PROGRAMMER_6(head,o1,a1,o2,a2,tail) \
    S(head); S(tail); \
    Δ(tail, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define PROGRAMMER_8(head,o1,a1,o2,a2,o3,a3,tail) \
    S(head); S(tail); \
    Δ(tail, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define PROGRAMMER_10(head,o1,a1,o2,a2,o3,a3,o4,a4,tail) \
    S(head); S(tail); \
    Δ(tail, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define PROGRAMMER_12(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,tail) \
    S(head); S(tail); \
    Δ(tail, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define PROGRAMMER_14(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,tail) \
    S(head); S(tail); \
    Δ(tail, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define PROGRAMMER_16(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,tail) \
    S(head); S(tail); \
    Δ(tail, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define PROGRAMMER_18(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,tail) \
    S(head); S(tail); \
    Δ(tail, o8, a8, head##_8) \
    Δ(head##_8, o7, a7, head##_7) \
    Δ(head##_7, o6, a6, head##_6) \
    Δ(head##_6, o5, a5, head##_5) \
    Δ(head##_5, o4, a4, head##_4) \
    Δ(head##_4, o3, a3, head##_3) \
    Δ(head##_3, o2, a2, head##_2) \
    Δ(head##_2, o1, a1, head##_1) \
    Δ(head##_1, 1, tail, head)
#define PROGRAMMER_20(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,tail) \
    S(head); S(tail); \
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
#define PROGRAMMER_22(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,tail) \
    S(head); S(tail); \
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
#define PROGRAMMER_24(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,tail) \
    S(head); S(tail); \
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
#define PROGRAMMER_26(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,tail) \
    S(head); S(tail); \
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
#define PROGRAMMER_28(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,tail) \
    S(head); S(tail); \
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
#define PROGRAMMER_30(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,o14,a14,tail) \
    S(head); S(tail); \
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
#define PROGRAMMER_32(head,o1,a1,o2,a2,o3,a3,o4,a4,o5,a5,o6,a6,o7,a7,o8,a8,o9,a9,o10,a10,o11,a11,o12,a12,o13,a13,o14,a14,o15,a15,tail) \
    S(head); S(tail); \
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

#define PROGRAMMER_DISPATCH(n, ...) PROGRAMMER_DISPATCH_(n, __VA_ARGS__)
#define PROGRAMMER_DISPATCH_(n, ...) PROGRAMMER_##n(__VA_ARGS__)
#define PROGRAMMER_NARG(...) PROGRAMMER_NARG_(__VA_ARGS__, PROGRAMMER_RSEQ_N())
#define PROGRAMMER_NARG_(...) PROGRAMMER_ARG_N(__VA_ARGS__)
#define PROGRAMMER_ARG_N(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,N,...) N
#define PROGRAMMER_RSEQ_N() 32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
#define PROGRAMMER_CONCAT_IMPL(x, y) x##y
#define PROGRAMMER_CONCAT(x, y) PROGRAMMER_CONCAT_IMPL(x, y)

