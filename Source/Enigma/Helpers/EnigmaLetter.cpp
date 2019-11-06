#include "EnigmaLetter.h"

const std::string EnigmaLetter::AllLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int EnigmaLetter::getIndex(char letter)
{
    for (int i = 0; i < EnigmaLetter::AllLetters.length(); i++) {
        if (EnigmaLetter::AllLetters[i] == letter) {
            return i;
        }
    }

    return -1;
}

char EnigmaLetter::getLetter(int index)
{
    return EnigmaLetter::AllLetters[index];
}
