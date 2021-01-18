#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::endl;


std::vector<std::string> alphabetized(std::vector<std::string>& m_words)
{
	for (auto& first : m_words)
	{
		for (auto& second : m_words)
		{
			if (first == second)
				continue;

			bool comp_res = std::lexicographical_compare(first.begin(), first.end(), second.begin(), second.end());
			if (!comp_res)
			{
				std::swap(first, second);
			}
		}
	}

	std::vector<std::string> m_words_rev(m_words.rbegin(), m_words.rend());

	return m_words_rev;
}


int main()
{
	std::vector<std::string> m_words{ "these", "are", "my", "words", "that", "will", "be", "alphabetized" };
	std::vector<std::string> m_words_alphabetized = alphabetized(m_words);

	puts("Alphabetized Words:");
	for (auto& m : m_words_alphabetized)
	{
		cout << m << endl;
	}

	return 0;
}
