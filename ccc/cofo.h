
#ifndef _cofo_h_
  #define _cofo_h_
  #ifndef _cofo_c
    #define _cofo_c
        typedef struct _cofonum_{
            int *elms;
            int nmax;
            int nelms;
        }cofonum;
        cofonum * cofoCreate(int tam);
        int cofoDestroy(cofonum * c);
        int cofoInsert(cofonum *c, int elm);
        int cofoRemove(cofonum * c, int key);
        int cofoPesquisa(cofonum * c, int key);

    #else
            typedef struct _cofoger_{
            int *elms;
            int nmax;
            int nelms;
        }cofonum;;

            extern  cofoDestroy(cofonum * c);
            extern  cofoInsert(cofonum *c, int elm);
            extern  cofoRemove(cofonum * c, int key);
            extern  cofoPesquisa(cofonum * c, int key);
    #endif // _cofo_c
#endif // _cofo_h_
