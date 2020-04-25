#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

// Cicular Single Linked List Tanpa Last //

#include <iostream>
#include "child.h"

using namespace std;

#define first(L) L.first

#define nextPr(P) P->nextPr

#define namaAyah(P) P->namaAyah
#define namaIbu(P) P->namaIbu

#define child(P) P->child


typedef struct elmListPr *adrPr;

struct elmListPr{

    string namaAyah;
    string namaIbu;
    adrPr nextPr;

    ListCh child;
};

struct ListPr{
    adrPr first;
};

void CreateListPr(ListPr &L);
adrPr alokasiPr(string ayah , string ibu);

void insertFirstPr(ListPr &L, adrPr p);
void insertAfterPr(ListPr &L, adrPr prec, adrPr p);
void insertLastPr(ListPr &L, adrPr p);


void deleteFirstPr(ListPr &L, adrPr &p);
void deleteAfterPr(ListPr &L, adrPr prec, adrPr &p);
void deleteLastPr(ListPr &L, adrPr &p);

void printInfoPr(ListPr L);
void printInfoKeluarga(ListPr L);
void HitungBanyakAnak(ListPr L, adrPr &banyak, adrPr &dikit);

void tambahKeluarga(ListPr &L);
void tambahDataOrangTua(ListPr &L);

//void editDataOrangTua(ListPr &L, adrPr &p);

adrPr findElemen(ListPr L, string ayah, string ibu);

void printKeluarga(ListPr L, adrPr p);

#endif // PARENT_H_INCLUDED
