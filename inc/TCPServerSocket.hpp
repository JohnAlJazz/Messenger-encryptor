#ifndef SERVER_H__
#define SERVER_H__

#include <iostream>
#include <memory>

#include "Socket.hpp"
#include "TCPClientSocket.hpp"
#include "TCPSocketExceptions.hpp"

namespace net {

class Server {
public:

    Server(uint16_t a_port);
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    ~Server() = default;

    std::unique_ptr<Client> Accept();    

private:
    friend class Asynchronizer;
    Socket m_serverSocket;    
    struct sockaddr_in m_address;
};
    
} //net

#endif //SERVER_H__