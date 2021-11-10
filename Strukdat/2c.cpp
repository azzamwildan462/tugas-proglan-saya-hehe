int DBKota::searchByName(string nama_kota)
{
    for (int i = 0; i < banyak_kota; i++)
    {
        if (nama_kota == kota[i].nama)
        {
            // cout << "Kota " << nama_kota << " ada pada index array ke-" << i << endl;
            // break;
            return i;
        }
    }
}