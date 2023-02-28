#ifndef IENCRYPTOR_HPP
#define IENCRYPTOR_HPP

#include <string>
#include <vector>
#include <memory>

namespace messenger {

class IEncryptor {
public:
    virtual ~IEncryptor() = default;    
    virtual std::string Encrypt(std::string& a_msg) = 0;

protected: 
    IEncryptor() = default;
    IEncryptor(const IEncryptor&) = default;
    IEncryptor& operator=(const IEncryptor&) = default;
};

class RotKEncryptor : public IEncryptor {
public:    
    explicit RotKEncryptor(int a_rotation);
    std::string Encrypt(std::string& a_msg) override;

private:
    int m_rotation;
};

class XorEncryptor : public IEncryptor {
public:
    std::string Encrypt(std::string& a_msg) override;      
};

class UpperCaseEncryptor : public IEncryptor {
public:
    std::string Encrypt(std::string& a_msg) override;    
};

class NoEncryption : public IEncryptor {
public:
    std::string Encrypt(std::string& a_msg) override;
};

class ReverseEncryption : public IEncryptor {
public:
    std::string Encrypt(std::string& a_msg) override;
};

class MultiEncryptions : public IEncryptor {
public:
    explicit MultiEncryptions(std::vector<std::unique_ptr<IEncryptor>> a_vec);
    std::string Encrypt(std::string& a_msg) override;

private:    
    std::vector<std::unique_ptr<IEncryptor>> m_vec;    
};

#include "inl/IEncryptor.hxx"

} //messsenger

#endif //IENCRYPTOR_HPP