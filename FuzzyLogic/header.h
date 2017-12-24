#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <cstdlib>
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
using namespace std;

struct member{
    string state;
    double value;
};

typedef member infotype;
typedef struct ElmList *adr;

struct ElmList{
    infotype info;
    adr next;
};

struct List{
    adr first;
    adr last;
};


void createList(List &L);
adr alocate(infotype x);
void inLa(List &L, adr P);
void clearList(List &L);
void showList(List L);
void mfEmo(List &L, int x);
void mfPro(List &L, int x);
int countList(List L);
void infMember(List L);

#endif // HEADER_H_INCLUDED
