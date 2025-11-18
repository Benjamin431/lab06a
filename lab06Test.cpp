#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    WordCount bs;

    ASSERT_EQUALS(0, bs.getTotalWords());
    ASSERT_EQUALS("monkeys", WordCount::makeValidWord("Monkeys"));
    ASSERT_EQUALS(0, bs.getNumUniqueWords());
    ASSERT_EQUALS(0, bs.getWordCount("new"));
    ASSERT_EQUALS(-1, bs.decrWordCount("1111"));
    ASSERT_EQUALS("monkeys", WordCount::makeValidWord("12mOnkEYs-$"));
    ASSERT_EQUALS("can't", WordCount::makeValidWord("Can't"));
    ASSERT_EQUALS("good-hearted", WordCount::makeValidWord("good-hearted"));
    ASSERT_EQUALS("hello", WordCount::makeValidWord("hello---"));
    ASSERT_EQUALS("hello", WordCount::makeValidWord("---hello"));
    ASSERT_EQUALS("hel--lo", WordCount::makeValidWord("hel--lo"));
    ASSERT_EQUALS("happen'ed", WordCount::makeValidWord("happen'ed"));

  
    ASSERT_EQUALS(1, bs.incrWordCount("new"));  
    ASSERT_EQUALS(2, bs.incrWordCount("new"));
    ASSERT_EQUALS(2, bs.getWordCount("new"));
    ASSERT_EQUALS(2, bs.getTotalWords());
    ASSERT_EQUALS(1, bs.getNumUniqueWords());  

    ASSERT_EQUALS(1, bs.incrWordCount("pinapple"));
    ASSERT_EQUALS(3, bs.getTotalWords());
    ASSERT_EQUALS(2, bs.getNumUniqueWords());

    ASSERT_EQUALS(0, bs.incrWordCount("1234!@#")); 
    ASSERT_EQUALS(-1, bs.decrWordCount("1234!@#"));     
    return 0;
}