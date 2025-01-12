#include <SFML/Graphics.hpp>

#include <iostream>
#include "Gun.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 600, 400}), "TP1");
	window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("Roboto.ttf"))
    {
		std::cout << "Error loading font" << std::endl;
    }

    sf::Text remainingBullets(font);
    remainingBullets.setCharacterSize(16);
    remainingBullets.setPosition({ 10, 10 });
    remainingBullets.setFillColor(sf::Color::White);

	Gun* gun = new Gun(100, 100, 100, 20, 6);
    std::vector<Bullet> bullets;
	bullets.clear();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            {
                window.close();
            }

            // Character
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
            {
                gun->reload();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                gun->shoot(bullets);
            }
        }

        // Update
		gun->update();
        for (auto it = bullets.begin(); it != bullets.end(); ) {
            if (it->getPosX() > window.getSize().x || it->getPosX() < 0 ||
                it->getPosY() > window.getSize().y || it->getPosY() < 0)
            {
                it = bullets.erase(it);
            }
            else
            {
                ++it;
            }
        }

        for (Bullet& bullet : bullets) {
            bullet.update();
        }
        remainingBullets.setString(std::to_string(gun->getBulletCount()));

        // Draw
        window.clear();

        // UI
        window.draw(remainingBullets);

		// Entities
		window.draw(gun->getGun());
		for (Bullet& bullet : bullets) {
			window.draw(bullet.getBullet());
		}

        window.display();
    }
}