#ifndef SOCKET_H
#define SOCKET_H

#include <winsock2.h> /* socket */
#include <unistd.h> /* close  */
#include <cstring>
#include <cstdio>

namespace net {

class Socket {
public:
    Socket();
    Socket(int a_socket);

    Socket(const Socket& a_other) = delete;
    Socket& operator=(const Socket& a_other) = delete;
    ~Socket();
    
private:
    friend class Client;
    friend class Server;
    int m_socket;
    int GetFD();
};

} //net

#include "./inl/socket_inl.hxx"

#endif //SOCKET_H