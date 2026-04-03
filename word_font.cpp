#include "word_font.h"

#include <cctype>
#include <iostream>

/*
  Each draw*() method fills a fontSize×fontSize grid with pixelChar at positions
  that trace the character's strokes. Every character is defined as a set of line
  equations over (row, col) coordinates where (0,0) is the top-left corner.

  Non-bold: single-pixel strokes.
  Bold:     two-pixel-wide strokes (adjacent rows/cols both filled).
*/

// ── A ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, left col, right col, middle row
// Bold:     rows 0-1, cols 0-1, cols (n-2)-(n-1), rows (n/2-1)-(n/2)
std::vector<std::vector<char>> WordFont::drawA() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 || c == 0 || c == 1 ||
                   c == n - 2 || c == n - 1 ||
                   r == n / 2 || r == n / 2 - 1)
                : (r == 0 || c == 0 || c == n - 1 || r == n / 2);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── B ──────────────────────────────────────────────────────────────────────
// Non-bold: top/bottom/mid rows, left/right cols; skip top-right & bottom-right corners
// Bold:     same with double-width strokes; skip 2×2 top-right & bottom-right corners
std::vector<std::vector<char>> WordFont::drawB() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke, atCorner;
            if (isBold) {
                onStroke = (r == 0 || r == 1 || r == n - 1 || r == n - 2 ||
                            r == n / 2 || r == n / 2 - 1 ||
                            c == 0 || c == 1 || c == n - 1 || c == n - 2);
                atCorner = ((r == 0 || r == 1) && (c == n - 1 || c == n - 2)) ||
                           ((r == n - 1 || r == n - 2) && (c == n - 1 || c == n - 2));
            } else {
                onStroke = (r == 0 || r == n - 1 || r == n / 2 ||
                            c == 0 || c == n - 1);
                atCorner = (r == 0 && c == n - 1) || (r == n - 1 && c == n - 1);
            }
            if (onStroke && !atCorner)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── C ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, bottom row, left col
// Bold:     rows 0-1, rows (n-2)-(n-1), cols 0-1
std::vector<std::vector<char>> WordFont::drawC() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 || r == n - 1 || r == n - 2 || c == 0 || c == 1)
                : (r == 0 || r == n - 1 || c == 0);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── D ──────────────────────────────────────────────────────────────────────
// Non-bold: top/bottom rows, left/right cols; skip top-right & bottom-right corners
// Bold:     double-width; skip 2×2 top-right & bottom-right corners
std::vector<std::vector<char>> WordFont::drawD() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke, atCorner;
            if (isBold) {
                onStroke = (r == 0 || r == 1 || r == n - 1 || r == n - 2 ||
                            c == 0 || c == 1 || c == n - 1 || c == n - 2);
                atCorner = (r == 0 || r == 1 || r == n - 1 || r == n - 2) &&
                           (c == n - 1 || c == n - 2);
            } else {
                onStroke = (r == 0 || r == n - 1 || c == 0 || c == n - 1);
                atCorner = (r == 0 && c == n - 1) || (r == n - 1 && c == n - 1);
            }
            if (onStroke && !atCorner)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── E ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, bottom row, left col, middle row
// Bold:     double-width versions of the same
std::vector<std::vector<char>> WordFont::drawE() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 || c == 0 || c == 1 ||
                   r == n / 2 || r == n / 2 - 1 ||
                   r == n - 1 || r == n - 2)
                : (r == 0 || c == 0 || r == n / 2 || r == n - 1);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── F ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, middle row, left col
// Bold:     rows 0-1, rows (n/2-1)-(n/2), cols 0-1
std::vector<std::vector<char>> WordFont::drawF() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 || r == n / 2 || r == n / 2 - 1 || c == 0 || c == 1)
                : (r == 0 || r == n / 2 || c == 0);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── I ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, bottom row, center col
// Bold:     rows 0-1, rows (n-2)-(n-1), cols (n/2-1)-(n/2)
std::vector<std::vector<char>> WordFont::drawI() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 || c == n / 2 || c == n / 2 - 1 ||
                   r == n - 1 || r == n - 2)
                : (r == 0 || c == n / 2 || r == n - 1);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── J ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, center col, bottom-left hook (bottom row, cols ≤ n/2)
// Bold:     double-width versions; hook spans two rows
std::vector<std::vector<char>> WordFont::drawJ() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 ||
                   (r == n - 1 && c <= n / 2) ||
                   (r == n - 2 && c <= n / 2 - 1) ||
                   c == n / 2 || c == n / 2 - 1)
                : (r == 0 ||
                   (r == n - 1 && c <= n / 2) ||
                   c == n / 2);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── L ──────────────────────────────────────────────────────────────────────
// Non-bold: bottom row, left col
// Bold:     rows (n-2)-(n-1), cols 0-1
std::vector<std::vector<char>> WordFont::drawL() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == n - 1 || r == n - 2 || c == 0 || c == 1)
                : (r == n - 1 || c == 0);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── O ──────────────────────────────────────────────────────────────────────
// Non-bold: all four border edges, skip four corner pixels
// Bold:     double-width border edges, skip 2×2 corner blocks
std::vector<std::vector<char>> WordFont::drawO() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke, atCorner;
            if (isBold) {
                onStroke = (r == 0 || r == 1 || r == n - 1 || r == n - 2 ||
                            c == 0 || c == 1 || c == n - 1 || c == n - 2);
                atCorner = ((r == 0 || r == 1) &&
                            (c == 0 || c == 1 || c == n - 1 || c == n - 2)) ||
                           ((r == n - 1 || r == n - 2) &&
                            (c == 0 || c == 1 || c == n - 1 || c == n - 2));
            } else {
                onStroke = (r == 0 || r == n - 1 || c == 0 || c == n - 1);
                atCorner = (r == 0 && c == 0) || (r == 0 && c == n - 1) ||
                           (r == n - 1 && c == 0) || (r == n - 1 && c == n - 1);
            }
            if (onStroke && !atCorner)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── P ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, row 2, left col, plus pixel at (1, n-1)
// Bold:     rows 0-1 and 3-4, cols 0-1, plus pixels at rows 1-2 on right edge
std::vector<std::vector<char>> WordFont::drawP() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 || r == 3 || r == 4 ||
                   c == 0 || c == 1 ||
                   (r == 1 && c == n - 1) ||
                   (r == 2 && (c == n - 2 || c == n - 1)))
                : (r == 0 || r == 2 || c == 0 || (r == 1 && c == n - 1));
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── T ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, center col
// Bold:     rows 0-1, cols (n/2-1)-(n/2)
std::vector<std::vector<char>> WordFont::drawT() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 || c == n / 2 || c == n / 2 - 1)
                : (r == 0 || c == n / 2);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── U ──────────────────────────────────────────────────────────────────────
// Non-bold: bottom row, left col, right col
// Bold:     rows (n-2)-(n-1), cols 0-1, cols (n-2)-(n-1)
std::vector<std::vector<char>> WordFont::drawU() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (c == 0 || c == 1 || r == n - 1 || r == n - 2 ||
                   c == n - 1 || c == n - 2)
                : (c == 0 || r == n - 1 || c == n - 1);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── X ──────────────────────────────────────────────────────────────────────
// Non-bold: two diagonals: r==c  and  r+c==n-1
// Bold:     shifted diagonals: |r-c|==1  and  r+c==n-2 or n
std::vector<std::vector<char>> WordFont::drawX() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r - c == 1 || c - r == 1 ||
                   r + c == n - 2 || r + c == n)
                : (r == c || r + c == n - 1);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── Z ──────────────────────────────────────────────────────────────────────
// Non-bold: top row, bottom row, anti-diagonal r+c==n-1
// Bold:     rows 0-1, rows (n-2)-(n-1), anti-diagonals r+c==n-2 and r+c==n
std::vector<std::vector<char>> WordFont::drawZ() {
    std::vector<std::vector<char>> grid(fontSize, std::vector<char>(fontSize, ' '));
    const int n = fontSize;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            bool onStroke = isBold
                ? (r == 0 || r == 1 || r == n - 1 || r == n - 2 ||
                   r + c == n - 2 || r + c == n)
                : (r == 0 || r == n - 1 || r + c == n - 1);
            if (onStroke)
                grid[r][c] = pixelChar;
        }
    }
    return grid;
}

// ── Input / Output ──────────────────────────────────────────────────────────

void WordFont::readInput() {
    int boldChoice;
    std::cout << "Enter a word (supported letters: a b c d e f i j l o p t u x z): ";
    std::cin >> word;
    std::cout << "Enter the pixel character to use: ";
    std::cin >> pixelChar;
    std::cout << "Enter the font size (8-12): ";
    std::cin >> fontSize;
    std::cout << "Bold? (0=No, 1=Yes): ";
    std::cin >> boldChoice;
    isBold = (boldChoice != 0);
}

void WordFont::render() {
    // Each letter occupies fontSize columns; letters are separated by 2 spaces.
    const int canvasWidth = fontSize * static_cast<int>(word.length())
                            + 2 * (static_cast<int>(word.length()) - 1);

    std::vector<std::vector<char>> canvas(fontSize, std::vector<char>(canvasWidth, ' '));

    int colOffset = 0;
    for (char rawCh : word) {
        const char ch = static_cast<char>(std::toupper(static_cast<unsigned char>(rawCh)));
        switch (ch) {
        case 'A': blitChar(canvas, drawA(), colOffset); break;
        case 'B': blitChar(canvas, drawB(), colOffset); break;
        case 'C': blitChar(canvas, drawC(), colOffset); break;
        case 'D': blitChar(canvas, drawD(), colOffset); break;
        case 'E': blitChar(canvas, drawE(), colOffset); break;
        case 'F': blitChar(canvas, drawF(), colOffset); break;
        case 'I': blitChar(canvas, drawI(), colOffset); break;
        case 'J': blitChar(canvas, drawJ(), colOffset); break;
        case 'L': blitChar(canvas, drawL(), colOffset); break;
        case 'O': blitChar(canvas, drawO(), colOffset); break;
        case 'P': blitChar(canvas, drawP(), colOffset); break;
        case 'T': blitChar(canvas, drawT(), colOffset); break;
        case 'U': blitChar(canvas, drawU(), colOffset); break;
        case 'X': blitChar(canvas, drawX(), colOffset); break;
        case 'Z': blitChar(canvas, drawZ(), colOffset); break;
        default:  break; // unsupported character — leave blank
        }
        colOffset += fontSize + 2;
    }

    for (const auto& row : canvas) {
        for (char cell : row)
            std::cout << cell;
        std::cout << '\n';
    }
}

void WordFont::blitChar(std::vector<std::vector<char>>& canvas,
                        const std::vector<std::vector<char>>& letterGrid,
                        int colOffset) {
    for (int r = 0; r < static_cast<int>(canvas.size()); ++r) {
        for (int col = 0; col < fontSize; ++col)
            canvas[r][colOffset + col] = letterGrid[r][col];
    }
}
