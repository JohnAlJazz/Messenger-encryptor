#ifndef ENCRYPTION_FACTORY_HPP
#define ENCRYPTION_FACTORY_HPP

#include <memory>
#include <string>

#include "IEncryptor.hpp"

namespace messenger {

class EncryptionFactory {
public:
    explicit EncryptionFactory(const std::string a_encryption);
    
    std::unique_ptr<IEncryptor> Get();

private:    
    bool IsMultiEncryptions();
    std::unique_ptr<IEncryptor> CreateEncryptor(const std::string& a_enc);

private:
    const std::string m_encryption;
};

#include "inl/encryptionFactory.hxx"

} //messenger

#endif //ENCRYPTION_FACTORY_HPP

#include "inl/encryptionFactory.hxx"