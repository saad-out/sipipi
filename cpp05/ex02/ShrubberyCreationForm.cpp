#include "ShrubberyCreationForm.hpp"
#include <fstream>

void printTree(int height, std::ofstream &file) {
    // Print the leaves of the tree
    for (int i = 1; i <= height; ++i) {
        // Print leading spaces for alignment
        for (int j = i; j < height; ++j)
            file << " ";
        
        // Print the stars to form the leaves
        for (int k = 1; k <= (2 * i - 1); ++k)
            file << "*";
        
        // Move to the next line after printing one row of leaves
        file << std::endl;
    }
    
    // Print the trunk of the tree
    for (int i = 0; i < height / 3; ++i) {
        // Align the trunk
        for (int j = 0; j < height - 1; ++j)
            file << " ";
        
        // Print trunk
        file << "||" << std::endl;
    }
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (file.is_open()) {
        for (int i = 0; i < 3; ++i)
        {
            printTree(5 * (i + 1), file);
            file << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error: could not open file " << filename << std::endl;
    }
}

void ShrubberyCreationForm::myType() const
{
    std::cout << "ShrubberyCreationForm" << std::endl;
}

