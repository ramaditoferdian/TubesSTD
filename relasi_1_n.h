#ifndef RELASI_1_N_H_INCLUDED
#define RELASI_1_N_H_INCLUDED

#include "parent.h"
#include "child.h"

void deleteSemuaAnak(ListPr &L, adrPr &p);

void deleteAfterChild(ListCh &L, adrCh Q, adrCh &p);


void deleteAnakYgDiCari(ListCh &L, adrCh &p);
void editAnakYgDiCari(ListPr &L, adrPr &x, adrCh &p);

void deleteFirstParent(ListPr &L, adrPr &p);
void deleteAfterParent(ListPr &L, adrPr Q, adrPr &p);
void deleteLastParent(ListPr &L, adrPr &p);

void deleteDataNamaOrtuYgDicari(ListPr &L, adrPr &p);

void deleteAnak(ListPr &L, adrCh &c);
void editAnak(ListPr &L, adrCh &c);

void editDataNamaOrtuYgDicari(ListPr &L, adrPr &p);

void PrintKeluargaDariAnak(ListPr L);

void only_integer(int &angka);

void printSeluruhAnak(ListPr L);


#endif // RELASI_1_N_H_INCLUDED
