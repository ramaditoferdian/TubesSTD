#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

//  Double Linked List dengan Last //

#include <iostream>

using namespace std;

#define first(L) L.first
#define last(L) L.last

#define nextCh(P) P->nextCh
#define prevCh(P) P->prevCh
//#define info(P) P->info
#define namaAnak(P) P->namaAnak

//typedef string infotypeCh;
typedef struct elmListCh *adrCh;

struct elmListCh{
    //infotypeCh info;
    string namaAnak;
    adrCh nextCh;
    adrCh prevCh;
};

struct ListCh{
    adrCh first;
    adrCh last;
};

void createListCh(ListCh &L);
adrCh alokasi(string anak);

void insertFirstCh(ListCh &L, adrCh P);
void insertLastCh(ListCh &L, adrCh P);
void insertAfterCh(ListCh &L, adrCh Prec, adrCh P);

void deleteFirstCh(ListCh &L, adrCh &P);
void deleteLastCh(ListCh &L, adrCh &P);
void deleteAfterCh(ListCh &L,adrCh Prec, adrCh &P);

void printInfoCh(ListCh L);
//adrCh findElement(ListCh L, infotypeCh anak);

int panjangListCh(ListCh L);

void tambahDataAnak(ListCh &L);

void editDataAnak(ListCh &L, adrCh &p);

adrCh findElemenCh(ListCh L, string anak);


#endif // CHILD_H_INCLUDED
