#ifndef IENCRYPTOR_HXX
#define IENCRYPTOR_HXX

#include <string>
#include <cctype>

inline std::string UpperCaseEncryptor::Encrypt(std::string& a_msg) {   

    std::string upper{a_msg};

    for(auto& c : upper) {

        c = ::toupper(c);
    }  

    return upper;
}

inline std::string NoEncryption::Encrypt(std::string& a_msg) {
    
    return a_msg;
}

#endif //IENCRYPTOR_HXX