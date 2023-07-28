#pragma once

#include <D:\Files_for_C++\SFML-2.5.1\include\SFML\Graphics.hpp>

using namespace sf;

class Bob
{
public:
	Bob();

	Sprite getSprite();
	
	void moveLeft();

	void moveRight();
	 
	void stopLeft();

	void stotRight();

	void update(float elapsedTime);

private:
	Vector2f m_Position;

	Sprite m_Sprite;

	Texture m_Texture;

	bool m_LeftPressed;
	bool m_RightPressed;

	float m_Speed;
};


