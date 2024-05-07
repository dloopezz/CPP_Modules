#include "Phonebook.hpp"

bool all_of(const std::string& s, int (*func)(int))
{
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
        if (!func(*it))
            return false;
    }
    return true;
}

int stoi(const std::string& s)
{
    int n;

    std::istringstream stream(s);
    stream >> n;
    return n;
}
