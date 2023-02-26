#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <memory>
#include <string>
#include <fstream>

#include "IEncryptor.hpp"
#include "ISender.hpp"
#include "IStream.hpp"

namespace messenger{

class Messenger {
private:
    using Stream = std::unique_ptr<IStream>;
    using Destination = std::unique_ptr<ISender>;
    using Encryptor = std::unique_ptr<IEncryptor>;

public:
    Messenger(Stream a_stream, Destination a_destination, Encryptor a_encryptor);   
    
    void Send() const;

private:
    std::unique_ptr<IStream> m_stream;
    std::unique_ptr<IEncryptor> m_encryptor;
    std::unique_ptr<ISender> m_destination;
};

#include "inl/messenger.hxx"

} //messsenger

#endif //MESSENGER_HPP