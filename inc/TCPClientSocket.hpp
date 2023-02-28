#ifndef CLIENT_HPP__
#define CLIENT_HPP__

#include <vector>
#include <stdint.h>

#include "socket.hpp"
#include "TCPSocketExceptions.hpp"

namespace net {

class Client {
public:

    Client(const char* a_address, uint16_t a_port);
    Client(int a_socket);
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    ~Client() = default;  
    
    std::vector<char> Receive();
    
    void Send(std::vector<char>& a_buffer);   

private:
    friend class Asynchronizer; 
    friend class Epoll;
    Socket m_clientSocket;
};
    
} //net

#endif //CLIENT_HPP__