#ifndef TCP_SOCKET_EXCEPTIONS
#define TCP_SOCKET_EXCEPTIONS

#include <exception>

namespace net {

class TCPSocketExceptions : public std::exception {
public:
    TCPSocketExceptions(const char* a_what, const char* a_where) : m_what(a_what), m_where(a_where){}

    const char* what() const noexcept override;
    const char* where() const noexcept;

private:
    const char* m_what;
    const char* m_where;
};

#include "./inl/TCPSocketExceptions.hxx"

} // net

#endif //TCP_SOCKET_EXCEPTIONS

