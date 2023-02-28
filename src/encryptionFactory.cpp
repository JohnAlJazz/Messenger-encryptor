#include <sstream>
#include <vector>

#include "../inc/encryptionFactory.hpp"
#include <iostream>

namespace messenger {

std::unique_ptr<IEncryptor> EncryptionFactory::Get() {

    if(IsMultiEncryptions()) {

        std::vector<std::unique_ptr<IEncryptor>> encryptionsVec;
        std::stringstream ss{m_encryption};
        std::string encryption;

        while(ss >> encryption) {

            encryptionsVec.push_back(CreateEncryptor(encryption));
        }

        return std::make_unique<MultiEncryptions>(std::move(encryptionsVec));
    } 

    return CreateEncryptor(m_encryption);    
}

bool EncryptionFactory::IsMultiEncryptions() {

    std::stringstream ss{m_encryption};
    std::string first;
    std::string second;

    ss >> first;
    ss >> second;

    return first.length() && second.length();
}

std::unique_ptr<IEncryptor> EncryptionFactory::CreateEncryptor(const std::string& a_enc) {
    
    if(a_enc == ".") {
        
        return std::make_unique<NoEncryption>();
    }

    if(a_enc == "rot13") {

        return std::make_unique<RotKEncryptor>(13);
    }

    if(a_enc == "xor") {

        return std::make_unique<XorEncryptor>();
    }

    if(a_enc == "upper") {
    
        return std::make_unique<UpperCaseEncryptor>();
    }

    if(a_enc == "reverse") {

        return std::make_unique<ReverseEncryption>();
    }

    else { 

        throw std::runtime_error("no such encryption\n");       
    }
}

} //messenger