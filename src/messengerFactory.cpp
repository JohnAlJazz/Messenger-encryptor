#include "../inc/messengerFactory.hpp"

#include <iostream>

namespace messenger {

MessengerFactory::MessengerFactory(Configuration& a_config) 
: m_config(a_config)
, m_source(m_config.GetSource())
, m_destination(m_config.GetDestination())
, m_encryption(m_config.GetEncryptionType())
{}

std::unique_ptr<Messenger> MessengerFactory::Get() {  

    auto source = m_source.Get();    
    auto destination = m_destination.Get();
    auto encryption = m_encryption.Get();
    
    return std::make_unique<Messenger>(std::move(source), std::move(destination), std::move(encryption));    
}

} //messenger