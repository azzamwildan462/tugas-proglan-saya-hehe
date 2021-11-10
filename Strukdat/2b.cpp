void DBkota::insert(int posisi, string nama_kota, int x, int y)
{
    banyak_kota++;
    for (int i = banyak_kota; i >= posisi; i--)
    {
        kota[i + 1] = kota[i];
    }

    kota[posisi].nama = nama_kota;
    kota[posisi].x = x;
    kota[posisi].y = y;
    kota[posisi].next_node = -1;
}

void DBKota::remove(int posisi)
{
    posisi++;
    for (int i = posisi - 1; i < banyak_kota; i++)
    {
        kota[i] = kota[i + 1];
    }

    kota[banyak_kota - 1].nama = false;
    kota[banyak_kota - 1].x = false;
    kota[banyak_kota - 1].y = false;

    banyak_kota--;
}