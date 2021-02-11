#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(int argc, char* argv[])
{
   std::cout << "Hello, World!" << std::endl;
   std::cout << "Opening: " << argv[1] << std::endl;

   std::vector <std::string> x;
   std::string input {};
        std::ofstream __FILE__OPEN__;
        __FILE__OPEN__.open(argv[1]);

   while (true)
     {

        std::cin >> input;
        if (input == ":q!")
          break;

        __FILE__OPEN__ << input;
        x.push_back(input);

     }

   __FILE__OPEN__.close();
   for (std::string i: x)
     std::cout << "Wrote " << i << " to file: " << argv[1] << std::endl;

   return 0;
}
