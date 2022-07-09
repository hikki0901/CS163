#include "UI.h"

void gotoxy(short x, short y) {
  HANDLE hConsoleOutput;
  COORD Cursor_an_Pos = {x, y};
  hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void setColor(short x) {
  HANDLE hConsoleColor;
  hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsoleColor, x);
}
