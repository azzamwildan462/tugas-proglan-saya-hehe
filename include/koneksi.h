#ifndef KONEKSI_H
#define KONEKSI_H

#include "initlib.h"
#include "string.h"

class Koneksi
{
private:
    sf::UdpSocket udp_socket;
    sf::IpAddress alamat_ip = "192.168.43.220"; //alamat
    unsigned short port = 8877;                 //tes
    unsigned short port_server = 6969;          //port server untuk menerima

    Koneksi();

public:
    char data_kirim[64];
    char data_terima[64];

    ~Koneksi();

    //===== coba coba singleton =====
    static Koneksi *getInstance();

    void loop();
    void run();
};

#endif