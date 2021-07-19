/*
#ifndef cofog_h_
   #define cofo_h_
    #ifndef cofo_c_
     #definecofo_c_

        typedef struct _cofoger_{
            void* *elms;
            int nmax;
            int nelms;
        }cofonum;
        cofonum * cofoCreate(int tam);
        int cofoDestroy(cofonum * c);
        int cofoInsert(cofonum *c, void* elm);
        int cofoRemove(cofonum * c, void* key);
        int cofoPesquisa(cofonum * c, void* key);
    #else
        typedef struct _cofoger_{
            void* *elms;
            int nmax;
            int nelms;
        }cofonum;
        cofonum * cofoCreate(int tam);
        int cofoDestroy(cofonum * c);
        int cofoInsert(cofonum *c, void* elm);
        int cofoRemove(cofonum * c, void* key);
        int cofoPesquisa(cofonum * c, void* key);
    #endif // cofo_c_
#endif
*/
