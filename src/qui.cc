#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "handle.hh"

int main(int argc, char* argv[])
{
   std::cout << "Hello, World!" << std::endl;
   std::cout << "Opening: " << argv[1] << std::endl;
   std::vector <std::string> x;
   std::string input { };

   Handle event(&argv);
   
   while (true)
   {
     std::cin >> input;
     if (input == ":q!") break;
     else if (input == ":n!") __FILE__OPEN__ << std::endl;			
     
     else if (input == ":less!")
       {
	 /*	 __FILE__OPEN__ << std::endl;
	 std::stringstream __cmd__;
	 __cmd__ << "less " << argv[1];
	 std::system(__cmd__.str().c_str());*/
	 event.less(argv[1]);
       } 
     else if (input == ":cat!")
       {
	 /*__FILE__OPEN__ << std::endl;
	 std::stringstream __cmd__;
	 __cmd__ << "cat " << argv[1];
	 std::system(__cmd__.str().c_str());*/
       }
     else if (input == ":file!")
       {
	 /*__FILE__OPEN__ << std::endl;
	 std::stringstream __cmd__;
	 __cmd__ << "file " << argv[1];
	 std::system(__cmd__.str().c_str());*/
	 event.file(argv[1]);
	 
       }
     else if (input == ":size!")
       {
	 /*__FILE__OPEN__ << std::endl;
	   std::stringstream __cmd__;
	   __cmd__ << "du -sh " << argv[1];
	   std::system(__cmd__.str().c_str());*/
	 event.size(argv[1]);
       }
     else
       {
	 __FILE__OPEN__ << input;
	 x.push_back(input);
       }
     
   }
   __FILE__OPEN__.close();
   for (std::string i: x)
     std::cout << "Wrote " << i << " to file: " << argv[1] << std::endl;
   return 0;
}
