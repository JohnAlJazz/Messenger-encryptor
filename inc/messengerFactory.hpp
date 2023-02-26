#ifndef MESSENGER_FACTORY_HPP
#define MESSENGER_FACTORY_HPP

#include <memory>
#include <string>
#include <fstream>

#include "encryptionFactory.hpp"
#include "senderFactory.hpp"
#include "sourceFactory.hpp"
#include "messenger.hpp"
#include "configuration.hpp"

namespace messenger {

class MessengerFactory {
public:
    explicit MessengerFactory(Configuration& a_config); 
    MessengerFactory(const MessengerFactory&) = delete; 
    MessengerFactory& operator=(const MessengerFactory&) = delete; 
    ~MessengerFactory() = default; 

    std::unique_ptr<Messenger> Get();
    
private:
    Configuration& m_config;
    SourceFactory m_source;
    SenderFactory m_destination;
    EncryptionFactory m_encryption;    
};

#include "inl/messengerFactory.hxx"

} //messenger

#endif //MESSENGER_FACTORY_HPP

