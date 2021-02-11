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

	 char* _File_;
   
	 if (argc > 1) 
	 {
	   __FILE__OPEN__.open(argv[1]);
		 _File_ = argv[1];	
	 }

   if (argc == 1)
	 {
	 		char* File_QQ { };
   		std::cin >> File_QQ;
			std::cout << "What file do you want to open? " << std::endl;		
			__FILE__OPEN__.open(File_QQ);
			_File_ = File_QQ;
   }
   
   while (true)
   {

	   std::cin >> input;

     if (input == ":q!") break;
			
	   if (input == ":less!")
		 {
			 std::stringstream __cmd__;
			 __cmd__ << "less " << _File_;
			 std::system(__cmd__.str().c_str());
		 } else
		 {
       	__FILE__OPEN__ << input << std::endl;
      	x.push_back(input);
		 }
   }


   __FILE__OPEN__.close();
   for (std::string i: x)
     std::cout << "Wrote " << i << " to file: " << argv[1] << std::endl;

   return 0;
}
