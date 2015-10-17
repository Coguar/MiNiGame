// 15th.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "draw_mudle.h"
#include <SFML/Graphics.hpp>
#include <cstdio>
#include <iostream>
#include <sstream>
#include "state.h"




const float C = 64;
const int W = 4;
const int H = 4;


String TileMap1[H] = {
	"1234",
	"5678",
	"9ABC",
	"DEF0"
};



int main()
{
	int zeroI = 3;
	int zeroJ = 3;
	int lvl = 4;
	int tap = 0;
	int repos = 0;

	Page value = start;
	RenderWindow window(VideoMode(256, 256), "Game");
	window.clear(Color::White);

	Texture tileSet;
	tileSet.loadFromFile("16.png");

	Sprite tile(tileSet);

	String* TileMap = random_pos(TileMap1, zeroI, zeroJ, lvl, H, W);
	while (check_map(TileMap1) == true); {
		TileMap = random_pos(TileMap1, zeroI, zeroJ, lvl, H, W);
	}

	Texture menu_texture1, menu_texture3, picture_texture1, picture_texture2, picture_texture3, picture_texture4;
	menu_texture1.loadFromFile("111.png");
	menu_texture3.loadFromFile("333.png");
	picture_texture1.loadFromFile("p11.jpg");
	picture_texture2.loadFromFile("p21.jpg");
	picture_texture3.loadFromFile("p31.jpg");
	picture_texture4.loadFromFile("p41.jpg");
	Sprite menu1(menu_texture1), menu3(menu_texture3), win_menu1(menu_texture1), win_menu3(menu_texture3), pic1(picture_texture1), pic2(picture_texture2), pic3(picture_texture3), pic4(picture_texture4);
	menu1.setPosition(50, 30);
	menu3.setPosition(50, 150);
	win_menu1.setPosition(50, 30);
	win_menu3.setPosition(50, 150);
	pic1.setPosition(43, 43);
	pic2.setPosition(149, 43);
	pic3.setPosition(43, 149);
	pic4.setPosition(149, 149);
	bool win = 0;

	/////меню
	while (window.isOpen()) {
		switch (value) {
		case refrash:
			TileMap = random_pos(TileMap1, zeroI, zeroJ, lvl, H, W);
			while (TileMap == TileMap1) {
				TileMap = random_pos(TileMap1, zeroI, zeroJ, lvl, H, W);

				value = start;
				break;
		case start:
			main_menu(window, menu1, menu3, value);
			break;
		case choose:
			change_picture(window, value, pic1, pic2, pic3, pic4, tileSet);
			tap = 0;
			break;
		case game:
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
					if (event.key.code == Mouse::Left) {
						process(window, TileMap, zeroI, zeroJ);
						tap++;
						check_win(TileMap1, value);
					}
			}

			drawing_game(window, TileMap, tile, H, W);
			window.display();
			break;
		case win_text:
			drawing_game(window, TileMap, tile, H, W);
			showScore(window, tap);
			while (window.pollEvent(event)) {
				if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					value = win_page;
				}
			}
			break;
		case win_page:
			win_menu(window, value, win_menu1, win_menu3, tap);
			break;
			}

		}
	}
}