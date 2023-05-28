#include "View.h"

View::View(const std::string& name)
{
    this->name = name;
    
};

View::~View()
{
}

std::string View::GetName()
{
    return this->name;
}