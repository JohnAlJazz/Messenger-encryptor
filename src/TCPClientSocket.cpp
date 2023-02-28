#include "../inc/TCPClientSocket.hpp"

namespace net {

Client::Client(const char* a_address, uint16_t a_port) 
: m_clientSocket()
{
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(a_address);
    address.sin_port = htons(a_port);


    if(connect(m_clientSocket.m_socket, (struct sockaddr*)&address, sizeof(address)) < 0 ) {
        throw TCPSocketExceptions("connect() failed", "in client Ctor");
    } 
}

Client::Client(int a_socket)
: m_clientSocket(a_socket)
{}

std::vector<char> Client::Receive() {
    
    std::vector<char> buffer(1000);       
    int receivedBytes = 0;    
        
    if((receivedBytes = recv(m_clientSocket.m_socket, buffer.data(), buffer.size(), 0)) <= 0) {

        throw TCPSocketExceptions("recv() 1 failed", "in client Receive()");
    }

    buffer.resize(receivedBytes);  

    return buffer;
}

void Client::Send(std::vector<char>& a_buffer) {
    
    size_t bytesToSend = a_buffer.size();
    ssize_t sentBytes = 0;   

    while(bytesToSend > 0) { 

        if((sentBytes = send(m_clientSocket.m_socket, a_buffer.data(), a_buffer.size(), 0)) < 0) { 

            throw TCPSocketExceptions("send() failed", "in client Send()");
        }

        bytesToSend -= sentBytes; 
    }    
}

} //net