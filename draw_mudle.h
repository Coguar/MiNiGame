#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <ctime>
#include "state.h"

using namespace sf;

void drawing_game(RenderWindow & window, String* TileMap, Sprite & tile, const int & H, const int & W);

void process(RenderWindow & window, String* TileMap, int & zeroI, int & zeroJ);

void check_win(String* map, Page & value);

bool check_map(String* map);

String* random_pos(String* TileMap, int & I, int & J, const int lvl, const int H, const int W);

void main_menu(RenderWindow & window, Sprite & menu1, Sprite & menu3, Page & value);

void change_picture(RenderWindow & window, Page & value, Sprite & pic1, Sprite & pic2, Sprite & pic3, Sprite & pic4, Texture & tileSet);

void win_menu(RenderWindow & window, Page & value, Sprite & win_menu1, Sprite & win_menu3, int & tap);

void showScore(RenderWindow & window, int & tap);

