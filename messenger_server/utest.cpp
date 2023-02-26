#include "mu_test.h"

#include "Socket.hpp"
#include "TCPClientSocket.hpp"
#include "TCPServerSocket.hpp"
#include "messengerProtocol.hpp"

#include <iostream>
#include <string>

using namespace net;
using namespace messenger;

BEGIN_TEST(test_messenger_to_TCP)
    
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
    // std::string serverMsg("hello from server\n");
    // auto send = protocol.Pack(serverMsg);
    // client->Send(send);    
    
    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
    TEST(test_messenger_to_TCP)    

END_SUITE