#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./main <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string in_filename = av[1];
    std::string out_filename = in_filename + ".replace";

    std::ifstream ifile (in_filename.c_str());
    if (!ifile.is_open())
    {
        std::cerr << "Error opening: " << in_filename << std::endl;
        return (1);
    }
    std::ofstream ofile (out_filename.c_str());
    if (!ofile.is_open())
    {
        ifile.close();
        std::cerr << "Error opening: " << out_filename << std::endl;
        return (1);
    }
    std::string s1 = av[2], s2 = av[3];
    std::string line;

    while (getline(ifile, line))
    {
        if (s1.empty())
        {
            ofile << line << '\n';
            continue;
        }
    
        size_t  line_length = line.length();
        size_t  str_size = s1.length();
    
        std::size_t line_i = 0;
        std::size_t index = line.find(s1, line_i);
        while (index != std::string::npos)
        {
            ofile << line.substr(line_i, index - line_i);
            ofile << s2;
            line_i = (index + str_size);
            index = line.find(s1, line_i);
        }
        if (line_i < line_length)
            ofile << line.substr(line_i, std::string::npos);
        ofile << '\n';
    }
    ifile.close();
    ofile.close();
    return 0;
}
