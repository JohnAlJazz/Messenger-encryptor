#ifndef ISENDER_HXX
#define ISENDER_HXX

inline SendToFile::SendToFile(const std::string a_file) 
: m_file(a_file)
{}

inline void SendToScreen::Send(std::string& a_message) {

    std::cout << a_message << '\n';
}

inline void SendToFile::Send(std::string& a_message) {

    m_file << a_message;    
}

#endif //ISENDER_HXX