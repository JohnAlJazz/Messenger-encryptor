#include <memory>
#include <fstream>

#include "../inc/messengerFactory.hpp"
#include "../inc/messenger.hpp"

using namespace messenger; 

static std::vector<std::string> MultiEncryptionsVec(char** argv, int argc) {

    std::vector<std::string> encryptions;

    for(int i = 3; i < argc; ++i) {

        encryptions.push_back(argv[i]);
    }

    return encryptions;
}

int main(int argc, char* argv[]) { 
    
    if(argc < 4) { 

        return -1;
    }       

    auto encryptionsVec = MultiEncryptionsVec(argv, argc);
    Configuration conf(argv[1], argv[2], encryptionsVec);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();       
}

// g++ utest.cpp ../src/IEncryptor.cpp ../src/encryptionFactory.cpp ../src/messenger.cpp ../src/senderFactory.cpp ../src/messengerFactory.cpp ../src/sourceFactory.cpp ../src/IStream.cpp ../src/configuration.cpp ../src/messengerProtocol.cpp ../src/socket.cpp ../src/TCPClientSocket.cpp ../src/ISender.cpp -lws2_32


