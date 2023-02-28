#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <fstream>
#include <string>
#include <vector>

namespace messenger {

class Configuration {
private:
    using CStr = const std::string;
    using Encryptions = std::vector<std::string>&;
    
public:
    explicit Configuration(std::fstream& a_configFile);    
    explicit Configuration(CStr a_source, CStr a_destination, Encryptions a_encryptions);   
    std::string GetSource(); 
    std::string GetEncryptionType();
    std::string GetDestination();

private:
    std::string Source();
    std::string Encrypt();
    std::string Destination();
    std::string EncryptionsVec(Encryptions a_encryptions);

private:
    std::fstream& m_configFile;
    std::string m_source;
    std::string m_destination;
    std::string m_encrypt;

private:
    std::fstream m_dummy;
};

} //messenger

#endif //CONFIGURATION_HPP
