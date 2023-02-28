#include <iostream>

#include "../inc/sourceFactory.hpp"

namespace messenger {

SourceFactory::SourceFactory(const std::string a_source)
: m_source(a_source)
{  
  if(!a_source.length()) {
    
    throw std::runtime_error("no available source\n");   
  }
}

std::unique_ptr<IStream> SourceFactory::Get() {

    if(m_source == "stdin") {
      
      return std::make_unique<Stdin>();
    } 

    //read from file
    else {
      
      return std::make_unique<File>(m_source);
    } 
}

} //messenger