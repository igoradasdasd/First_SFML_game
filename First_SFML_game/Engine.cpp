#include "Engine.h"

Engine::Engine()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Simple Game Engine", Style::Fullscreen);

	m_BackgroundTexture.loadFromFile("background.jpg");

	m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::start()
{
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}

}void Engine::input()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_Bob.moveLeft();
	}
	else
	{
		m_Bob.stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_Bob.moveRight();
	}
	else
	{
		m_Bob.stotRight();
	}
}

void Engine::update(float dtAsSeconds)
{
	m_Bob.update(dtAsSeconds);
}

void Engine::draw()
{
	m_Window.clear(Color::White);

	m_Window.draw(m_BackgroundSprite);

	m_Window.draw(m_Bob.getSprite());

	m_Window.display();
		
}