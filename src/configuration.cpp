#include <iostream>

#include "configuration.hpp"

namespace messenger {

static std::fstream& CheckFile(std::fstream& a_conf) {

    if(!a_conf) {

        throw std::runtime_error("file doesn't exist\n");
    }

    else {

        return a_conf;
    }
}

Configuration::Configuration(std::fstream& a_configFile)
: m_configFile(CheckFile(a_configFile))
, m_source(Source())
, m_destination(Destination())
, m_encrypt(Encrypt())
{}

Configuration::Configuration(CStr a_source, CStr a_destination, Encryptions a_encryptions)
: m_configFile(m_dummy)
, m_source(a_source)
, m_destination(a_destination)
, m_encrypt(EncryptionsVec(a_encryptions))
{}

std::string Configuration::Source() {

    std::string source;

    m_configFile >> source; 

    return source;
}

std::string Configuration::Destination() {

    std::string dest;

    m_configFile >> dest;

    return dest;
}

std::string Configuration::Encrypt() {

    std::string encrypt;
    std::string temp;
    
    //in case of multiple encryptions
    while(!m_configFile.eof()) {

        m_configFile >> temp;
        encrypt += temp;

        if(!m_configFile.eof()) {

            encrypt += " ";
        }
    }  
      
    return encrypt;
}

std::string Configuration::EncryptionsVec(Encryptions a_encryptions) {

    std::string encryptions;

    auto size = a_encryptions.size();

    for(size_t i = 0; i < size; ++i) {

        encryptions += a_encryptions[i];

        if(i + 1 < size) {

            encryptions += " ";
        }
    }

    return encryptions;
}

std::string Configuration::GetSource() {

    return m_source;     
}

std::string Configuration::GetDestination() {

    return m_destination;
}

std::string Configuration::GetEncryptionType() {

    return m_encrypt;
}

} //messenger