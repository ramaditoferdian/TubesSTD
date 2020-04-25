#include "child.h"
#include <iostream>

void createListCh(ListCh &L){
    first(L) = NULL;
    last(L) = NULL;
}

adrCh alokasiCh(string anak){
    adrCh P = new elmListCh;
    //info(P) = anak;
    namaAnak(P) = anak;
    nextCh(P) = NULL;
    prevCh(P) = NULL;
    return P;

}

void insertFirstCh(ListCh &L, adrCh P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else {
        nextCh(P) = first(L);
        prevCh(first(L)) = P;
        first(L) = P;
    }
}

void insertLastCh(ListCh &L, adrCh P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else {
        nextCh(last(L)) = P;
        prevCh(P) = last(L);
        last(L) = P;
    }
}

void insertAfterCh(ListCh &L, adrCh Prec, adrCh P){

    nextCh(P) = nextCh(Prec);
    prevCh(P) = Prec;
    nextCh(Prec) = P;
    prevCh(nextCh(P)) = P;



}

void deleteFirstCh(ListCh &L, adrCh &P){
    P = first(L);
    if(nextCh(P) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        first(L) = nextCh(P);
        prevCh(first(L)) = NULL;
        nextCh(P) = NULL;
    }
}
void deleteLastCh(ListCh &L, adrCh &P){
    if(first(L) == last(L)){
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = last(L);
        last(L) = prevCh(P);
        prevCh(P) = NULL;
        nextCh(last(L)) = NULL;
    }
}
void deleteAfterCh(ListCh &L,adrCh Prec, adrCh &P){
    P = nextCh(Prec);
    nextCh(Prec) = nextCh(P);
    prevCh(nextCh(Prec)) = Prec;
    prevCh(P) = NULL;
    nextCh(P) = NULL;
}



void printInfoCh(ListCh L){
    adrCh P = first(L);
    int banyakAnak = 0;
    cout<<"Daftar Anak : ";
    while(P != NULL){
        cout<<namaAnak(P)<<", ";
        P = nextCh(P);
    }
    cout<<endl;
}

/*adrCh findElement(ListCh L, infotypeCh anak){
    adrCh P = first(L);
    while(P != NULL){
        if(info(P) == anak){
            return P;
        }
        P = nextCh(P);
    }
    return NULL;
}*/
int panjangListCh(ListCh L){
    int i = 0;


    adrCh Q = first(L);

    while(Q != NULL){
        i++;
        Q = nextCh(Q);
    }
    return i;

}
void tambahDataAnak(ListCh &L){
    int panjangList = panjangListCh(L);
    adrCh p;
    string anak;

    //cin.ignore();
    cout << "Masukan nama Anak ke-" << panjangList+1 << " : ";
    getline(cin, anak);


    p = alokasiCh(anak);

    insertLastCh(L,p);

    cout << endl;
}

void editDataAnak(ListCh &L, adrCh &p){
    string anak;


    cout << "Masukan nama Anak : " ;
    cin >> anak;

    p = alokasiCh(anak);
}

adrCh findElemenCh(ListCh L, string anak){
    adrCh p = first(L);
    while(p != NULL){
        if(namaAnak(p) == anak){
            return p;
        }
        p = nextCh(p);
    }
    return NULL;
}
