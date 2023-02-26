#include "IEncryptor.hpp"

#include <unordered_map>
#include <ctype.h>
#include <sstream>
#include <string>

#define NUM_OF_LETTERS 26

namespace messenger {

RotKEncryptor::RotKEncryptor(int a_rotation)
: m_rotation(a_rotation)
{}

std::string RotKEncryptor::Encrypt(std::string& a_msg) {    

    for(auto& c : a_msg) {

        if(isupper(c)) {

            c = ((c - 'A' + m_rotation) % NUM_OF_LETTERS) + 'A';
        }

        else if(islower(c)) {

            c = ((c - 'a' + m_rotation) % NUM_OF_LETTERS) + 'a';
        }         
    }    

    return a_msg;
}

std::string XorEncryptor::Encrypt(std::string& a_msg) {
        
    std::stringstream ss;

    for(auto& c : a_msg) {

        int n = c;
        n ^= 'B';
        ss << std::hex << n;                 
    }    

    return ss.str();
}

MultiEncryptions::MultiEncryptions(std::vector<std::unique_ptr<IEncryptor>> a_vec) 
: m_vec(std::move(a_vec))
{}

std::string MultiEncryptions::Encrypt(std::string& a_msg) {

    for(auto& enc : m_vec) {

        a_msg = enc->Encrypt(a_msg);
    }
    
    return a_msg;
}

static void Swap(std::string& a_msg, int a_first, int a_second) {

    char temp = a_msg[a_first];
    a_msg[a_first] = a_msg[a_second];
    a_msg[a_second] = temp;
}

std::string ReverseEncryption::Encrypt(std::string& a_msg) {

    size_t numOfLetters = a_msg.length();

    size_t last = numOfLetters - 1;

    for(size_t i = 0; i < numOfLetters / 2; ++i, --last) {

        if(a_msg[i] != a_msg[last]) {

            Swap(a_msg, i, last);
        }
    }

    return a_msg;   
}

} //messenger