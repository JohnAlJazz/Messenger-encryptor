#include <iostream>
#include <tuple>
#include <string>

#include "../inc/senderFactory.hpp"

#define FILE_SUFFIX_LEN 4

namespace messenger {

static bool IsValidFilename(const std::string& a_arg) {

    const std::string::const_iterator curr = a_arg.end() - FILE_SUFFIX_LEN;

    std::string suffix(curr, a_arg.end());

    return suffix == ".txt";
}

static std::pair<std::string,uint16_t> GetNetworkData(const std::string& a_arg) {

    using Iter = std::string::const_iterator;

    Iter cur = a_arg.begin();    

    while(*cur != ':') {

        ++cur;
    } 

    std::string ip(a_arg.begin(), cur);
    std::string port(cur + 1, a_arg.end());      

    return {ip, static_cast<uint16_t>(stoi(port))};
}

std::unique_ptr<ISender> SenderFactory::Get() const{

    if(m_destination == "stdout") {

        return std::make_unique<SendToScreen>();
    }

    //write to a file
    else if(IsValidFilename(m_destination)){

        return std::make_unique<SendToFile>(m_destination);
    } 

    //write to a TCP server
    else {

        auto network = GetNetworkData(m_destination);
        
        return std::make_unique<SendToTCP>(network.first.c_str(), network.second);
    }

    std::cout << m_destination << "\n";           
}

} //messenger