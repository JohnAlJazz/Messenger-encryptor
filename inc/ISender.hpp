#ifndef ISENDER_HPP
#define ISENDER_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "TCPClientSocket.hpp"

namespace messenger {

class ISender {
public:
    virtual ~ISender() = default;

    virtual void Send(std::string& a_message) = 0;

protected: 
    ISender() = default;
    ISender(const ISender&) = default;
    ISender& operator=(const ISender&) = default;
};

class SendToScreen : public ISender {
public:    
    void Send(std::string& a_message) override;
};

class SendToFile : public ISender {
public:
    SendToFile(const std::string a_file);
    void Send(std::string& a_message) override;

private:
    std::ofstream m_file;
};

class SendToTCP : public ISender {
public: 
    SendToTCP(std::string a_ip, uint16_t a_port);
    void Send(std::string& a_message) override;

private:
    std::string m_ip;
    uint16_t m_port;
    net::Client m_client;
};

#include "inl/Isender.hxx"

} //messsenger

#endif //ISENDER_HPP