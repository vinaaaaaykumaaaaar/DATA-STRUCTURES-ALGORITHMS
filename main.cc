#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream f("main.py");

    if (!f.is_open())
    {
        std::cerr << "Error opening the file!";
        return 1;
    }

    std::string s;

    // Read each line from the file
    while (std::getline(f, s))
        std::cout << s << std::endl;

    // Close the file
    f.close();

    return 0;
}
