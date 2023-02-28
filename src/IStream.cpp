#include <iostream>

#include "../inc/IStream.hpp"

namespace messenger {

Stdin::Stdin() 
: m_isEnd(false)
, m_openMsg(true)
{}

std::string Stdin::Read() {
    
    if(m_openMsg) {

        std::cout << "Enter your message, '.' to end\n\n";
        m_openMsg = false;
    }

    std::string line;

    std::getline(std::cin, line);

    if(line == ".") {

        m_isEnd = true;               
    }   

    return line;
}

File::File(const std::string& a_file) 
: m_file(a_file)
, m_isEnd(false)
{}

std::string File::Read() {
    
    std::string line;  

    getline(m_file, line);  

    if(m_file.eof()) {

        m_isEnd = true;          
    }
    
    return line;    
}

} //messenger