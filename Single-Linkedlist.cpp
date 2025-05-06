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

        // Jika list kosong atau NIM lebih kecil dari node pertama
        if (START == NULL || nim <= START->noMhs) 
        {
            if ((START != NULL) && (nim == START->noMhs)) 
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;   // Gagal karena duplikasi
            }
            NodeBaru->next = START;  // Sisipkan di awal list
            START = NodeBaru;
            return;
        }

        Node *previous = START;   // Penunjuk ke node sebelumnya
        Node *current = START;    // Penunjuk untuk traversal

        // Menemukan posisi penyisipan (harusnya nim > current->noMhs)
        while ((current != NULL) && (nim > current->noMhs)) 
        {
            if (nim == current->noMhs) 
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;   // Gagal karena duplikasi
            }
            previous = current;        // Geser ke node berikutnya
            current = current->next;
        }

        // Sisipkan NodeBaru di antara previous dan current
        NodeBaru->next = current;
        previous->next = NodeBaru;
    }

    bool listEmpty() 
    {
        return (START == NULL);   // Mengembalikan true jika list kosong
    }

    bool search(int nim, Node **previous, Node **current) 
    {
        *previous = START;     // Mulai dari awal list
        *current = START;

        // Telusuri sampai ketemu atau habis
        while ((*current != NULL) && (nim != (*current)->noMhs)) 
        {
            *previous = *current;            // Simpan posisi sebelumnya
            *current = (*current)->next;     // Lanjut ke node berikutnya
        }
        return (*current != NULL);   // True jika ditemukan
    }
    
    bool delNode(int nim) 
    {
        Node *current, *previous;   // Penunjuk untuk node sebelumnya dan saat ini

        // Cari node yang akan dihapus
        if (!search(nim, &previous, &current)) 
        {
            cout << "\nNode dengan noMhs " << nim << " tidak ditemukan\n";
            return false;   // Node tidak ditemukan
        }

        // Jika node yang akan dihapus adalah node pertama
        if (current == START) 
            START = START->next;  // Geser START ke node berikutnya
        else 
            previous->next = current->next;  // Hubungkan previous ke node berikutnya
        
        delete current;   // Hapus node yang ditemukan
        return true;     // Node berhasil dihapus
    }

    void traverse() 
    {
        if (listEmpty()) 
        {
            cout << "\nList Kosong\n";   // Jika list kosong
        }
        else 
        {
            cout << "\nData didalam list adalah:\n";
            Node *currentNode = START;   // Penunjuk untuk traversal
            while (currentNode != NULL) 
            {
                cout << currentNode->noMhs << endl;   
                currentNode = currentNode->next;   
            }
            cout << endl;   // Baris baru setelah traversal
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;   // Variabel untuk menyimpan pilihan user
    while(1)
    {
        cout << endl;   // Baris baru untuk tampilan menu
        cout << "Menu:" ;
        cout << endl;   // Baris baru
        cout << "1. Menambah data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data di dalam List" << endl;
        cout << "4. Mencari data kedalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << endl;   // Baris baru
        cout << "Masukkan pilihan (1 - 5): ";
        cout << "Pilih menu: ";
        cin >> ch;   // Input pilihan user
        switch(ch) 
        {
            case '1':
            {
                mhs.AddNode();   // Menambah node baru
            }
            break;

            case '2':
            {
                if(mhs.listEmpty()) 
                {
                    cout << endl;
                    cout << "List Kosong" << endl;   // Jika list kosong
                    break;
                } 
                cout << "\nMasukkan Nomor Mahasiswa yang akan dihapus: ";
                cin >> nim;   // Input NIM yang akan dihapus
                if(mhs.delNode(nim)== false) 
                    cout << endl;
                    cout << "Data tidak ditemukan" << endl;   // Jika data tidak ditemukan
                else
                    cout << endl;
                    cout << "Data dengan nomor mahasiswa" << nim << " berhasil dihapus" << endl; // Jika data berhasil dihapus
        }
        break;
        case '3':
        {
            mhs.traverse();   // Menampilkan semua data dalam list
        }
        break;
        case '4':
        {
            if(mhs.listEmpty()== true) 
            {
                cout << "nList Kosong\n";   // Jika list kosong
                break;
            } 
            Node *previous, *current;   // Penunjuk untuk node sebelumnya dan saat ini
            cout << endl;
            cout << "Masukkan No Mahasiswa yang dicari: ";
            cin >> nim;   // Input NIM yang dicari
            if(mhs.search(nim, &previous, &current)== false) 
                cout << endl;
                cout << "Data tidak ditemukan" << endl;   // Jika data tidak ditemukan 
            else 
            {
                cout << endl;
                cout << "Data ditemukan" << endl;   // Jika data ditemukan
                cout << "\nNo Mahasiswa: " << current->noMhs << endl;   // Menampilkan NIM yang ditemukan
                cout << "\n";
            }
        }
        break;
 