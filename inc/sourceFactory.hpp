#ifndef SOURCE_FACTORY_HPP
#define SOURCE_FACTORY_HPP

#include <memory>
#include <string>

#include "IStream.hpp"

namespace messenger {

class SourceFactory {
public:
    explicit SourceFactory(const std::string a_source);
    std::unique_ptr<IStream> Get();

private:
    const std::string m_source;
};

} //messenger

#endif //SOURCE_FACTORY_HPP