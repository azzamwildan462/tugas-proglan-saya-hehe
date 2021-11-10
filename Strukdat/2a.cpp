void DBKota::append(string nama_kota, int x, int y)
{
    last_node++;
    banyak_kota++;
    kota[last_node].nama = nama_kota;
    kota[last_node].x = x;
    kota[last_node].y = y;
    kota[last_node].next_node = -1;
}