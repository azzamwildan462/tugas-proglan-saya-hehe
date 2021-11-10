#include <bits/stdc++.h>

using namespace std;

float pitagoras(float x1, float y1, float x2, float y2)
{

    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

class DbKota
{
private:
    // properties
    int last_node;
    int banyak_kota;

public:
    // properties
    struct kota_t
    {
        string nama;
        char *nama_serial;
        int x;
        int y;
        string hubungan_kota[100];
        int hubungan_kota_pos[100];
        int tanda_akhir_hubungan_kota;
        // int next_node;
    };

    kota_t kota[100];

    // method

    DbKota()
    {
        last_node = -1;
        banyak_kota = 0;
    }
    ~DbKota()
    {
        // desturtor
    }

    void push(string nama_kota, int x, int y)
    {
        // last_node++;
        banyak_kota++;
        kota[banyak_kota - 1].nama = nama_kota;
        kota[banyak_kota - 1].x = x;
        kota[banyak_kota - 1].y = y;
        // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
        kota[banyak_kota - 1].tanda_akhir_hubungan_kota = -1;
        // kota[last_node].next_node = -1;
        kota[banyak_kota - 1].nama_serial = new char[nama_kota.size() + 1];
        strcpy(kota[banyak_kota - 1].nama_serial, kota[banyak_kota - 1].nama.c_str());
    }
    void push(kota_t src)
    {
        banyak_kota++;
        printf("alamat tekan push: %p\n", &kota[banyak_kota - 1]);
        // kota[banyak_kota] = src;
        memcpy(&kota[banyak_kota - 1], &src, sizeof(kota[banyak_kota - 1]));
        // memset(&kota[banyak_kota-1],src,sizeof(kota[banyak_kota]));
        // memccpy(&kota[banyak_kota - 1], &src, sizeof(kota[banyak_kota - 1]));
    }

    kota_t pop()
    {
        kota_t buff;
        // memcpy(&buff, &kota[banyak_kota - 1], sizeof(buff));
        buff = kota[banyak_kota - 1];
        memset(&kota[banyak_kota], false, sizeof(kota[banyak_kota]));
        banyak_kota--;
        return buff;
    }

    void pop(kota_t *result)
    {
        // printf("fungsi: %p\n", result);
        // printf("asli pop: %s", kota[banyak_kota - 1].nama.c_str());
        printf("alamat sakdoronge %p\n", &kota[banyak_kota - 1]);
        *result = kota[banyak_kota - 1];
        memset(&kota[banyak_kota - 1], 0, sizeof(kota[banyak_kota]));
        printf("alamat sakmarine %p\n", &kota[banyak_kota - 1]);
        printf("hasil pop fungsi: %s\n", kota[banyak_kota - 1].nama.c_str());
        printf("waetfcthweftvewjqewfqweyj\n");
        banyak_kota--;
        // printf("hasil pop: %s", result->nama.c_str());
    }

    void justPop()
    {
        memset(&kota[banyak_kota], false, sizeof(kota[banyak_kota]));
        banyak_kota--;
    }

    void remove(int posisi)
    {
        posisi++;
        for (int i = posisi - 1; i < banyak_kota; i++) // mengiri
        {
            kota[i] = kota[i + 1];
        }

        kota[banyak_kota - 1].nama = false;
        kota[banyak_kota - 1].x = false;
        kota[banyak_kota - 1].y = false;
        // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
        kota[last_node].tanda_akhir_hubungan_kota = -1;

        banyak_kota--;
    }

    void removeByName(string nama_kota)
    {
        remove(searchByName(nama_kota));
    }

    void insert(int posisi, string nama_kota, int x, int y)
    {
        banyak_kota++;
        for (int i = banyak_kota; i >= posisi; i--) // menganan
        {
            kota[i + 1] = kota[i];
        }

        kota[posisi].nama = nama_kota;
        kota[posisi].x = x;
        kota[posisi].y = y;
        // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
        kota[last_node].tanda_akhir_hubungan_kota = -1;
        // kota[posisi].next_node = -1;
    }

    void show(int more = 0)
    {
        int panjang_nama = 0;
        int panjang_terdekat = 0;
        if (!more)
        {
            for (int i = 0; i < banyak_kota; i++)
            {
                // printf("iter-%d\n", i);
                if (kota[i].nama.size() < 0x8)
                    cout << kota[i].nama << "\t\t";
                else if (kota[i].nama.size() >= 0x8)
                    cout << kota[i].nama << "\t";
                cout << kota[i].x << "\t";
                cout << kota[i].y << "\t";
                if (kota[i].tanda_akhir_hubungan_kota == -1)
                    printf("- ");
                else
                {
                    for (int v = 0; v < kota[i].tanda_akhir_hubungan_kota; v++) // print hubungan
                    {
                        cout << kota[i].hubungan_kota[v] << ", ";
                    }
                    cout << kota[i].hubungan_kota[kota[i].tanda_akhir_hubungan_kota] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            // header
            for (int i = 0; i < banyak_kota; i++)
            {
                if (kota[i].nama.size() < 0x8)
                    panjang_nama = 0;
                else if (kota[i].nama.size() >= 0x8)
                    panjang_nama = 1;

                if (cariKotaTerdekatStr(kota[i].nama).size() < 0x8)
                    panjang_terdekat = 0;
                else if (cariKotaTerdekatStr(kota[i].nama).size() >= 0x8)
                    panjang_terdekat = 1;
            }

            if (panjang_nama == 0)
                printf("Nama \t");
            else if (panjang_nama == 1)
                printf("Nama \t\t");

            printf("X\t");

            printf("Y\t");

            if (panjang_terdekat = 0)
                printf("Terdekat");
            else if (panjang_terdekat = 1)
                printf("Terdekat\t");

            printf("Hubungan ");

            printf("\n");

            // isi
            for (int i = 0; i <= banyak_kota; i++)
            {
                printf("iter-%d\t", i); // untuk debug index
                if (kota[i].nama.size() < 0x8)
                    cout << kota[i].nama << "\t\t";
                else if (kota[i].nama.size() >= 0x8)
                    cout << kota[i].nama << "\t";

                cout << kota[i].x << "\t";

                cout << kota[i].y << "\t";

                if (cariKotaTerdekatStr(kota[i].nama).size() < 0x8)
                    cout << cariKotaTerdekatStr(kota[i].nama) << "\t\t";
                else if (cariKotaTerdekatStr(kota[i].nama).size() >= 0x8)
                    cout << cariKotaTerdekatStr(kota[i].nama) << "\t";
                // cout << cariKotaTerdekatStr(kota[i].nama) << " ";

                if (kota[i].tanda_akhir_hubungan_kota == -1)
                    printf("- ");
                else
                {
                    for (int v = 0; v < kota[i].tanda_akhir_hubungan_kota; v++) // print hubungan
                    {
                        cout << kota[i].hubungan_kota[v] << ", ";
                    }
                    cout << kota[i].hubungan_kota[kota[i].tanda_akhir_hubungan_kota] << " ";
                }
                cout << endl;
            }
        }
    }

    int searchByName(string nama_kota)
    {
        for (int i = 0; i < banyak_kota; i++)
        {
            if (nama_kota == kota[i].nama)
            {
                return i;
            }
        }
        // kalo sampek sini berarti kota gk ditemukan
        //  printf("kota gk ditemukan\n");
        return -1;
    }

    void searchByPos(int posisi)
    {
        cout << "Kota pada posisi ke-" << posisi << " adalah " << kota[posisi].nama << endl;
    }
    void connect1arah(string src, string dst)
    {
        int src_pos = searchByName(src);
        int dst_pos = searchByName(dst);
        if (src_pos >= 0 && dst_pos >= 0)
        {

            kota[src_pos].tanda_akhir_hubungan_kota++;
            kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst;
            kota[src_pos].hubungan_kota_pos[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
        }
        else
            printf("Invalid name\n");
    }
    void connect2arah(string src, string dst)
    {
        int src_pos = searchByName(src);
        int dst_pos = searchByName(dst);
        if (src_pos >= 0 && dst_pos >= 0)
        {
            kota[dst_pos].tanda_akhir_hubungan_kota++;
            kota[dst_pos].hubungan_kota[kota[dst_pos].tanda_akhir_hubungan_kota] = src;
            kota[dst_pos].hubungan_kota_pos[kota[dst_pos].tanda_akhir_hubungan_kota] = src_pos;

            kota[src_pos].tanda_akhir_hubungan_kota++;
            kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst;
            kota[src_pos].hubungan_kota_pos[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
        }
        else
            printf("Invalid name\n");
    }

    // PERCOBAAN, kendala belum menemukan solusi tepat untuk pindah cabang pencarian
    void cariHubungan(int dst, int temp[100], int *total_hub, int iter)
    {
        // Linear search
        int temp_iter = iter;
        for (int i = 0; i < banyak_kota; i++)
        {
            if (kota[i].tanda_akhir_hubungan_kota > -1)
            {
                for (int j = 0; j <= kota[i].tanda_akhir_hubungan_kota; j++)
                {
                    // printf("hub: %d dengan %d, ", kota[i].hubungan_kota_pos[j], dst);
                    if (kota[i].hubungan_kota_pos[j] == dst)
                    {
                        temp[temp_iter] = i;
                        temp_iter++;
                    }
                }
            }
            // printf("sudah\n");
        }
        // printf("ier: %d\n", temp_iter);
        if (temp_iter == 0)
            printf("Tdk punya hubungan..\n");
        else
            *total_hub = temp_iter;
    }
    void cariRute(string src, string dst)
    {
        int temp[100], total_hub = 0, hasil[100];
        int tanda_hasil = 0;
        int src_pos = searchByName(src);
        int dst_pos = searchByName(dst);
        if (src_pos >= 0 && dst_pos >= 0)
        {
            int i = 0;
            // while (temp[i] != src_pos)
            // {
            temp[0] = dst_pos;
            int j = 0;
            while (temp[0] != src_pos)
            {
                // printf("j: %d\n", j);
                if (j >= banyak_kota - 1)
                {
                    j = 0;
                    i++;
                }
                cariHubungan(temp[i], temp, &total_hub, i);
                j++;
                if (total_hub > 0)
                {
                    hasil[tanda_hasil] = temp[i];
                    tanda_hasil++;
                }
            }
            //     i++;
            // }
        }
        // printf("temp0: %d\n", temp[0]);
        if (temp[0] == searchByName(src))
        { // printf("hasil: %d", temp[0]);
            // printf("Rute: ");
            cout << "Rute " << src << " ke " << dst << " : " << endl;
            for (int i = tanda_hasil - 1; i >= 0; i--)
            {
                // printf("awukehhkcuakuaew %d ", hasil[i]);
                // printf("%");
                cout << kota[hasil[i]].nama << " -> ";
            }
            cout << dst << endl;
        }
        else
        {
            printf("Tidak ditemukan jalan..");
        }
    }
    int cariKotaTerdekat(string kota_yang_ingin_dicari)
    {
        int pos = searchByName(kota_yang_ingin_dicari);
        float min = 9999999999;
        int min_pos = pos;
        for (int i = 0; i < banyak_kota; i++)
        {
            if (i != pos)
            {
                // printf("min: %f ", min);
                // printf("jarak %s: %f\n", kota[i].nama.c_str(), pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y));
                if (min >= pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y))
                {
                    min = pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y);
                    min_pos = i;
                }
            }
        }
        return min_pos;
    }
    string cariKotaTerdekatStr(string kota_yang_ingin_dicari)
    {
        return kota[cariKotaTerdekat(kota_yang_ingin_dicari)].nama;
    }
};

int main()
{
    DbKota DB;
    DbKota::kota_t buff;

    DB.push("Atlantis", -200, -121);
    DB.push("Bikini Bottom", 242, 678);
    DB.push("Cilacap", 123, 321);
    DB.push("Dimmsdale", 124, 323);
    DB.push("Eindhoven", 234, 823);
    DB.push("Flores", 0x46, 0x21);
    DB.push("Garut", 0x23, 0x12);
    DB.push("Honduras", 0x69, 0x90);
    DB.push("Istanbul", 0x8, 0x13);

    DB.connect1arah("Atlantis", "Bikini Bottom");
    DB.connect1arah("Atlantis", "Cilacap");
    DB.connect1arah("Atlantis", "Istanbul");
    DB.connect1arah("Bikini Bottom", "Flores");
    DB.connect1arah("Bikini Bottom", "Eindhoven");
    DB.connect1arah("Bikini Bottom", "Dimmsdale");
    DB.connect1arah("Cilacap", "Honduras");
    DB.connect1arah("Cilacap", "Garut");
    // DB.connect1arah("Istanbul", "Istanbul");
    // DB.connect1arah("Atlantis", "Istanbul");

    // DB.connect2arah("Jember", "Haven");
    // DB.connect2arah("Konoha", "Atlantis");
    // DB.connect2arah("Haven", "Bikini Bottom");
    // DB.connect2arah("Bikini Bottom", "Dimmsdale");

    // DB.insert(2, "sby", 12, 23);
    // DB.show(1);
    // DB.searchByName("sby");
    // DB.searchByPos(2);
    // DB.remove(2);
    // DB.removeByName("Cilacap");

    // buff = DB.pop();
    DB.pop(&buff);
    DB.show(1);
    // printf("main: %p\n", &buff);
    printf("hasil pop: %s", buff.nama.c_str());
    DB.push(buff);
    DB.show(1);
    // printf("buri\n");
    // DB.cariRute("Jember", "Dimmsdale");
    // DB.cariRute("Jember", "Konoha");

    // printf("%f", pitagoras(2, 0, 5, 4));
    // printf("%d\n", DB.cariKotaTerdekat("Jember"));
    // printf("%s\n", DB.cariKotaTerdekatStr("Jember").c_str());
    // DB.cariKotaTerdekat("Jember");

    // DB.show(1);
    // int coba = 8;
    // if (coba == 0x8)
    //     printf("%x\n", coba);
    // printf("%x\n", 69);
    return 0;
}