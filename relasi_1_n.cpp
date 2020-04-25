#include "relasi_1_n.h"

#include <stdlib.h>

#include <limits>

using namespace std;


void deleteSemuaAnak(ListPr &L, adrPr &Q){
    adrCh c;
    adrPr p = Q;
    while(first(child(p)) != NULL){
        deleteFirstCh(child(p), c);
        delete c;
    }

    system("pause");
    system("cls");

    cout << endl;
    cout << "[===================]" <<endl;
    cout << "[ BERHASIL DI HAPUS ]" << endl;
    cout << "[===================]" <<endl;
    cout << endl;
}

void deleteAfterChild(ListCh &L, adrCh Q, adrCh &p){
    adrCh prec = first(L);
    while(nextCh(prec) != Q){
        prec = nextCh(prec);
    }
    deleteAfterCh(L,prec,p);
}


void deleteAnakYgDiCari(ListPr &L, adrPr &x, adrCh &p){
    string anak;

    bool cek = true;
    string lagi;
    printKeluarga(L, x);

    while((cek != false) && (first(child(x)) != NULL)){
        //cin.ignore();
        cout << "Masukan nama Anak yang ingin di hapus : ";
        getline(cin, anak);

        system("cls");

        adrCh alamat_anak = findElemenCh(child(x), anak);


        if(alamat_anak == NULL){
            cout << endl;
            cout << "[ ANAK TIDAK DITEMUKAN ]" << endl;
            cout << endl;
        }else{
            if(alamat_anak == first(child(x))){
                //DELETE FIRST CHILD
                deleteFirstCh(child(x), p);

            }else if(alamat_anak == last(child(x))){
                //DELETE LAST CHILD
                deleteLastCh(child(x), p);

            }else{
                //DELETE AFTER CHILD
                deleteAfterChild(child(x), alamat_anak, p);

            }

            system("pause");
            system("cls");

            cout << endl;
            cout << "[===================]" <<endl;
            cout << "[ BERHASIL DI HAPUS ]" << endl;
            cout << "[===================]" <<endl;
            cout << endl;
            printKeluarga(L, x);
            cout << endl;
            cout << "[==========================]" <<endl;
            cout << "[ DATA KELUARGA TER-UPDATE ]" << endl;
            cout << "[==========================]" <<endl;
            cout << endl;



            system("pause");
            system("cls");
        }


        if (first(child(x)) != NULL){
            cout << endl;
            cout << "APAKAH INGIN MENGHAPUS LAGI ? (Y/N) : ";
            getline(cin, lagi);
            //cin >> lagi;
            cout << endl;

            while((lagi != "y") && (lagi != "Y") && (lagi != "n") && (lagi != "N")){
                cout << "[COBA LAGI]" << endl;
                cout << endl;
                cout << "APAKAH INGIN MENGHAPUS LAGI ? (Y/N) : ";
                getline(cin, lagi);
                //cin >> lagi;
                cout << endl;
            }

            if(lagi == "y" || lagi == "Y"){
                cek = true;
                printKeluarga(L, x);
            }else if(lagi == "n" || lagi == "N"){
                cek = false;
            }

        }

    }

}


void editAnakYgDiCari(ListPr &L, adrPr &x, adrCh &p){
    string anak;
    string anakBaru;
    adrCh baru;

    bool cek = true;
    string lagi;
    //printKeluarga(L, x);

    while((cek != false) && (first(child(x)) != NULL)){
        //cin.ignore();
        cout << "Masukan nama Anak yang ingin di edit : ";
        getline(cin, anak);


        //system("cls");

        adrCh alamat_anak = findElemenCh(child(x), anak);

        if(alamat_anak == NULL){
            cout << endl;
            cout << "[ ANAK TIDAK DITEMUKAN ]" << endl;
            cout << endl;
        }else{
            cout << endl;
            cout << "[ ANAK DITEMUKAN ]" << endl;
            cout << endl;
            cout << "Masukan nama Anak terbaru : " ;
            getline(cin, anakBaru);

            namaAnak(alamat_anak) = anakBaru;

            system("pause");
            system("cls");

            cout << endl;
            cout << "[==================]" <<endl;
            cout << "[ BERHASIL DI EDIT ]" << endl;
            cout << "[==================]" <<endl;
            cout << endl;
            printKeluarga(L, x);
            cout << endl;
            cout << "[==========================]" <<endl;
            cout << "[ DATA KELUARGA TER-UPDATE ]" << endl;
            cout << "[==========================]" <<endl;
            cout << endl;

            //system("pause");
            //system("cls");
        }


        if (first(child(x)) != NULL){
            cout << endl;
            cout << "APAKAH INGIN MENGEDIT LAGI ? (Y/N) : ";
            getline(cin, lagi);
            //cin >> lagi;
            cout << endl;

            while((lagi != "y") && (lagi != "Y") && (lagi != "n") && (lagi != "N")){
                cout << "[COBA LAGI]" << endl;
                cout << endl;
                cout << "APAKAH INGIN MENGEDIT LAGI ? (Y/N) : ";
                getline(cin, lagi);
                //cin >> lagi;
                cout << endl;

            }

            if(lagi == "y" || lagi == "Y"){
                cek = true;
                printKeluarga(L, x);
            }else if(lagi == "n" || lagi == "N"){
                cek = false;
            }

        }

    }

}



void deleteFirstParent(ListPr &L, adrPr &p){

    deleteFirstPr(L, p);
}

void deleteAfterParent(ListPr &L, adrPr Q, adrPr &p){ // Q yaitu hasil FindElemen

    adrPr prec = first(L);
    while(nextPr(prec) != Q){
        prec = nextPr(prec);
    }
    deleteAfterPr(L, prec, p);
}


void deleteLastParent(ListPr &L, adrPr &p){

    deleteLastPr(L, p);
}


void deleteDataNamaOrtuYgDicari(ListPr &L, adrPr &p){
    string ayah, ibu;
    adrPr Q;


    cout << "HAPUS KELUARGA BERDASARAKAN NAMA ORANG TUA :  " << endl;
    cout << endl;

    cin.ignore();
    cout << "Masukan nama Ayah : ";
    getline(cin, ayah);
    cout << "Masukan nama Ibu  : ";
    getline(cin, ibu);
    cout << endl;

    Q = findElemen(L, ayah, ibu);

    if(Q == NULL){
        // GAGAL DIHAPUS
        cout << endl;
        cout << "[ TIDAK ADA KELUARGA DENGAN NAMA ORANG TUA TERSEBUT ]" << endl;
        cout << endl;

        printInfoKeluarga(L);

    }else{
        // BERHASIL DIHAPUS


        if(Q == first(L)){
            deleteFirstParent(L,p);
            deleteSemuaAnak(L,Q);
        }else if(nextPr(Q) == first(L)){
            deleteLastParent(L, p);
            deleteSemuaAnak(L,Q);
        }else{
            deleteAfterParent(L,Q,p); // Q hasil FindElemen
            deleteSemuaAnak(L,Q);
        }
        printInfoKeluarga(L);

        cout << endl;
        cout << "[==========================]" <<endl;
        cout << "[ DATA KELUARGA TER-UPDATE ]" << endl;
        cout << "[==========================]" <<endl;
        cout << endl;
    }
}


void deleteAnak(ListPr &L, adrCh &c){
    string ayah, ibu;
    adrPr p;
    adrPr Q;


    cout << "HAPUS ANAK BERDASARAKAN NAMA ORANG TUA :  " << endl;
    cout << endl;

    cin.ignore();
    cout << "Masukan nama Ayah : ";
    getline(cin, ayah);
    cout << "Masukan nama Ibu  : ";
    getline(cin, ibu);
    cout << endl;

    Q = findElemen(L, ayah, ibu);


    if(Q == NULL){
        cout << endl;
        cout << "[ TIDAK ADA ANAK DENGAN NAMA ORANG TUA TERSEBUT ]" << endl;
        cout << endl;

    }else if(first(child(Q)) == NULL){
        cout << endl;
        cout << "[ KELUARGA INI TIDAK MEMILIKI ANAK ]" << endl;
        cout << endl;
    }else{
        if(Q == first(L)){
            cout << endl;
            cout << "[ NAMA ORANG TUA DITEMUKAN ]" << endl;
            deleteAnakYgDiCari(L, Q, c);
        }else if(nextPr(Q) == first(L)){
            cout << endl;
            cout << "[ NAMA ORANG TUA DITEMUKAN ]" << endl;
            deleteAnakYgDiCari(L, Q, c);
        }else{
            cout << endl;
            cout << "[ NAMA ORANG TUA DITEMUKAN ]" << endl;
            deleteAnakYgDiCari(L, Q, c);
        }

    }


}

void editAnak(ListPr &L, adrCh &c){
    string ayah, ibu;
    adrPr p;
    adrPr Q;



    if(first(L) != NULL){

        cout << "EDIT ANAK BERDASARAKAN NAMA ORANG TUA :  " << endl;
        cout << endl;
        cin.ignore();
        cout << "Masukan nama Ayah : ";
        getline(cin, ayah);
        cout << "Masukan nama Ibu  : ";
        getline(cin, ibu);
        cout << endl;

        Q = findElemen(L, ayah, ibu);



        if(Q == NULL){
            cout << endl;
            cout << "[ TIDAK ADA ANAK DENGAN NAMA ORANG TUA TERSEBUT ]" << endl;
            cout << endl;
        }else if(first(child(Q)) == NULL){
            cout << endl;
            cout << "[ KELUARGA INI TIDAK MEMILIKI ANAK ]" << endl;
            cout << endl;
        }else{
            printKeluarga(L, Q);
            if(Q == first(L)){
                cout << endl;
                cout << "[ KELUARGA DITEMUKAN ]" << endl;
                editAnakYgDiCari(L, Q, c);
            }else if(nextPr(Q) == first(L)){
                cout << endl;
                cout << "[ KELUARGA DITEMUKAN ]" << endl;
                editAnakYgDiCari(L, Q, c);
            }else{
                cout << endl;
                cout << "[ KELUARGA DITEMUKAN ]" << endl;
                editAnakYgDiCari(L, Q, c);
            }
        }

    }else{
        /*
        cout << endl;
        cout << "[ LIST KOSONG ]" << endl;
        cout << endl;
        */
    }
}

void editDataNamaOrtuYgDicari(ListPr &L, adrPr &p){
    string ayah, ibu;
    string ayahBaru, ibuBaru;
    adrPr Q;


    if(first(L) != NULL ){


        cin.ignore();
        cout << "Masukan nama Ayah yang di cari : ";
        getline(cin, ayah);
        cout << "Masukan nama Ibu yang di cari  : ";
        getline(cin, ibu);

        Q = findElemen(L, ayah, ibu);

        if(Q == NULL){
            cout << endl;
            cout << "[ TIDAK ADA KELUARGA DENGAN NAMA ORANG TUA TERSEBUT ]" << endl;
            cout << endl;
        }else if(Q != NULL){
            cout << endl;
            cout << "[ NAMA ORANG TUA DITEMUKAN ]" << endl;
            cout << endl;

            printKeluarga(L, Q);

            cout << "Masukan nama Ayah yang baru : ";
            getline(cin, ayahBaru);
            cout << "Masukan nama Ibu yang baru  : ";
            getline(cin, ibuBaru);

            if((namaAyah(Q) == ayah) && (namaIbu(Q) == ibu)){
                namaAyah(Q) = ayahBaru;
                namaIbu(Q) = ibuBaru;

                system("pause");
                system("cls");

                cout << endl;
                cout << "[==================]" <<endl;
                cout << "[ BERHASIL DI EDIT ]" << endl;
                cout << "[==================]" <<endl;
                cout << endl;
                printKeluarga(L, Q);
                cout << endl;
                cout << "[==========================]" <<endl;
                cout << "[ DATA KELUARGA TER-UPDATE ]" << endl;
                cout << "[==========================]" <<endl;
                cout << endl;
            }
        }
    }else{
        cout << endl;
        cout << "[ LIST KOSONG ]" << endl;
        cout << endl;
    }

}



void PrintKeluargaDariAnak(ListPr L){

    cout << "CARI IDENTITAS ANAK" << endl;
    cout << "-------------------" << endl;


    adrPr p;
    int bukti = 0;
    string cariAnak;

    p = first(L);



    if(first(L) != NULL){

        printSeluruhAnak(L);

        cin.ignore();
        cout << "Masukan Nama Anak : ";
        getline(cin, cariAnak);
        do{
            if(first(child(p)) != NULL){
                adrCh Q = first(child(p));
                while(Q != NULL){
                    if(namaAnak(Q) == cariAnak){

                        cout << endl;
                        cout << "==================================" << endl;
                        cout << "       [ KELUARGA DITEMUKAN ]     " << endl;
                        cout << endl;
                        cout << "Nama Anak : " << namaAnak(Q) << endl;
                        cout << "[ ORANG TUA ]" << endl;
                        cout << "Nama Ayah : " << namaAyah(p) << endl;
                        cout << "Nama Ibu  : " << namaIbu(p) << endl;
                        cout << "==================================" << endl;
                        cout << endl;

                        bukti = bukti + 1;
                    }

                    Q = nextCh(Q);
                }
            }

            p = nextPr(p);
        }while(p != first(L));

        if(bukti == 0){
            cout << endl;
            cout << "[ ANAK TERSEBUT TIDAK ADA PADA DATA KELUARGA ]" << endl;
            cout << endl;
        }

    }else{

        printSeluruhAnak(L);
        //printInfoKeluarga(L); // LIST KOSONG = TIDAK ADA DATA KELUARGA
    }

}

void only_integer(int &angka){


  while (true)
  {
    cout << "Masukan jumlah anak : " ;
    cin >> angka;
    cout << endl;
    if (!cin)
    {

      cout << "[INVALID]" << endl;
      cout << endl;

      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    else break;
  }
}

void printSeluruhAnak(ListPr L){
    //int i = 1;


    adrPr(p) = first(L);


    if(first(L) != NULL){
        cout << "List Nama Anak : " << endl;
        cout << "=================" << endl;


        do{

            adrCh z = first(child(p));

            while(z != NULL){
                cout<<namaAnak(z)<<endl;
                z = nextCh(z);
            }

            p = nextPr(p);

        }while(p != first(L));
        cout << endl;

    }else{
        cout << endl;
        cout << "[ TIDAK ADA DATA ANAK]" << endl;
        cout << endl;
    }

}



