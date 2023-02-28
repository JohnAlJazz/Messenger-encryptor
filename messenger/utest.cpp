#include <memory>
#include <fstream>

#include "messengerFactory.hpp"
#include "messenger.hpp"

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
