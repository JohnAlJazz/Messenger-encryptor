#include "../inc/socket.hpp"
#include "../inc/TCPSocketExceptions.hpp"

#include <iostream>

namespace net {

Socket::Socket() 
: m_socket(socket(AF_INET, SOCK_STREAM, 0)) {

    if(m_socket == -1) {
                 
        throw TCPSocketExceptions("socket() failed", "in socket Ctor");
    }    
}

Socket::Socket(int a_socket) 
: m_socket(a_socket)
{}

Socket::~Socket() {
    // close(m_socket); //causes problems when using epoll   
}

} //net