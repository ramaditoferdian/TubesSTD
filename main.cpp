#include <iostream>
#include "parent.h"
#include "child.h"
#include "relasi_1_n.h"




#include <stdlib.h>


/*
    TARGET :    - Prosedur Tambah Data Keluarga + jumlah anaknya                    ✔
                - Membuat prosedur untuk hapus data anak dari keluarga              ✔
                - Prosedur Tampilkan Keluarga dengan Anak terbanyak dan sedikit     ✔
                - Prosedur Edit data Orang Tua & data Anak                          ✔
                - Prosedur Menampilkan Keluarga berdasarkan nama Ayah & Ibu         ✔
                - Prosedur Edit Data Keluarga                                       ✖

                - Memperbaiki Tampilan Menu     ✖
                - Menambahkan Error Handling    1/2

                - Memperbaiki Menu 4_5   !!!!!!



    FIXED :     - Menu edit
                - Menu hapus ???? [cek lagi]
                - Menu tambah ??? [cek lagi]

*/

using namespace std;

// KUMPULAN FUNGSI DAN PROSEDUR //

void MenuUtama(){
    cout << "#===========================================#" << endl;
    cout << "|              SELAMAT DATANG               |" << endl;
    cout << "|       DI APLIKASI PENDATAAN KELUARGA      |" << endl;
    cout << "|===========================================|" << endl;
    cout << "| HALAMAN UTAMA APLIKASI PENDATAAN KELUARGA |" << endl;
    cout << "|===========================================|" << endl;
    cout << "| [1]. Tambah Data                          |" << endl;       // ✔
    cout << "| [2]. Hapus Data                           |" << endl;        // ✔
    cout << "| [3]. Edit Data                            |" << endl;
    cout << "| [4]. Tampilkan Data                       |" << endl;
    cout << "| [0]. Keluar                               |" << endl;
    cout << "#===========================================#" << endl;

}
void Menu_1(){
    cout << "|=========================|" << endl;
    cout << "|   HALAMAN TAMBAH DATA   |" << endl;
    cout << "|=========================|" << endl;
    cout << "| [1]. Data Keluarga      |" << endl;     // ✔
    cout << "| [2]. Data Orang Tua     |" << endl;    // ✔
    cout << "| [3]. Data Anak          |" << endl;         // ✔
    cout << "| [0]. Menu Utama         |" << endl;
    cout << "|=========================|" << endl;
}

void Menu_2(){
    cout << "|==========================|" << endl;
    cout << "|    HALAMAN HAPUS DATA    |" << endl;
    cout << "|==========================|" << endl;
    cout << "| [1]. Data Keluarga       |" << endl;      // ✔
    cout << "| [2]. Data Anak           |" << endl;          // ✔
    cout << "| [0]. Menu Utama          |" << endl;
    cout << "|==========================|" << endl;
}

void Menu_3(){
    cout << "|=========================|" << endl;
    cout << "|    HALAMAN EDIT DATA    |" << endl;
    cout << "|=========================|" << endl;
    cout << "| [1]. Data Keluarga      |" << endl;
    cout << "| [2]. Data Orang Tua     |" << endl;    // ✔
    cout << "| [3]. Data Anak          |" << endl;         // ✔
    cout << "| [0]. Menu Utama         |" << endl;
    cout << "|=========================|" << endl;
}

void Menu_4(){
    cout << "|===================================================|" << endl;
    cout << "|               HALAMAN TAMPILKAN DATA              |" << endl;
    cout << "|===================================================|" << endl;
    cout << "| [1]. Data Seluruh Keluarga                        |" << endl;     // ✔
    cout << "| [2]. Data Keluarga yang Memiliki Anak Terbanyak   |" << endl;    // ✔
    cout << "| [3]. Data Keluarga yang Memiliki Anak Terdikit    |" << endl;         // ✔
    cout << "| [4]. Data Keluarga Berdasarkan Nama Orang Tua     |" << endl;         // ✔
    cout << "| [5]. Data Orang Tua Berdasarkan Nama Anak         |" << endl;
    cout << "| [0]. Menu Utama                                   |" << endl;
    cout << "|===================================================|" << endl;
}

void TambahData_Keluarga(ListPr &L){
    cout << "TAMBAH DATA KELUARGA" << endl;
    cout << "--------------------" << endl;
    tambahKeluarga(L);

    cout << "[=======================]" <<endl;
    cout << "[ BERHASIL DI TAMBHAKAN ]" << endl;
    cout << "[=======================]" <<endl;
    cout << endl;

    system("pause");
    system("cls");

    printInfoKeluarga(L);

    cout << "[==========================]" <<endl;
    cout << "[ DATA KELUARGA TER-UPDATE ]" << endl;
    cout << "[==========================]" <<endl;
    cout << endl;
}

void TambahData_OrangTua(ListPr &L){
    cout << "TAMBAH DATA ORANG TUA" << endl;
    cout << "-------------------- " << endl;

    tambahDataOrangTua(L);

    cout << "[=======================]" <<endl;
    cout << "[ BERHASIL DI TAMBHAKAN ]" << endl;
    cout << "[=======================]" <<endl;
    cout << endl;

    system("pause");
    system("cls");

    printInfoKeluarga(L);

    cout << "[==========================]" <<endl;
    cout << "[ DATA KELUARGA TER-UPDATE ]" << endl;
    cout << "[==========================]" <<endl;
    cout << endl;
}

void TambahData_AnakKeKeluarga(ListPr &L){
    string cariAyah, cariIbu;

    cout << "TAMBAH DATA ANAK KE KELUARGA" << endl;
    cout << "----------------------------" << endl;


    printInfoKeluarga(L);

    if(first(L) != NULL){
        cout << "CARI KELUARGA BERDASARAKAN NAMA ORANG TUA :  " << endl;
        cout << endl;

        cin.ignore();
        cout << "Nama Ayah : ";
        getline(cin, cariAyah);
        cout << "Nama Ibu  : ";
        getline(cin, cariIbu);
        adrPr p = findElemen(L, cariAyah , cariIbu);
        if(p == NULL){
            cout << endl;
            cout << "[ KELUARGA TIDAK DITEMUKAN ]" << endl;
            cout << endl;
        }else{
            cout << endl;
            cout << "[ KELUARGA DITEMUKAN ]" << endl;
            cout << endl;
            printKeluarga(L, p);
            tambahDataAnak(child(p));

            cout << "[=======================]" <<endl;
            cout << "[ BERHASIL DI TAMBHAKAN ]" << endl;
            cout << "[=======================]" <<endl;
            cout << endl;
            printKeluarga(L, p);
            cout << "[==========================]" <<endl;
            cout << "[ DATA KELUARGA TER-UPDATE ]" << endl;
            cout << "[==========================]" <<endl;
            cout << endl;
        }


    }

}

void HapusData_Keluarga(ListPr &L){
    cout << "HAPUS DATA KELUARGA" << endl;
    cout << "-------------------" << endl;
    adrPr p;

    printInfoKeluarga(L);
    if(first(L) != NULL){
        deleteDataNamaOrtuYgDicari(L, p);

    }

}

void HapusData_Anak(ListPr &L){
    cout << "HAPUS DATA ANAK" << endl;
    cout << "---------------" << endl;

    adrCh c;

    printInfoKeluarga(L);
    if(first(L) != NULL){
        deleteAnak(L, c);
    }

}

void EditData_Keluarga(ListPr &L, adrPr &P){
    string ayah, ibu;
    string ayahBaru, ibuBaru, anakBaru;
    adrCh kid;

    cout << "EDIT DATA KELUARGA" <<endl;
    cout << "------------------" << endl;

    if(first(L) != NULL){

        printInfoKeluarga(L);
        cout<<"MASUKAN DATA KELUARGA YANG AKAN DI EDIT"<<endl;
        cin.ignore();
        cout<<"Nama Ayah: ";
        getline(cin, ayah);
        cout<<"Nama Ibu : ";
        getline(cin, ibu);

        cout<<endl;

        adrPr Q = findElemen(L, ayah, ibu);

        if(Q != NULL){
            cout << endl;
            cout << "[ KELUARGA DITEMUKAN ]" << endl;
            cout << endl;
            printKeluarga(L, Q);

            cout<< "MASUKAN NAMA ANGGOTA KELUARGA TERBARU" <<endl;
            //cin.ignore();
            cout<< "Nama ayah: ";
            getline(cin, ayahBaru);
            cout<< "Nama ibu : ";
            getline(cin, ibuBaru);

            cout << endl;

            namaAyah(Q) = ayahBaru;
            namaIbu(Q) = ibuBaru;

            if(first(child(Q)) != NULL){
                kid = first(child(Q));
                int i = 1;
                while(kid != NULL){
                    cout<<"Nama anak ke-"<< i << " : ";
                    getline(cin, anakBaru);
                    namaAnak(kid) = anakBaru;
                    i++;
                    kid = nextCh(kid);
                }

                system("pause");
                system("cls");

            } else {
                cout << "[ KELUARGA INI TIDAK MEMILIKI ANAK ]" << endl;
                cout<<endl;
                system("pause");
                system("cls");
            }
            cout << endl;
            cout << "[==================]" <<endl;
            cout << "[ BERHASIL DI EDIT ]" << endl;
            cout << "[==================]" <<endl;
            cout << endl;
            printKeluarga(L , Q);
            cout << "[==========================]" <<endl;
            cout << "[ DATA KELUARGA TER-UPDATE ]" << endl;
            cout << "[==========================]" <<endl;
            cout << endl;

        } else {
            cout << "[ DATA KELUARGA TIDAK DITEMUKAN ]"<<endl;
            cout << endl;
        }
    }else{
        printInfoKeluarga(L);
    }
}

void EditData_Anak(ListPr &L){
    cout << "EDIT DATA ANAK" << endl;
    cout << "--------------" << endl;
    adrCh c;

    printInfoKeluarga(L);

    editAnak(L, c);

}

void EditData_OrangTua(ListPr &L, adrPr &p){
    cout << "EDIT DATA ORANG TUA" << endl;
    cout << "-------------------" << endl;


    if(first(L) != NULL){
        printInfoKeluarga(L);
        editDataNamaOrtuYgDicari(L, p);

    }else{
        printInfoKeluarga(L);
    }

}

void printAnakTerbanyak(ListPr L){

    cout << "KELUARGA DENGAN ANAK TERBANYAK" << endl;
    cout << "------------------------------" << endl;

    adrPr banyak, dikit;
    adrPr temp;

    HitungBanyakAnak(L, banyak, dikit);
    temp = banyak;


    if(first(L) != NULL){
        do{
            if(panjangListCh(child(banyak)) == panjangListCh(child(temp))){
                printKeluarga(L, temp);
            }
            temp = nextPr(temp);
        }while(temp != banyak);

    }else{
        printKeluarga(L,temp);
    }
}

void printAnakTerdikit(ListPr L){

    cout << "KELUARGA DENGAN ANAK TERDIKIT" << endl;
    cout << "-----------------------------" << endl;

    adrPr banyak, dikit;
    adrPr temp;

    HitungBanyakAnak(L, banyak, dikit);
    temp = dikit;



    if(first(L) != NULL){
        do{
            if(panjangListCh(child(dikit)) == panjangListCh(child(temp))){
                printKeluarga(L, temp);
            }
            temp = nextPr(temp);
        }while(temp != dikit);
    }else{
        printKeluarga(L,temp);
    }
}

void cariKeluarga(ListPr L){


    cout << "CARI KELUARGA BERDASARKAN NAMA ORANG TUA" << endl;
    cout << "----------------------------------------" << endl;

    string ayah, ibu;

    adrPr Q;


    if(first(L) != NULL ){

        printInfoPr(L);

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
            cout << "[ KELUARGA DITEMUKAN ]" << endl;
            cout << endl;

            printKeluarga(L, Q);
        }

    }else{
        cout << endl;
        cout << "[ TIDAK ADA DATA KELUARGA ]" << endl;
        cout << endl;
    }
}

// VARIABEL GLOBAL //

ListPr orangTua;
ListCh anak;



// TAMBAHAN //
    //system("pause");
    //system("cls");

int main(){

    string cariAyah, cariIbu;
    //string pilih;

    adrPr p;
    adrCh c;

    CreateListPr(orangTua);



    string pilih,konfirmasi,pil;
    bool cek = true;




    konfirmasi = "N";
    while(konfirmasi != "Y" && konfirmasi != "y"){

        MenuUtama();
        cout << "Pilihan : ";
        cin >> pilih;
        cout << endl;

        system("cls");

        if(konfirmasi == "N" || konfirmasi == "n"){
            while(pilih != "0"){

                if(pilih == "1"){   // MENU 1
                    Menu_1();
                    cout << "Pilihan : ";
                    cin >> pil;
                    cout << endl;

                    while(pil != "0"){
                        if(pil == "1"){
                            TambahData_Keluarga(orangTua);
                        }else if(pil == "2"){
                            TambahData_OrangTua(orangTua);
                        }else if(pil == "3"){
                            TambahData_AnakKeKeluarga(orangTua);
                        }else{

                            system("cls");

                            cout << endl;
                            cout << "[INVALID]" << endl;
                            cout << endl;
                        }


                        Menu_1();
                        cout << "Pilihan : ";
                        cin >> pil;
                        cout << endl;
                    }

                    system("cls");

                }else if(pilih == "2"){ // MENU 2
                    Menu_2();
                    cout << "Pilihan : ";
                    cin >> pil;
                    cout << endl;

                    while(pil != "0"){
                        if(pil == "1"){
                            HapusData_Keluarga(orangTua);
                        }else if(pil == "2"){
                            HapusData_Anak(orangTua);
                        }else{
                            system("cls");

                            cout << endl;
                            cout << "[INVALID]" << endl;
                            cout << endl;
                        }

                        Menu_2();
                        cout << "Pilihan : ";
                        cin >> pil;
                        cout << endl;
                    }

                    system("cls");

                }else if(pilih == "3"){     // MENU 3
                    Menu_3();
                    cout << "Pilihan : ";
                    cin >> pil;
                    cout << endl;

                    while(pil != "0"){
                        if(pil == "1"){
                            EditData_Keluarga(orangTua, p);
                        }else if(pil == "2"){
                            EditData_OrangTua(orangTua, p);
                        }else if(pil == "3"){
                            EditData_Anak(orangTua);
                        }else{
                            system("cls");

                            cout << endl;
                            cout << "[INVALID]" << endl;
                            cout << endl;
                        }


                        Menu_3();
                        cout << "Pilihan : ";
                        cin >> pil;
                        cout << endl;
                    }

                    system("cls");

                }else if(pilih == "4"){     // MENU 4
                    Menu_4();
                    cout << "Pilihan : ";
                    cin >> pil;
                    cout << endl;

                    while(pil != "0"){
                        if(pil == "1"){
                            cout << "SELURUH DATA KELUARGA " << endl;
                            cout << "----------------------" << endl;
                            printInfoKeluarga(orangTua);
                        }else if(pil == "2"){
                            printAnakTerbanyak(orangTua);
                        }else if(pil == "3"){
                            printAnakTerdikit(orangTua);
                        }else if(pil == "4"){
                            cariKeluarga(orangTua);
                        }else if(pil == "5"){
                            PrintKeluargaDariAnak(orangTua);
                        }else{
                            system("cls");

                            cout << endl;
                            cout << "[INVALID]" << endl;
                            cout << endl;
                        }


                        Menu_4();
                        cout << "Pilihan : ";
                        cin >> pil;
                        cout << endl;
                    }

                    system("cls");

                }else{
                    system("cls");

                    cout << endl;
                    cout << "[INVALID]" << endl;
                    cout << endl;    // ERROR HANDLING
                }
                MenuUtama();
                cout << "Pilihan : ";
                cin >> pilih;
                cout << endl;

                system("cls");
            }

            system("cls");

        }else{
            system("cls");

            cout << endl;
            cout << "[INVALID]" << endl;
            cout << endl;
        // ERROR HANDLING
        }


        cout << "APAKAH YAKIN INGIN KELUAR ? (Y/N) : ";
        cin >> konfirmasi;

        system("cls");

        while((konfirmasi != "Y") && (konfirmasi != "y") && (konfirmasi != "N") && (konfirmasi != "n") ){
            cout << "[COBA LAGI]" << endl;
            cout << "APAKAH YAKIN INGIN KELUAR ? (Y/N) : ";
            cin >> konfirmasi;
            system("cls");
        }


    }
    system("pause");
    system("cls");

    cout << "[===========================================================]" << endl;
    cout << "|===================== PROGRAM SELESAI =====================|" << endl;
    cout << "[===========================================================]" << endl;
    cout << endl;




    cout << endl;
    cout << "Credit : - RAMADITO FERDIAN ASSA         [ 1301194005 ] " << endl;
    cout << "         - MUHAMMAD BAYU SAMUDRA SIDIDK  [ 1301194031 ] " << endl;
}


