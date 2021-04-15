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
    struct _lval val;
    struct _lnode *next;
    size_t ref_cnt;
} LNode;

typedef struct _lval {
    int type;
    union {
        LString lstring;
        LInt lint;
        LDouble ldouble;
        LNode lnode;
    }
} LVal;

typedef 
