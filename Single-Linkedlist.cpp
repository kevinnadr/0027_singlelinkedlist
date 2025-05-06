#include <iostream>      // Digunakan untuk input-output standar
#include <string.h>      // Tidak digunakan dalam kode ini (bisa dihapus)
using namespace std;

class Node 
{
public:
    int noMhs;           // Menyimpan Nomor Mahasiswa
    Node* next;          // Pointer ke node berikutnya dalam list
};

