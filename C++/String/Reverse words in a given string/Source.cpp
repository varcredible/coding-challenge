#include <iostream>
using std::string;

// I decided to find the count of words regarding spaces in the sentence //
int getCountOfWords(string __input)
{
	unsigned int CountOfWords = 0;

	for (size_t indexOfLetter = 0; indexOfLetter < __input.length(); indexOfLetter++)
	{
		if (__input[indexOfLetter] == ' ')
		{
			CountOfWords++;
		}
	}

	return CountOfWords + 1; // +1 — a last word in sentence after the last space
}

string getTheResult(string* _words, const unsigned int _COUNT_OF_WORDS)
{
	string result;

	for (size_t indexOfWord = 0; indexOfWord < _COUNT_OF_WORDS; indexOfWord++)
	{
		result += _words[indexOfWord];

		if (indexOfWord != _COUNT_OF_WORDS - 1)
		{
			result += ' ';
		}

	}

	return result;
}

string* reverseTheWordsBack(string* _words, const unsigned int _COUNT_OF_WORDS)
{
	for (size_t indexOfWord = 0; indexOfWord < _COUNT_OF_WORDS; indexOfWord++)
	{
		std::reverse(_words[indexOfWord].begin(), _words[indexOfWord].end());
	}

	return _words;
}

string* fillTheArrayWords(string* _words, string __input)
{
	const unsigned int INPUT_LENGTH = __input.length();
	
	for (size_t indexOfLetter = 0, indexOfWord = 0; indexOfLetter < INPUT_LENGTH; indexOfLetter++)
	{
		if (__input[indexOfLetter] != ' ')
		{
			_words[indexOfWord] += __input[indexOfLetter];
		}

		else
		{
			indexOfWord++;
		}
	}

	return _words;
}

string reverseInput(string _input)
{
	std::reverse(_input.begin(), _input.end());
	const unsigned int INPUT_LENGTH = _input.length();
	const unsigned int COUNT_OF_WORDS = getCountOfWords(_input);
	string* words = new std::string[COUNT_OF_WORDS];
	
	fillTheArrayWords(words, _input);
	reverseTheWordsBack(words, COUNT_OF_WORDS);

	string result = getTheResult(words, COUNT_OF_WORDS);

	delete[] words;
	
	return result;
}

int main()
{
	string input = "I love programming very much";
	reverseInput(input); // -> Output: much very programming love I 
	
	return 0;
}
