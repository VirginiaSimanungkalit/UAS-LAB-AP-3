#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Kontak 
{
    string nama;
    string nomorTelepon;
    string email;
};


class PengelolaKontak 
{
private:
    vector<Kontak> kontakList; 

public:
    
    void tambahKontak(const string& nama, const string& nomorTelepon, const string& email) 
    {
        Kontak kontakBaru;
        kontakBaru.nama = nama;
        kontakBaru.nomorTelepon = nomorTelepon;
        kontakBaru.email = email;
        kontakList.push_back(kontakBaru);
        cout << "Kontak berhasil ditambahkan" << endl;
    }

    void tampilkanKontak() const 
    {
        if (kontakList.empty()) 
        {
            cout << "Tidak ada kontak yang tersedia" << endl;
            return;
        }

        cout << "Daftar Kontak :" << endl;
        for (const auto& k : kontakList)  
        {
            cout << "Nama : " << k.nama;
            cout << ", Nomor Telepon : " << k.nomorTelepon;
            cout << ", Email : " << k.email << endl;
        }
    }

    Kontak* cariKontak(const string& nama) 
    {
        for (auto& k : kontakList) 
        {
            if (k.nama == nama) 
            {
                return &k;
            }
        }
        return nullptr;
    }

    void hapusKontak(const string& nama) 
    {
        for (auto it = kontakList.begin(); it != kontakList.end(); ++it) 
        {
            if (it->nama == nama) 
            {
                kontakList.erase(it);
                cout << "Kontak berhasil dihapus" << endl;
                return;
            }
        }
        cout << "Kontak tidak ditemukan" << endl;
    }
};

void tampilkanMenu() 
{
    cout << "1. Tambah Kontak" << endl;
    cout << "2. Tampilkan Semua Kontak" << endl;
    cout << "3. Cari Kontak" << endl;
    cout << "4. Hapus Kontak" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih opsi : ";
}

int main() 
{
    PengelolaKontak pengelola; 
    int pilihan;
    string nama, nomorTelepon, email;

    while (true) 
    {
        tampilkanMenu(); 
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) 
        {
            case 1:
                cout << "Masukkan nama : ";
                getline(cin, nama);
                cout << "Masukkan nomor telepon : ";
                getline(cin, nomorTelepon);
                cout << "Masukkan email : ";
                getline(cin, email);
                pengelola.tambahKontak(nama, nomorTelepon, email); 
                break;
            case 2:
                pengelola.tampilkanKontak(); 
                break;
            case 3:
                cout << "Masukkan nama yang dicari: ";
                getline(cin, nama);
                if (Kontak* k = pengelola.cariKontak(nama)) 
                { 
                    cout << "Kontak ditemukan : Nama : " << k->nama << endl;
                    cout << "Nomor Telepon : " << k->nomorTelepon << endl;
                    cout << "Email : " << k->email << endl;
                } 
                else 
                {
                    cout << "Kontak tidak ditemukan" << endl;
                }
                break;
            case 4:
                cout << "Masukkan nama yang akan dihapus : ";
                getline(cin, nama);
                pengelola.hapusKontak(nama); 
                break;
            case 5:
                cout << "Terima kasih telah menggunakan manajemen kontak." << endl;
                return 0; 
            default:
                cout << "Opsi tidak valid, silakan coba lagi" << endl;
        }
    }

    return 0;
}