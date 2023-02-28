#include "../inc/messengerProtocol.hpp"

namespace messenger {

static void InitVecWithMsgLen(std::vector<char>& a_packedVec, unsigned char* a_ptrSize) {

    for(size_t i = 0; i < sizeof(size_t); ++i) {

        a_packedVec.push_back(a_ptrSize[i]);
    }
}

static void FillVecWithLetters(std::vector<char>& a_packedVec, const std::string& a_msg) {

    for(auto letter : a_msg) {

        a_packedVec.push_back(letter);               
    }
}

std::vector<char> Protocol::Pack(const std::string& a_msg) {
    
    std::vector<char> packedVec;     
    size_t size = a_msg.length();
    unsigned char* ptrSize = reinterpret_cast<unsigned char*>(&size);    

    InitVecWithMsgLen(packedVec, ptrSize);

    FillVecWithLetters(packedVec, a_msg);    

    return packedVec;
}

std::string Protocol::UnPack(std::unique_ptr<net::Client>& a_client) {
    
    std::vector<char> uscVec = a_client->Receive();
    size_t* nthDsize = reinterpret_cast<size_t*>(&uscVec[0]);       
    std::string newMsg;    
    size_t i = sizeof(size_t);

    auto recvVecLen = uscVec.size();

    //if there's a msg, copy each char, starting from 8th byte
    if(recvVecLen > sizeof(size_t)) {

        for(; i < recvVecLen; ++i) {

            newMsg.push_back(uscVec[i]);       
        }
    }
     
    while(uscVec.size() < *nthDsize) {

        uscVec = a_client->Receive();

        for(; i < uscVec.size(); ++i) {

            newMsg.push_back(uscVec[i]);
        } 
    }     

    return newMsg;
}

} //messenger


    // double dSize = be64toh(*nthDsize);
    // size_t size = static_cast<size_t>(dSize);