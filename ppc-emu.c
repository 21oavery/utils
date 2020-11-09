#include <stdint.h>

#define S_FLAG_64 1

struct env {
    uint64_t special_flags;
    uint64_t xregs[31];
    uint64_t sp;
    uint64_t pc;
    uint128_t vregs[32];
}

typedef void (*ins_call_t)(struct env *);
#define GINS(name) (&_ins_##name)
#define INS(name) void _ins_##name(struct env *_ENV)

INS() {
}
