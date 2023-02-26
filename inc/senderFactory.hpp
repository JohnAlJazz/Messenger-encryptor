#ifndef SENDER_FACTORY_HPP
#define SENDER_FACTORY_HPP

#include <memory>
#include <string>

#include "ISender.hpp"

namespace messenger {

class SenderFactory {
public:
    explicit SenderFactory(const std::string a_destination);
    
    std::unique_ptr<ISender> Get() const;

private:
    const std::string m_destination;
};

#include "inl/senderFactory.hxx"
    
} //messenger

#endif //SENDER_FACTORY_HPP