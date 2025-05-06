#include <iostream>      // Digunakan untuk input-output standar
#include <string.h>      // Tidak digunakan dalam kode ini (bisa dihapus)
using namespace std;

class Node 
{
public:
    int noMhs;           // Menyimpan Nomor Mahasiswa
    Node* next;          // Pointer ke node berikutnya dalam list
};

class LinkedList 
{
    Node* START;         // Pointer ke node pertama dalam linked list

public:
    LinkedList() 
    {
        START = NULL;    // Inisialisasi list kosong
    }

    void AddNode() 
    {
        int nim;
        cout << "Masukkan Nomor Mahasiswa: ";
        cin >> nim;      // Input NIM dari user

        Node *NodeBaru = new Node();     // Membuat node baru
        NodeBaru->noMhs = nim;           // Menyimpan NIM ke node
        NodeBaru->next = NULL;           // Inisialisasi pointer next ke NULL
