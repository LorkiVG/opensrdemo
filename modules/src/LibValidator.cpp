#include "LibValidator.h"

Validator::Validator(const std::string& pattern) {
    this->pattern = pattern;
}
void Validator::setPattern(const std::string& pattern)
{
    this->pattern = pattern;
}

bool Validator::Match(const std::string& input) const 
{
    return std::regex_match(input, this->pattern);
}
bool Validator::partialMatch(const std::string& input) const 
{
    return std::regex_search(input, this->pattern);
}

std::vector<std::string> Validator::getMatches(std::string& input) const
{
    std::smatch match;
    std::vector<std::string> matches;

    while (std::regex_search(input, match, this->pattern)) 
    {
        for (const auto& m : match) 
        {
            matches.push_back(m.str());
        }
        input = (std::string)(match.suffix().str());
    }

    return matches;
}