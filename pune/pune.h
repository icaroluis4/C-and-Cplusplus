#include <stdlib.h>


    typedef struct _Stack{
    int top;
    int maxElms;
    void **elms;
}Stack;


    Stack *stkCreate(int);
    int stkDestroy(Stack*);
    int stkPush(Stack*,void*);
    void *stkPop(Stack *tmp);
    int stkIsEmpty(Stack*);
    void* stkTop(Stack*);
