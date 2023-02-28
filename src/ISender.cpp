#include "../inc/ISender.hpp"
#include "../inc/messengerProtocol.hpp"

#include <iostream>
#include <exception>

namespace messenger {

SendToTCP::SendToTCP(std::string a_ip, uint16_t a_port) 
: m_ip(a_ip)
, m_port(a_port)
, m_client(a_ip.c_str(), a_port)
{
    std::cout<<"\nSEnd TCP: " << a_ip << '\n';
}

void SendToTCP::Send(std::string& a_message) {
    
    try {
        
        Protocol protocol;
        
        auto msg = protocol.Pack(a_message);

        m_client.Send(msg);
    } 

    catch(const std::runtime_error& e) {

        std::cout << "here: " << e.what() << '\n';
    }
}

} //messenger