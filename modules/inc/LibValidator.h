#include <regex>
#include <string>
#include <vector>

class Validator 
{
    private:
        std::regex pattern;

    public:
        Validator(const std::string& pattern);
        void setPattern(const std::string& pattern);
        std::string getPattern() const;

        bool Match(const std::string& input) const;
        bool partialMatch(const std::string& input) const;

        std::vector<std::string> getMatches(std::string& input) const;
};