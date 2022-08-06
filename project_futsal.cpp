#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
void menu();
void pemesanan();
void cetak_kartu();
void keluar();
int datacust = 0;
struct booking{
    char namapembeli[100],kodelapangan[100],namalapangan[100],konfir;
    int jenispembeli,jam,harga,jumlah,total,bayar,sisa,diskon;
    string tanggal;
}bkg[100];

void pemesanan(){
char pilih;
awal:
datacust++;
cout<<"INFOR FUTSAL"<<endl;
cout<<"JL.MAJAPAHIT"<<endl;
cout<<"============================"<<endl;

cout<<"DAFTAR HARGA : 1. -VINYL (MEMBER) : Rp.125.000"<<endl
    <<"                  -VINYL (REGULER : Rp.150.000"<<endl
    <<"               2. -SINTETIS (MEMBER) : Rp.75.000"<<endl
    <<"                  -SINTETIS (REGULER : Rp.100.000"<<endl
    <<"               3. -KARPET PLASTIK (MEMBER) : Rp.100.000"<<endl
    <<"                  -KARPET PLASTIK (REGULER : Rp.125.000"<<endl
    <<"NOTE : -booking >= 3 jam diskon 5%"<<endl
    <<"       -booking >= 5 jam diskon 10%"<<endl;
cout<<"Pelanggan ke - "<<datacust<<endl;
cout<<" MASUKKAN NAMA ANDA            : ";
cin>>bkg[datacust].namapembeli;

cout<<" JENIS PEMBELI                 "<<endl
    <<"      1.MEMBER                 "<<endl
    <<"      2.REGULER                "<<endl;

cout<<"APAKAH ANDA MEMBER [1/2]       : "; 
cin>>bkg[datacust].jenispembeli;
cin.ignore();
cout<<"INPUT TANGGAL SEWA             : ";
getline(cin,bkg[datacust].tanggal);

cout<<"============================="<<endl;

cout<<"PILIH KODE LAPANGAN [VL/ST/KP] : ";
cin>>bkg[datacust].kodelapangan;

cout<<"INPUT LAMA JAM                 : ";
cin>>bkg[datacust].jam;

if((strcmp(bkg[datacust].kodelapangan,"VL")==0)||(strcmp(bkg[datacust].kodelapangan,"vl")==0)){
strcpy(bkg[datacust].namalapangan,"VINYL");
if(bkg[datacust].jenispembeli==1){
bkg[datacust].harga=125000;
}
else {
bkg[datacust].harga=150000;
}
}

else if((strcmp(bkg[datacust].kodelapangan,"ST")==0)||(strcmp(bkg[datacust].kodelapangan,"st")==0)){
strcpy(bkg[datacust].namalapangan,"SINTETIS");
if(bkg[datacust].jenispembeli==1){
bkg[datacust].harga=75000;
}
else
{
bkg[datacust].harga=100000;
}
}

else if((strcmp(bkg[datacust].kodelapangan,"KP")==0)||(strcmp(bkg[datacust].kodelapangan,"kp")==0)){
strcpy(bkg[datacust].namalapangan,"KARPET PLASTIK");
if(bkg[datacust].jenispembeli==1){
bkg[datacust].harga=100000;
}
else
{
bkg[datacust].harga=125000;
}
}
cout<<"Data "<< bkg[datacust].namapembeli << " berhasil disimpan!!"<<endl;
cout<<"Tambah data lagi ? (y/n) : ";cin>>pilih;
if(pilih=='y'){
    system("cls");
    goto awal;
}else if(pilih=='n'){
    char ketik;
    cout<<"Ketik Y untuk kembali ke menu : ";cin>>ketik;
    while (ketik=='Y'){
    system("cls");
    menu();
    }
}
}

void menu(){
int pilih;
cout<<"================================="<<endl
    <<"          INFOR FUTSAL           "<<endl
    <<"          JL.MAJAPAHIT           "<<endl
    <<"=================================="<<endl;
cout<<"               MENU               "<<endl
    <<"     1. Booking Jadwal            "<<endl
    <<"     2. Cetak kartu               "<<endl
    <<"     3. Keluar                    "<<endl
    <<"     => ";cin>>pilih;
    system("cls");
    switch(pilih){
        case 1:{
            pemesanan();
            break;
        }
        case 2:{
            cetak_kartu();
            break;
        }
        case 3:{
            keluar();
            break;
        }
    }
}

void cetak_kartu(){
datacust++;
string input,carinama;
cout<<"---CARI DATA PELANGGAN---"<<endl;
cout<<"Masukkan Nama : ";cin>>carinama;
for (int i=0; i<datacust; i++){

if(carinama==bkg[i].namapembeli){
cout<<"Data "<<bkg[i].namapembeli<<" berhasil ditemukan"<<endl;
cout<<"\nINFOR FUTSAL"<<endl;
cout<<"JL.MAJAPAHIT"<<endl;
cout<<"============================"<<endl;

cout<<" NAMA PEMBELI     : "<<bkg[i].namapembeli<<endl;
cout<<" NAMA LAPANGAN    : "<<bkg[i].namalapangan<<endl;
cout<<" HARGA            : "<<bkg[i].harga<<endl;
cout<<" TANGGAL          : "<<bkg[i].tanggal<<endl;
cout<<" LAMA SEWA        : "<<bkg[i].jam<<" jam"<<endl;
cout<<"-----------------------------"<<endl;

bkg[i].jumlah=bkg[i].harga*bkg[i].jam;
if(bkg[i].jam>=5){
bkg[i].diskon=0.1*bkg[i].harga;
}
else if(bkg[i].jam>=3){
bkg[i].diskon=0.05*bkg[i].harga;
}
else {
bkg[datacust].diskon=0;
}
cout<<" JUMLAH           : "<<bkg[i].jumlah<<endl;
cout<<" DISKON           : "<<bkg[i].diskon<<endl;

cout<<"-----------------------------"<<endl;

bkg[i].total=bkg[i].jumlah-bkg[i].diskon;
bayar :
cout<<" TOTAL BAYAR      : "<<bkg[i].total<<endl;
cout<<" UANG BAYAR       : ";cin>>bkg[i].bayar;

bkg[i].sisa=bkg[i].total-bkg[i].bayar;
cout<<" SISA PEMBAYARAN  : "<<bkg[i].sisa<<endl;
cout<<"-----------------------------"<<endl;

cout<<" \nKartu "<<bkg[i].namapembeli<<" berhasil dicetak, ketik YA untuk kembali ke menu"<<endl;
cout<<"=>";cin>>input;
if(input=="YA"){
    system("cls");
    menu();
            }
        }
    }
}

void keluar(){
    cout<<"================================="<<endl
        <<"          INFOR FUTSAL           "<<endl
        <<"          JL.MAJAPAHIT           "<<endl
        <<"=================================="<<endl;
    cout<<endl;
    cout<<"\n---TERIMAKASIH SUDAH BOOKING---"<<endl
        <<"       SAMPAI JUMPA LAGI       ";
}

int main(){
    menu();
}