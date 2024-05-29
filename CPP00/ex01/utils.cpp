#include "Phonebook.hpp"

bool all_of(const std::string& s, int (*func)(int))
{
    for (std::string::const_iterator i = s.begin(); i != s.end(); ++i)
	{
        if (!func(*i))
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
