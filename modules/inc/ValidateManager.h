#pragma once
#include <regex>
#include <string>
#include <vector>

class ValidateManager 
{
    private:
        std::regex pattern;

    public:
        ValidateManager(const std::string& pattern);
        void SetPattern(const std::string& pattern);

        bool Match(const std::string& input) const;
        bool PartialMatch(const std::string& input) const;

        std::vector<std::string> GetMatches(std::string& input) const;
};