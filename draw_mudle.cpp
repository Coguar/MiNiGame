#pragma once

#include "stdafx.h"
#include "draw_mudle.h"


void drawing_game(RenderWindow & window, String* TileMap, Sprite & tile, const int & H, const int & W)
{
	window.clear();
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{

			if (TileMap[i][j] == '1')
			{
				tile.setTextureRect(IntRect(0, 0, 64, 64));
			}
			if (TileMap[i][j] == '2')
			{
				tile.setTextureRect(IntRect(64, 0, 64, 64));
			}
			if (TileMap[i][j] == '3')
			{
				tile.setTextureRect(IntRect(128, 0, 64, 64));
			}
			if (TileMap[i][j] == '4')
			{
				tile.setTextureRect(IntRect(192, 0, 64, 64));
			}
			if (TileMap[i][j] == '5')
			{
				tile.setTextureRect(IntRect(0, 64, 64, 64));
			}
			if (TileMap[i][j] == '6')
			{
				tile.setTextureRect(IntRect(64, 64, 64, 64));
			}
			if (TileMap[i][j] == '7')
			{
				tile.setTextureRect(IntRect(128, 64, 64, 64));
			}
			if (TileMap[i][j] == '8')
			{
				tile.setTextureRect(IntRect(192, 64, 64, 64));
			}
			if (TileMap[i][j] == '9')
			{
				tile.setTextureRect(IntRect(0, 128, 64, 64));
			}
			if (TileMap[i][j] == 'A')
			{
				tile.setTextureRect(IntRect(64, 128, 64, 64));
			}
			if (TileMap[i][j] == 'B')
			{
				tile.setTextureRect(IntRect(128, 128, 64, 64));
			}
			if (TileMap[i][j] == 'C')
			{
				tile.setTextureRect(IntRect(192, 128, 64, 64));
			}
			if (TileMap[i][j] == 'D')
			{
				tile.setTextureRect(IntRect(0, 192, 64, 64));
			}
			if (TileMap[i][j] == 'E')
			{
				tile.setTextureRect(IntRect(64, 192, 64, 64));
			}
			if (TileMap[i][j] == 'F')
			{
				tile.setTextureRect(IntRect(128, 192, 64, 64));
			}
			if (TileMap[i][j] == '0')
			{
				tile.setTextureRect(IntRect(300, 1, 64, 64));
			}

			tile.setPosition(j * 64, i * 64);
			window.draw(tile);
		}
};

void process(RenderWindow & window, String* TileMap, int & zeroI, int & zeroJ)
{
	Vector2i mousePos = Mouse::getPosition(window);

	int x(mousePos.x), y(mousePos.y);

	int pY(y / 64);
	int pX(x / 64);

	if (TileMap[pY][pX] != '0')
	{
		if ((abs(pX - zeroJ) + abs(pY - zeroI)) < 2)
		{
			char reserv = TileMap[pY][pX];
			TileMap[pY][pX] = TileMap[zeroI][zeroJ];
			TileMap[zeroI][zeroJ] = reserv;
			zeroI = pY;
			zeroJ = pX;
		}
	}
};

void check_win(String* map, Page & value)
{
	bool win = 1;
	String true_map[4] =
	{
		"1234",
		"5678",
		"9ABC",
		"DEF0"
	};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != true_map[i][j])
			{
				win = 0;
			}
		}
	if (win == 1) value = win_text;
}

bool check_map(String* map)
{
	bool win = 1;
	String true_map[4] =
	{
		"1234",
		"5678",
		"9ABC",
		"DEF0"
	};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != true_map[i][j])
			{
				win = 0;
			}
		}
	return win;
}

String* random_pos(String* TileMap, int & I, int & J, const int lvl, const int H, const int W) {
	int val = lvl;
	String* startMap = TileMap;
	while (val > 0)
	{
		int number = 0;
		val -= 1;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if ((abs(j - J) + abs(i - I)) < 2)  number++;
		int random = 0;
		srand(time(NULL) * (1 + rand() % number));
		random = 1 + rand() % number;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if ((abs(j - J) + abs(i - I)) < 2)
				{
					if (random == 1)
					{
						char reserv = TileMap[j][i];
						TileMap[j][i] = TileMap[I][J];
						TileMap[I][J] = reserv;
						I = j;
						J = i;
					}
					else
					{
						random--;
					}
				}
			}
	}
	return TileMap;
};

void main_menu(RenderWindow & window, Sprite & menu1, Sprite & menu3, Page & value)
{
	menu1.setColor(Color::White);
	menu3.setColor(Color::White);
	int MenuNum = 0;
	window.clear(Color(0, 0, 0));

	if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); MenuNum = 1; }
	if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); MenuNum = 2; }

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (MenuNum == 1) value = choose;
		if (MenuNum == 2) { window.close(); }

	}


	window.draw(menu1);
	window.draw(menu3);

	window.display();
};

void change_picture(RenderWindow & window, Page & value, Sprite & pic1, Sprite & pic2, Sprite & pic3, Sprite & pic4, Texture & tileSet)
{
	int pic_num = 0;
	window.clear(Color(0, 0, 0));

	if (IntRect(43, 43, 64, 64).contains(Mouse::getPosition(window))) { pic_num = 1; }
	if (IntRect(149, 43, 64, 64).contains(Mouse::getPosition(window))) { pic_num = 2; }
	if (IntRect(43, 149, 64, 64).contains(Mouse::getPosition(window))) { pic_num = 3; }
	if (IntRect(149, 149, 64, 64).contains(Mouse::getPosition(window))) { pic_num = 4; }

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (pic_num == 1)
		{
			tileSet.loadFromFile("p1.jpg");
			value = game;
		}
		if (pic_num == 2)
		{
			tileSet.loadFromFile("p2.jpg");
			value = game;
		}
		if (pic_num == 3)
		{
			tileSet.loadFromFile("p3.jpg");
			value = game;
		}
		if (pic_num == 4)
		{
			tileSet.loadFromFile("p4.jpg");
			value = game;
		}

	}
	window.draw(pic1);
	window.draw(pic2);
	window.draw(pic3);
	window.draw(pic4);

	window.display();
};

void win_menu(RenderWindow & window, Page & value, Sprite & win_menu1, Sprite & win_menu3, int & tap)
{
	window.clear();
	win_menu1.setColor(Color::White);
	win_menu3.setColor(Color::White);

	int MenuNum = 0;
	window.clear(Color(0, 0, 0));

	if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { win_menu1.setColor(Color::Yellow); MenuNum = 1; }
	if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { win_menu3.setColor(Color::Yellow); MenuNum = 2; }

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (MenuNum == 1) value = refrash;
		if (MenuNum == 2) { window.close(); }

	}
	Font font;//шрифт 
	font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пиксел€х);//сам объект текст (не строка)
	text.setColor(Color::Yellow);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	std::ostringstream taps;    // объ€вили переменную
	taps << tap;		//занесли в нее число очков, то есть формируем строку
	text.setString("—делано ходов:" + taps.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
	text.setPosition(50, 90);//задаем позицию текста, отступа€ от центра камеры
	window.draw(text);

	window.draw(win_menu1);
	window.draw(win_menu3);

	window.display();
}

void showScore(RenderWindow & window, int & tap)
{
	Font font;//шрифт 
	font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20), text1("Press Up to Continue", font, 17);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пиксел€х);//сам объект текст (не строка)
	text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text1.setColor(Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

	std::ostringstream taps;    // объ€вили переменную
	taps << tap;		//занесли в нее число очков, то есть формируем строку
	text.setString("—делано ходов:" + taps.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
	text.setPosition(50, 90);
	text1.setPosition(50, 120);//задаем позицию текста, отступа€ от центра камеры
	window.draw(text);
	window.draw(text1);
	window.display();
}