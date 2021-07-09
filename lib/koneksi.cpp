#include "../include/koneksi.h"

Koneksi::~Koneksi()
{
    //destruktor
}

Koneksi::Koneksi()
{
    if (udp_socket.bind(port_server) != sf::Socket::Done)
    {
        //gagal
    }
    // printf("tes wes bind opo gorong?");
}

void Koneksi::loop()
{
    // printf("tes");
    while (1)
    {
        // printf("melbu gk?\n");
        char terima_pesan[64];
        std::size_t size_terima_data;

        if (udp_socket.receive(terima_pesan, 64, size_terima_data, alamat_ip, port) != sf::Socket::Done)
        {
            //printf("errroerrerrr");
            // break;
        }

        // printf("%s", terima_pesan);
        // strcpy(data_terima, terima_pesan);

        memcpy(data_terima, &terima_pesan, 1);
        memcpy(data_terima + 1, &terima_pesan + 1, 1);
        memcpy(data_terima + 2, &terima_pesan + 2, 1);
        memcpy(data_terima + 3, &terima_pesan + 3, 1);
        memcpy(data_terima + 4, &terima_pesan + 4, 1);

        // char kirim_pesan[64];
        // strcpy(kirim_pesan, data_kirim);

        // // char kirim_pesan[64] = "ini dari server";
        // if (udp_socket.send(kirim_pesan, 64, alamat_ip, port) != sf::Socket::Done)
        // {
        //     // break;
        // }
    }
    return;
}

Koneksi *Koneksi::getInstance()
{
    static Koneksi instance;
    return &instance;
}

void Koneksi::run()
{
    // tes_thread = new sf::Thread(&loop);
    // tes_thread->launch();

    // sf::Thread tes_thread(&loop);
    // tes_thread.launch();

    // data_diterima = std::async(std::launch::async,loop);

    // if (tes_thread)
    // {
    //     tes_thread->wait();
    //     delete tes_thread;
    // }
    // return;
}