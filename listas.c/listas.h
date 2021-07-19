#ifndef LISTAS_H_INCLUDED
    #define LISTAS_H_INCLUDED

    #define TRUE 1
    #define FALSE 0



    #ifndef _LISTAS_C_
        #define _LISTAS_C_

                        typedef struct _dlnode_{
                        struct _dlnode_ *next;
                        struct _dlnode_ *prev;
                        void *data;
                    } dlnode;

                    typedef struct _dllist_{
                        dlnode *first;
                        dlnode *cur;
                    } dllist;


                dllist *dllCreate();
                int dllInsertFirst(dllist *l, void *data);
                int dllInsertAfterSpec(dllist *l, void *data, int(*cmp)(void*, void*), void *key);
                int dllInsertBeforeSpec (dllist *l, void *data, int(*cmp)(void*, void*), void *key);
                void *dllRemoveFirst(dllist *l);
                void *dllRemoveSpec(dllist *l, int(*cmp)(void*, void*), void *key);
                //void *sllQuery(sllist *l,int(*cmp)(void*,void*),void *key);
                int dllDestroy (dllist *l);
                int dllQuery(dllist *l , void * key);
                void dllShow(dllist *l);
                int cmp(void *a,void *b);


     #else
             typedef struct _dlnode_{
                    struct _dlnode_ *next;
                    struct _dlnode_ *prev;
                    void *data;
                } dlnode;

                typedef struct _dllist_{
                    dlnode *first;
                    dlnode *cur;
                } dllist;


            extern dllist *dllCreate();
            extern int dllInsertFirst(dllist *l, void *data);
            extern int dllInsertAfterSpec(dllist *l, void *data, int(*cmp)(void*, void*), void *key);
            extern int dllInsertBeforeSpec (dllist *l, void *data, int(*cmp)(void*, void*), void *key);
            extern void *dllRemoveFirst(dllist *l);
            extern void *dllRemoveSpec(dllist *l, int(*cmp)(void*, void*), void *key);
            //extern void *sllQuery(sllist *l,int(*cmp)(void*,void*),void *key);
            extern int dllDestroy (dllist *l);
            int dllQuery(dllist *l , void * key);
            extern void dllShow(dllist *l);
            extern int cmp(void *a,void *b);



    #endif // _LISTAS_C_
#endif // LISTAS_H_INCLUDED

