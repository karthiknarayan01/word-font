#pragma once

#include <string>
#include <vector>

// Renders a word as large pixel-art characters in the terminal.
// Supported characters: a e i o u b c d f j l p t x z
class WordFont {
public:
    void readInput();
    void render();

private:
    std::string word;
    bool isBold;
    int fontSize;
    char pixelChar;

    // Copies a single character grid into the full canvas at the given column offset.
    void blitChar(std::vector<std::vector<char>>& canvas,
                  const std::vector<std::vector<char>>& letterGrid,
                  int colOffset);

    std::vector<std::vector<char>> drawA();
    std::vector<std::vector<char>> drawB();
    std::vector<std::vector<char>> drawC();
    std::vector<std::vector<char>> drawD();
    std::vector<std::vector<char>> drawE();
    std::vector<std::vector<char>> drawF();
    std::vector<std::vector<char>> drawI();
    std::vector<std::vector<char>> drawJ();
    std::vector<std::vector<char>> drawL();
    std::vector<std::vector<char>> drawO();
    std::vector<std::vector<char>> drawP();
    std::vector<std::vector<char>> drawT();
    std::vector<std::vector<char>> drawU();
    std::vector<std::vector<char>> drawX();
    std::vector<std::vector<char>> drawZ();
};
