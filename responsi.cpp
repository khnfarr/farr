#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100;

struct Mahasiswa {
    string nim;
    string nama;
    string jurusan;
    int angkatan;
};

Mahasiswa data[MAX];
int jumlahData = 0;

void bacaDariFile() {
    ifstream file("mahasiswa.txt");
    if (!file) {
        cout << "File tidak ditemukan.\n";
        return;
    }

    while (!file.eof() && jumlahData < MAX) {
        getline(file, data[jumlahData].nim);
        getline(file, data[jumlahData].nama);
        getline(file, data[jumlahData].jurusan);
        file >> data[jumlahData].angkatan;
        file.ignore();

        // Tambahan debug
        cout << "Terbaca: " << data[jumlahData].nim << ", "
             << data[jumlahData].nama << ", "
             << data[jumlahData].jurusan << ", "
             << data[jumlahData].angkatan << endl;

        jumlahData++;
    }

    file.close();
    cout << "Data berhasil dibaca dari file.\n";
}


void tampilkanData() {
    cout << "\n--- Data Mahasiswa ---\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << "NIM      : " << data[i].nim << endl;
        cout << "Nama     : " << data[i].nama << endl;
        cout << "Jurusan  : " << data[i].jurusan << endl;
        cout << "Angkatan : " << data[i].angkatan << endl;
        cout << "-----------------------\n";
    }
}

void cariMahasiswa() {
    string nimCari;
    cout << "Masukkan NIM yang dicari: ";
    getline(cin, nimCari);

    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nim == nimCari) {
            cout << "Data ditemukan:\n";
            cout << "Nama     : " << data[i].nama << endl;
            cout << "Jurusan  : " << data[i].jurusan << endl;
            cout << "Angkatan : " << data[i].angkatan << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan.\n";
    }
}

void bubbleSortNama() {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            if (data[j].nama > data[j + 1].nama) {
                Mahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan nama.\n";
}

void simpanKeFile() {
    ofstream file("output_mahasiswa.txt");
    for (int i = 0; i < jumlahData; i++) {
        file << data[i].nim << endl;
        file << data[i].nama << endl;
        file << data[i].jurusan << endl;
        file << data[i].angkatan << endl;
    }
    file.close();
    cout << "Data berhasil disimpan ke file output_mahasiswa.txt\n";
}

int main() {
    bacaDariFile();
    int pilihan;
    string dummy;

    do {
        cout << "\n===== Menu =====\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Cari berdasarkan NIM\n";
        cout << "3. Urutkan berdasarkan Nama\n";
        cout << "4. Simpan ke File\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline

        switch (pilihan) {
            case 1: tampilkanData(); break;
            case 2: cariMahasiswa(); break;
            case 3: bubbleSortNama(); break;
            case 4: simpanKeFile(); break;
            case 5: cout << "Terima kasih.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 5);

    return 0;
}

