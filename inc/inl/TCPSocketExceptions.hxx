#ifndef TCP_SOCKET_EXCEPTIONS_HXX
#define TCP_SOCKET_EXCEPTIONS_HXX

// TCPSocketExceptions::TCPSocketExceptions(const char* a_what, const char* a_where)
// : m_what(a_what)
// , m_where(a_where)
// {}


inline const char* TCPSocketExceptions::what() const noexcept {
    return m_what;
}

inline const char* TCPSocketExceptions::where() const noexcept {
    return m_where;
}

#endif //TCP_SOCKET_EXCEPTIONS_HXX