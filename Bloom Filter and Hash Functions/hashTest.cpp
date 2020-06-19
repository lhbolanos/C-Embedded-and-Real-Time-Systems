

#include <cstdlib>

using namespace std;

/*
 * 
 */
#include <iostream>
#include <string>
#include <sstream>
#include "HashFunctions.h"
#include "BloomFilter.h"


int main(int argc, char* argv[])
{
   std::string key = "";

   
   cout<<"Enter string to hash and store into bloom filter: ";
   cin >> key;
   
   

   std::cout << "Lucas Bolanos - Discrete Structures - Hashing Project         " << std::endl;
   std::cout << "Key: "                          << key           << std::endl;
   std::cout << " 1. RS-Hash Function Value:   " << RSHash  (key) << std::endl;
   std::cout << " 2. JS-Hash Function Value:   " << JSHash  (key) << std::endl;
   std::cout << " 3. PJW-Hash Function Value:  " << PJWHash (key) << std::endl;
   std::cout << " 4. ELF-Hash Function Value:  " << ELFHash (key) << std::endl;
   std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
   std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
   std::cout << " 7. DJB-Hash Function Value:  " << DJBHash (key) << std::endl;
   std::cout << " 8. DEK-Hash Function Value:  " << DEKHash (key) << std::endl;
   std::cout << "9. BP-Hash Function Value:   " << BPHash  (key) << std::endl;

   
   
   
   
   //unsigned int hash_list[] = {RSHash(key), JSHash(key), PJWHash(key), ELFHash(key), BKDRHash(key), SDBMHash(key), DJBHash(key), DEKHash (key), BPHash(key)};
   
   bloom_parameters parameters;

   // How many elements roughly do we expect to insert?
   parameters.projected_element_count = 1000;

   // Maximum tolerable false positive probability? (0,1)
   parameters.false_positive_probability = 0.0001; // 1 in 10000

   // Simple randomizer (optional)
   parameters.random_seed = 0xA5A5A5A5;

   if (!parameters)
   {
      std::cout << "Error - Invalid set of bloom filter parameters!" << std::endl;
      return 1;
   }

   parameters.compute_optimal_parameters();

   //Instantiate Bloom Filter
   bloom_filter filter(parameters);

   std::string strHolder;
   std::string strHolder2;
   std::string strHolder3;
   std::string strHolder4;
   std::string strHolder5;
   std::string strHolder6;
   std::string strHolder7;
   std::string strHolder8;
   std::string strHolder9;
   
   std::stringstream ss;
   std::stringstream ss2;
   std::stringstream ss3;
   std::stringstream ss4;
   std::stringstream ss5;
   std::stringstream ss6;
   std::stringstream ss7;
   std::stringstream ss8;
   std::stringstream ss9;
   
   
   ss << RSHash(key);
   ss2 << JSHash(key);
   ss3 << PJWHash(key);
   ss4 << ELFHash(key);
   ss5 << BKDRHash(key);
   ss6 << SDBMHash(key);
   ss7 << DJBHash(key);
   ss8 << DEKHash(key);
   ss9 << BPHash(key);
   
   strHolder = ss.str();
   strHolder2 = ss2.str();
   strHolder3 = ss3.str();
   strHolder4 = ss4.str();
   strHolder5 = ss5.str();
   strHolder6 = ss6.str();
   strHolder7 = ss7.str();
   strHolder8 = ss8.str();
   strHolder9 = ss9.str();
   
   std::string str_list[] = {strHolder,strHolder2,strHolder3,strHolder4,strHolder5,strHolder6,strHolder7,strHolder8,strHolder9};
  

   // Insert into Bloom Filter
   {
      // Insert some strings
      for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i)
      {
         filter.insert(str_list[i]);
      }

   }

   std::string key2 = "";
   //std::string userIn = "";
   
   cout << "Enter string to check filter for: ";
   cin>>key2;
   
   
   std::string strHolderQ;
   std::string strHolder2Q;
   std::string strHolder3Q;
   std::string strHolder4Q;
   std::string strHolder5Q;
   std::string strHolder6Q;
   std::string strHolder7Q;
   std::string strHolder8Q;
   std::string strHolder9Q;
   
   std::stringstream ssQ;
   std::stringstream ss2Q;
   std::stringstream ss3Q;
   std::stringstream ss4Q;
   std::stringstream ss5Q;
   std::stringstream ss6Q;
   std::stringstream ss7Q;
   std::stringstream ss8Q;
   std::stringstream ss9Q;
   
   
   ssQ << RSHash(key2);
   ss2Q << JSHash(key2);
   ss3Q << PJWHash(key2);
   ss4Q << ELFHash(key2);
   ss5Q << BKDRHash(key2);
   ss6Q << SDBMHash(key2);
   ss7Q << DJBHash(key2);
   ss8Q << DEKHash(key2);
   ss9Q << BPHash(key2);
   
   strHolderQ = ss.str();
   strHolder2Q = ss2Q.str();
   strHolder3Q = ss3Q.str();
   strHolder4Q = ss4Q.str();
   strHolder5Q = ss5Q.str();
   strHolder6Q = ss6Q.str();
   strHolder7Q = ss7Q.str();
   strHolder8Q = ss8Q.str();
   strHolder9Q = ss9Q.str();
   
   

   std::string str_list2[] = {strHolderQ,strHolder2Q,strHolder3Q,strHolder4Q,strHolder5Q,strHolder6Q,strHolder7Q,strHolder8Q,strHolder9Q};
   
   
   // Query Bloom Filter
   {
      // Query the existence of strings
      for (std::size_t i = 0; i < (sizeof(str_list) / sizeof(std::string)); ++i)
      {
         if (filter.contains(str_list2[i]))
         {
            std::cout << "BF contains: " << key2 << std::endl;
         }
      }


   
   return 1;
}
}
