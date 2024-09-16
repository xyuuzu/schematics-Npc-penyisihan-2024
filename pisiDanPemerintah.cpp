#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    string otoritas;
    string aksi;
    
    string otoritas_tertinggi = "cipherpol";
    string aksi_terakhir;
    string otoritas_terakhir;
    bool sudah_diperintah = false;
    
    for (int i = 0; i < N; i++) {
        cin >> otoritas >> aksi;
        
        if (!sudah_diperintah && aksi == "berhenti") {
            cout << "Pacifista ngambek karena belum diperintah tetapi sudah disuruh berhenti!" << endl;
            return 0;
        }
        
        if (otoritas == "gorosei") {
            otoritas_tertinggi = "gorosei";
        } else if (otoritas == "vegapunk" && otoritas_tertinggi != "gorosei") {
            otoritas_tertinggi = "vegapunk";
        } else if (otoritas == "cipherpol" && otoritas_tertinggi == "cipherpol") {
            otoritas_tertinggi = "cipherpol";
        }
        
        if (otoritas == otoritas_tertinggi) {
            if (sudah_diperintah) {
                if (aksi == aksi_terakhir) {
                    cout << "Pacifista sudah diperintah untuk " << aksi << " oleh " << otoritas_terakhir << "." << endl;
                } else {
                    cout << "Pacifista " << aksi << " sesuai dengan keinginan " << otoritas << "." << endl;
                    aksi_terakhir = aksi;
                    otoritas_terakhir = otoritas;
                }
            } else {
                cout << "Pacifista " << aksi << " sesuai dengan keinginan " << otoritas << "." << endl;
                aksi_terakhir = aksi;
                otoritas_terakhir = otoritas;
                sudah_diperintah = true;
            }
        } else {
            cout << "Pacifista tidak nurut karena wewenang " << otoritas << " lebih rendah dari " << otoritas_tertinggi << "." << endl;
        }
    }
    
    return 0;
}
