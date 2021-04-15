#include <stdlib.h>
#include <stdio.h>

#define TYPE_STRING 0
typedef struct {
    char *data;
    size_t len;
} LString;

#define TYPE_INT 1
typedef struct {
    int val;
} LInt;

#define TYPE_DOUBLE 2
typedef struct {
    double val;
} LDouble;

#define TYPE_NODE 3
typedef struct _lnode {
    struct _lval car;
    struct _lval cdr;
} LNode;

#define TYPE_CALL 4
typedef struct {
    LVal (*call)(void *, LNode *);
    void (*dealloc)(void *);
    void *data;
} LCall;

typedef struct _lval {
    int type;
    size_t ref_cnt;
    union {
        LString lstring;
        LInt lint;
        LDouble ldouble;
        LNode lnode;
        LCall lcall;
    } inner;
} LVal;

void free_lval(LVal *val) {
    if (

// Does not handle reference counts
char *try_get_str(LVal *val) {
    if (val->type != TYPE_STRING) return NULL;
    return val->inner.lstring.data;
}

char *try_get_str(LVal *val) {
    

// builtin: defun, car, cdr
