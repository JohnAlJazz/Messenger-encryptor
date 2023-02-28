#include "../inc/socket.hpp"
#include "../inc/TCPClientSocket.hpp"
#include "../inc/TCPServerSocket.hpp"
#include "../inc/messengerProtocol.hpp"

#include <iostream>
#include <string>

using namespace net;
using namespace messenger;

int main() {
    
    std::cout << "encrypted message\n\n";

    Server server(8080);                  
    Protocol protocol;    

    std::unique_ptr<Client> client = server.Accept(); 

    while(true) {

        try {

            auto msg = protocol.UnPack(client);          
            std::cout << msg << '\n'; 
        }

        catch(const TCPSocketExceptions& e) {

            std::cout << e.what() << ", " << e.where() << '\n';
            break;
        }

    }      
}