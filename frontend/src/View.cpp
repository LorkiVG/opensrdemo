#include "View.h"

View::View(const std::string& tag) : ElementDocument(tag)
{
    this->Hide();
};

View::~View()
{
}