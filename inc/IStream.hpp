#ifndef ISTREAM_HPP
#define ISTREAM_HPP

#include <string>
#include <fstream>

namespace messenger {

class IStream {
public:
    virtual ~IStream() = default;

    virtual std::string Read() = 0;
    virtual bool IsEnd() = 0;    

protected: 
    IStream() = default;
    IStream(const IStream&) = default;
    IStream& operator=(const IStream&) = default;
};

class Stdin : public IStream {
public:
    Stdin();
    
    std::string Read() override;
    bool IsEnd() override;

private:
    bool m_isEnd;
    bool m_openMsg;
};

class File : public IStream {
public:
    File(const std::string& a_file);

    std::string Read() override;
    bool IsEnd() override;

private:
    std::ifstream m_file;
    bool m_isEnd;
};

#include "inl/IStream.hxx"

} //messenger 

#endif //ISTREAM_HPP
