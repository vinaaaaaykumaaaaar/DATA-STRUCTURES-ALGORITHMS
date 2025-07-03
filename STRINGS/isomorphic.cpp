#include<iostream>
#include <string>
#include <vector>

using namespace std;


class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        if (s.length() != t.length())
        {
            return false; // Strings of different lengths cannot be isomorphic
        }

        std::vector<int> mapS(256, 0); // Mapping from s characters to integers
        std::vector<int> mapT(256, 0); // Mapping from t characters to integers

        for (int i = 0; i < s.length(); ++i)
        {
            // Check if the current mapping is consistent
            if (mapS[s[i]] != mapT[t[i]])
            {
                return false;
            }

            // Establish the mapping if not already done
            if (mapS[s[i]] == 0)
            {
                mapS[s[i]] = i + 1; // Use i+1 to distinguish from initial 0
                mapT[t[i]] = i + 1;
            }
        }

        return true; // If the loop completes without finding inconsistency, strings are isomorphic
    }
};

int main()
{

    Solution s;
    std::cout<<s.isIsomorphic("egg","add")<<endl;
}