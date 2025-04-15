#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int pilihan, jumlah;
    int hargaSatuan, hargaTotal, diskon = 0;
    string namaMenu;

    cout << "================ DAFTAR MENU AYAM =================" << endl;
    cout << "1. Ayam Goreng\t\tRp 17.000" << endl;
    cout << "2. Ayam Bakar\t\tRp 21.000" << endl;
    cout << "==================================================" << endl;

    cout << "Masukkan pilihan menu (1 atau 2): ";
    cin >> pilihan;

    if (pilihan == 1) {
        namaMenu = "Ayam Goreng";
        hargaSatuan = 17000;
    } else if (pilihan == 2) {
        namaMenu = "Ayam Bakar";
        hargaSatuan = 21000;
    } else {
        cout << "Pilihan tidak valid." << endl;
        return 1; // Keluar dari program dengan kode error
    }

    cout << "Masukkan jumlah yang dipesan: ";
    cin >> jumlah;

    hargaTotal = hargaSatuan * jumlah;

    if (hargaTotal > 45000) {
        diskon = 0.10 * hargaTotal; // Diskon 10%
        hargaTotal -= diskon;
    }

    cout << "\n================== STRUK PEMBAYARAN =================" << endl;
    cout << "Menu yang dipesan\t: " << namaMenu << endl;
    cout << "Harga satuan\t\t: Rp "   << hargaSatuan << endl;
    cout << "Jumlah pesanan\t\t: " << jumlah << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Subtotal\t\t: Rp "  << hargaSatuan * jumlah << endl;
    if (diskon > 0) {
        cout << "Diskon (10%)\t\t: Rp " << diskon << endl;
        cout << "--------------------------------------------------" << endl;
    }
    cout << "Total harga\t\t: Rp "  << hargaTotal << endl;
    cout << "==================================================" << endl;

    return 0;
}
