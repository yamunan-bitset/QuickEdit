#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>

#include "handle.hh"

int main(int argc, char* argv[])
{
   std::cout << "Hello, World!" << std::endl;
   std::cout << "Opening: " << argv[1] << std::endl;
   std::vector <std::string> x;
   std::string input { };

   std::string file_QUI_(argv[1]);
      
   Handle event(argv[1]);
   
   while (true)
   {
     std::cin >> input;

     // Handle Events
     if      (input == ":q!")    break;
     else if (input == ":n!")       event.n(file_QUI_);
     else if (input == ":less!") event.less(file_QUI_); 
     else if (input == ":cat!")   event.cat(file_QUI_); 
     else if (input == ":file!") event.file(file_QUI_);	 
     else if (input == ":size!") event.size(file_QUI_);
     else      event.write(input);x.push_back(input);
       
            
   }
   for (std::string i: x)
     std::cout << "Wrote " << i << " to file: " << argv[1] << std::endl;
   return 0;
}
