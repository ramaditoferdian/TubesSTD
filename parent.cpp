#include "parent.h"
#include "relasi_1_n.h"

#include <iostream>


void CreateListPr(ListPr &L){
    first(L) = NULL;
}

adrPr alokasiPr(string ayah , string ibu){
    adrPr p = new elmListPr;
    //infoPr(p) = x;
    namaAyah(p) = ayah;
    namaIbu(p) = ibu;

    nextPr(p) = NULL;

    createListCh(child(p));

    return p;
}

void insertFirstPr(ListPr &L, adrPr p){
    if(first(L) == NULL){
        first(L) = p;
        nextPr(p) = first(L);
    }else if(nextPr(first(L)) == first(L)){
        nextPr(p) = first(L);
        nextPr(first(L)) = p;
        first(L) = p;
    }else{
        adrPr q = first(L);
        do{
            q = nextPr(q);
        }while(nextPr(q) != first(L));
        nextPr(p) = first(L);
        nextPr(q) = p;
        first(L) = p;
    }
}

void insertAfterPr(ListPr &L, adrPr prec, adrPr p){

    nextPr(p) = nextPr(prec);
    nextPr(prec) = p;

}

void insertLastPr(ListPr &L, adrPr p){
    if(first(L) == NULL){
        first(L) = p;
        nextPr(p) = first(L);
    }else if(nextPr(first(L)) == first(L)){
        nextPr(first(L)) = p;
        nextPr(p) = first(L);
    }else{
        adrPr Q = first(L);
        do{
            Q = nextPr(Q);
        }while(nextPr(Q) != first(L));

        nextPr(Q) = p;
        nextPr(p) = first(L);
    }
}

void deleteFirstPr(ListPr &L, adrPr &p){
    if(first(L) == NULL){
        cout << "Tidak Ada Data" << endl;
    }else if(nextPr(first(L)) == first(L)){
        p = first(L);
        first(L) = NULL;
    }else{
        adrPr Q = first(L);
        do{
            Q = nextPr(Q);
        }while(nextPr(Q) != first(L));

        p = first(L);
        first(L) = nextPr(p);

        nextPr(Q) = first(L);
        nextPr(p) = NULL;
    }
}

void deleteAfterPr(ListPr &L, adrPr prec, adrPr &p){
    p = nextPr(prec);
    nextPr(prec) = nextPr(p);
    nextPr(p) = NULL;
}

void deleteLastPr(ListPr &L, adrPr &p){
    if(first(L) == NULL){
        cout << "Tidak Ada Data" << endl;
    }else if(nextPr(first(L)) == first(L)){
        p = first(L);
        first(L) = NULL;
    }else{
        adrPr Q = first(L);
        do{
            Q = nextPr(Q);
        }while(nextPr(nextPr(Q)) != first(L));

        p = nextPr(Q);
        nextPr(Q) = first(L);
        nextPr(p) = NULL;
    }
}

void printInfoPr(ListPr L){
    adrPr(p) = first(L);
    cout << "List Nama Orang Tua : " << endl;
    cout << "======================" << endl;
    cout << "Ayah & Ibu" << endl;
    cout << "======================" << endl;
    do{
        cout << namaAyah(p) << " & " << namaIbu(p) << endl;

        p = nextPr(p);
    }while(p != first(L));
    cout << endl;
}

void printInfoKeluarga(ListPr L){
    int i = 1;


    adrPr(p) = first(L);


    if(first(L) != NULL){
        cout << "\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1" << endl;
        cout << "\xB1\xB1\xB1\xB1 [ List Keluarga ] \xB1\xB1\xB1\xB1" << endl;
        cout << "\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1" << endl;
        cout << "==================================================" << endl;

        do{

            cout << "Keluarga ke-" << i << endl;
            cout << "---------------" << endl;
            cout << "Nama Ayah   : " << namaAyah(p) << endl;
            cout << "Nama Ibu    : " << namaIbu(p) << endl;

            printInfoCh(child(p));
            cout << "Total Anak  : " << panjangListCh(child(p)) << endl;
            cout << "==================================================" << endl;

            p = nextPr(p);

            i++;
            cout << endl;
        }while(p != first(L));
        cout << endl;

    }else{
        cout << endl;
        cout << "[ TIDAK ADA DATA KELUARGA ]" << endl;
        cout << endl;
    }

}

void HitungBanyakAnak(ListPr L, adrPr &banyak, adrPr &dikit){
    adrPr p;

    if(first(L) != NULL){
        p = first(L);

        banyak = p;
        dikit = p;

        int temp_anak_Terbanyak = panjangListCh(child(p));
        int temp_anak_Terdikit= panjangListCh(child(p));
        do{
            if(temp_anak_Terbanyak < panjangListCh(child(p))){
                temp_anak_Terbanyak = panjangListCh(child(p));
                banyak = p;
            }

            if(temp_anak_Terdikit > panjangListCh(child(p))){
                temp_anak_Terdikit = panjangListCh(child(p));
                dikit = p;
            }
            p = nextPr(p);
        }while(p != first(L));
    }else{
        banyak = NULL;
        dikit = NULL;
    }
}

void tambahKeluarga(ListPr &L){
    int jumlah;
    int i = 0;
    adrPr p;
    string ayah , ibu;

    cin.ignore();
    cout << "Masukan nama Ayah : ";
    getline(cin, ayah);
    cout << "Masukan nama Ibu  : ";
    getline(cin, ibu);


    p = alokasiPr(ayah , ibu);

    insertLastPr(L , p);

    only_integer(jumlah);
    //cout << "Masukan jumlah anak : ";
    //cin >> jumlah;
    cin.ignore();
    while(i < jumlah){

        tambahDataAnak(child(p));
        i++;
    }
    cout << endl;


}

void tambahDataOrangTua(ListPr &L){
    adrPr p;
    string ayah , ibu;

    cin.ignore();
    cout << "Masukan nama Ayah : ";
    getline(cin, ayah);
    cout << "Masukan nama Ibu  : ";
    getline(cin, ibu);

    p = alokasiPr(ayah , ibu);

    insertLastPr(L , p);
    cout << endl;



}

/*
void editDataOrangTua(ListPr &L, adrPr &p){

    string ayah , ibu;

    cout << " EDIT " << endl;

    cout << "Masukan nama Ayah : ";
    cin >> ayah;
    cout << "Masukan nama Ibu  : ";
    cin >> ibu;

    namaAyah(p) = ayah;
    namaIbu(p) = ibu;

}

*/

adrPr findElemen(ListPr L, string ayah, string ibu){
    adrPr p = first(L);
    do{
        if((namaAyah(p) == ayah) && namaIbu(p) == ibu){
            return p;
        }
        p = nextPr(p);
    }while(p != first(L));
    return NULL;
}



void printKeluarga(ListPr L, adrPr p){



    if(first(L) != NULL){

        cout << "\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1" << endl;
        cout << "\xB1\xB1\xB1\xB1 List Keluarga \xB1\xB1\xB1\xB1" << endl;
        cout << "\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1\xB1" << endl;


        cout << "Nama Ayah   : " << namaAyah(p) << endl;
        cout << "Nama Ibu    : " << namaIbu(p) << endl;

        printInfoCh(child(p));
        cout << "Total Anak  : " << panjangListCh(child(p)) << endl;

        p = nextPr(p);


        cout << endl;

        cout << endl;

    }else{
        cout << endl;
        cout << "TIDAK ADA DATA KELUARGA" << endl;
        cout << endl;
    }

}
