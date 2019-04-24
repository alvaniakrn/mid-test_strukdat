/*
 alvina vania kirana
 140810180010
 uts strukdat
 24 april 2019
 */

#include <iostream>
using namespace std;

struct elemenList {
    char namaMakanan;
    int jumlah;
    int harga;
    elemenList* next;
};

typedef elemenList* pointer;
typedef pointer list;

void createList (list& first);
void createElemen (pointer& pBaru);
void insertFirst (list& first, pointer& pBaru);
void deleteFirst (list& first, pointer& pHapus);
void traversal(list& first);
void sort(list& first);

int main() {
    pointer p;
    list v;
    char namaPelanggan;
    int n;
    
    cout << "-----------Menu Restoran LALALA-----------"<<endl;
    cout << "------------------------------------------"<<endl;
    cout << "No         Nama Makanan            Harga"<<endl;
    cout << "------------------------------------------"<<endl;
    cout << "1          Omlet Rendang           8.000"<<endl;
    cout << "------------------------------------------"<<endl;
    cout << "2          Nasi Gila               10.000"<<endl;
    cout << "------------------------------------------"<<endl;
    cout << "3          Chicken Katsu           12.000"<<endl
    cout << "------------------------------------------"<<endl;
    cout << "4          Ayam Geprek             10.000"<<endl;
    cout << "------------------------------------------"<<endl;
    cout << "5          Nasi Goreng             8.000"<<endl;
    cout << "------------------------------------------"<<endl;
    
    createList(v);
    
    cout << "Nama Pelanggan     :";cin>>namaPelanggan;
    cout << "Ingin memesan berapa menu?"; cin >> n;
    cout << "Masukkan pesanan   :"<<endl;
    for (int i=0; i<n; i++){
        createElemen(p);
        insertFirst(v,p);
    }
    traversal(v);
    
    sort(v);
    traversal(v);
    
    return 0;
}

//---------------------------------------------------------------------
void createList (list& first){
    first=NULL;
}

void createElemen (pointer& pBaru){
    pBaru=new elemenList;
    cout << "Nama Makanan  :";cin >> pBaru->namaMakanan;
    cout << "Jumlah        :";cin >> pBaru->jumlah;
    cout << "Harga         :";cin >> pBaru->harga;
    pBaru->next=NULL;
}

void insertFirst (list& first, pointer pBaru){
    if (first==NULL){
        first=pBaru;
    }
    else {
        pBaru->next=first;
        first=pBaru;
    }
}

void deleteFirst (list& first, pointer& pHapus){
    if (first==NULL){
        pHapus=NULL;
        cout << "List Kosong Tidak ada yang dihapus" <<endl;
    }
    else if (first->next==NULL){
        pHapus=first;
        first=NULL;
    }
    else {
        pHapus=first;
        first=first->next;
        pHapus->next=NULL;
    }
}

void traversal (list& first){
    pointer pBantu;
    if (first==NULL){
        cout << "List kosong"<<endl;
    }
    else {
        pBantu=first;
        do {
            cout << pBantu->namaMakanan<<"          " <<pBantu->jumlah<<"           "<<pBantu->harga<<endl;
            pBantu = pBantu->next;
        }
        while (pBantu != NULL);
    }
}

void sort(list& first) {
    pointer pBantu,jum;
    
    while (pBantu!= NULL) {
        pBantu=first;
        
        while (jum!= NULL) {
            jum=first;
            if (jum->jumlah > pBantu->jumlah) {
                
                menu temp = *jum;
                jum->namaMakanan = pBantu->namaMakanan;
                jum->jumlah = pBantu->jumlah;
                jum->harga = pBantu->harga;
                
                pBantu->namaMakanan = temp.namaMakanan;
                pBantu->jumlah = temp.jumlah;
                pBantu->harga = temp.harga;
            } else {
                jum = jum->next;
            }
        }
        pBantu=pBantu->next;
    }
}
