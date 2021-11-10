#include <bits/stdc++.h>
using namespace std;
class DbKota
{
private:
    //properties
    int last_node;
    int banyak_kota;

public:
    //properties
    struct kota_t
    {
        string nama;
        int x;
        int y;
        int next_node;
    };
    kota_t kota[100];

    //method

    DbKota();
    ~DbKota();

    void append(string nama_kota, int x, int y);
    void remove(int posisi);
    void removeByName(string nama_kota);
    void insert(int posisi, string nama_kota, int x, int y);
    void show();
    int searchByName(string nama_kota);
    void searchByPos(int posisi);
};