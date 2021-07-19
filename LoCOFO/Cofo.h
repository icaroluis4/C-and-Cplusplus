#ifndef _cofo_h
#define _cofo_h
    #ifndef _cofo_c
    #define _cofo_c
        typedef struct _cofo_{
                void **elms;
                int tam;
                int nemls;
        }cofo;
            cofo * cofoCreate(int n);
            int cofDestroy(cofo * c);
            int cofoInsert(cofo *c, void* elm);
            int cofoRemove(cofo *c,void*key);
            int cofoQuery(cofo *c,void*key);
    #else
        typedef struct _cofo_ cofo;

          extern  cofo * cofoCreate(int n);
          extern  int cofDestroy(cofo * c);
          extern  int cofoInsert(cofo *c, void* elm);
          extern  int cofoRemove(cofo *c,void*key);
          extern  int cofoQuery(cofo *c,void*key);
    #endif // _cofo_c

#endif // _cofo_h
