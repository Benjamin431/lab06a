// WordCount.cpp

#include "WordCount.h"
#include <cctype>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0; 
	for(size_t i = 0; i < CAPACITY; i++){
		for (const auto& wordcount : table[i]) {
        	total += wordcount.second;

        }
	}

	return total;
}

int WordCount::getNumUniqueWords() const {
	int unique = 0; 
	for(size_t i = 0; i < CAPACITY; i++){
		unique += table[i].size();
	}

	return unique;
}

int WordCount::getWordCount(std::string word) const {
	word = makeValidWord(word);
    if (word == "") return 0;

    size_t index = hash(word);

    for(const auto &wordUsed : table[index]){
        if(wordUsed.first == word) {
            return wordUsed.second;
        }
    }

    return 0;
	
}
	
int WordCount::incrWordCount(std::string word) {
	word = makeValidWord(word);
    if (word == "") return 0;

    size_t index = hash(word);
	for(auto &wordUsed : table[index]){
        if(wordUsed.first == word){
            wordUsed.second += 1;
			return wordUsed.second;
        }
    }
	
	table[index].push_back(std::pair<std::string, int>(word, 1));
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
    if (word == "") return -1;

    size_t index = hash(word);
	for(size_t i = 0; i < table[index].size(); i++){
        auto &words = table[index][i];
        if(words.first == word){
            if(words.second > 1){
                words.second -= 1;
                return words.second;
            }
            table[index].erase(table[index].begin() + i);
            return 0;
        }
    }
	
	
	return -1;
}

bool WordCount::isWordChar(char c) {

	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	std::string updatedWord = "";
    for (size_t i = 0; i < word.size(); i++){
        char c = word[i];

        if(isalpha(c)){
            updatedWord += tolower(c);
        }
        else if((c == '\'' || c == '-') && i > 0 && i < word.size() - 1){
            updatedWord += c;
        }
    }
    while(!updatedWord.empty() && !isalpha(updatedWord.front())){
        updatedWord.erase(updatedWord.begin());
    }
    while(!updatedWord.empty() && !isalpha(updatedWord.back())){
        updatedWord.pop_back();
    }

    return updatedWord;
}
