#pragma once

#include <string>

UENUM(BlueprintType)
enum class ELetter : uint8
{ A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z };

class EnigmaLetter
{
private:
    static const std::string AllLetters;
public:
    static int getIndex(char letter);
    static char getLetter(int index);
};
