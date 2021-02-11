#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

int main(int argc, char* argv[])
{
   std::cout << "Hello, World!" << std::endl;
   std::cout << "Opening: " << argv[1] << std::endl;
   std::vector <std::string> x;
   std::string input { };
   std::ofstream __FILE__OPEN__;
   
   __FILE__OPEN__.open(argv[1]);
	 
   while (true)
   {
	   std::cin >> input;
     if (input == ":q!") break;
		 else if (input == ":n!") __FILE__OPEN__ << std::endl;			
	   else if (input == ":less!")
		 {
			 __FILE__OPEN__ << std::endl;
			 std::stringstream __cmd__;
			 __cmd__ << "less " << argv[1];
			 std::system(__cmd__.str().c_str());
		 } else
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
