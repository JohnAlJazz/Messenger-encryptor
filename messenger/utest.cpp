#include <memory>
#include <fstream>

#include "messengerFactory.hpp"
#include "messenger.hpp"

using namespace messenger; 

#ifndef THE_TEST

static std::vector<std::string> MultiEncryptionsVec(char** argv, int argc) {

    std::vector<std::string> encryptions;

    for(int i = 3; i < argc; ++i) {

        encryptions.push_back(argv[i]);
    }

    return encryptions;
}

int main(int argc, char* argv[]) { 
    
    if(argc < 4) { 

        return -1;
    }       

    auto encryptionsVec = MultiEncryptionsVec(argv, argc);
    Configuration conf(argv[1], argv[2], encryptionsVec);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();       
}

#else

#include "mu_test.h"

using namespace messenger;

BEGIN_TEST(test_messenger_wrong_conf_file) 

    try {

        std::fstream file("blah");
        Configuration conf(file);
        MessengerFactory messengerFact(conf);  
        auto msg = messengerFact.Get();     
        msg->Send(); 
    }

    catch(const std::runtime_error& e) {

        std::cout << e.what() << '\n';
    }
    
    ASSERT_PASS();
END_TEST

BEGIN_TEST(test_messenger_UPPER_configuration) 
    
    std::fstream file("./files/upper_config.txt");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);      
    auto msg = messengerFact.Get();     

    msg->Send();   
    
    ASSERT_PASS();
END_TEST

BEGIN_TEST(test_messenger_Rot13_configuration) 
    
    std::fstream file("./files/rot13_config.txt");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST

BEGIN_TEST(test_xor42_to_screen)           
    
    std::fstream file("./files/xor42");
    Configuration conf(file);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();

    ASSERT_PASS();
END_TEST

BEGIN_TEST(test_messenger_upper_from_file_to_screen) 
    
    std::fstream file("./files/ff.txt");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST

BEGIN_TEST(test_messenger_upper_write_to_file) 
    
    std::fstream file("./files/upperToFile.txt");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST

BEGIN_TEST(test_messenger_upper_file_to_file) 
    
    std::fstream file("./files/file_to_file");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST

BEGIN_TEST(test_multi_to_screen)           
    
    std::fstream file("./files/multi");
    Configuration conf(file);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();

    ASSERT_PASS();
END_TEST

BEGIN_TEST(test_screen_to_tcp_server)           
        
    std::fstream file("./files/toTcp");
    Configuration conf(file);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();

    ASSERT_PASS();
    
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)

    // TEST(test_messenger_wrong_conf_file)
    // TEST(test_messenger_UPPER_configuration)
    // TEST(test_messenger_Rot13_configuration)  
    // TEST(test_xor42_to_screen) 
    // TEST(test_messenger_upper_from_file_to_screen)
    // TEST(test_messenger_upper_write_to_file)
    // TEST(test_messenger_upper_file_to_file)
    // TEST(test_multi_to_screen) 
    TEST(test_screen_to_tcp_server)  

END_SUITE

#endif