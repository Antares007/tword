n = 2**5
print("""#pragma once
#define A PROGRAMMER_CONCAT(unit, __LINE__)
#define D(...) PROGRAMMER_DISPATCH(PROGRAMMER_NARG(__VA_ARGS__), __VA_ARGS__)
""")
for n in range(2, n+1, 2):
    k = (n - 2) // 2
    params = ["head"] + [f"{x}{i}" for i in range(1, k+1) for x in "oa"] + ["tail"]
    print(f"#define PROGRAMMER_{n}({','.join(params)}) \\")
    print(f"    S(head); S(tail); \\")
    if n == 2:
        print(f"    Δ(tail, 1, tail, head)")
    else:
        print(f"    Δ(tail, o{k}, a{k}, head##_{k}) \\")
        for i in range(k-1, 0, -1):
            print(f"    Δ(head##_{i+1}, o{i}, a{i}, head##_{i}) \\")
        print(f"    Δ(head##_1, 1, tail, head)")
print(f"""
#define PROGRAMMER_DISPATCH(n, ...) PROGRAMMER_DISPATCH_(n, __VA_ARGS__)
#define PROGRAMMER_DISPATCH_(n, ...) PROGRAMMER_##n(__VA_ARGS__)
#define PROGRAMMER_NARG(...) PROGRAMMER_NARG_(__VA_ARGS__, PROGRAMMER_RSEQ_N())
#define PROGRAMMER_NARG_(...) PROGRAMMER_ARG_N(__VA_ARGS__)
#define PROGRAMMER_ARG_N({','.join(f'_{i}' for i in range(1, n + 1))},N,...) N
#define PROGRAMMER_RSEQ_N() {n},{','.join(str(i) for i in range(n - 1, -1, -1))}
#define PROGRAMMER_CONCAT_IMPL(x, y) x##y
#define PROGRAMMER_CONCAT(x, y) PROGRAMMER_CONCAT_IMPL(x, y)
""")
