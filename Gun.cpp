#include <iostream>

#include "Gun.h"

Gun::Gun(float posX, float posY, float width, float height, int bulletCount) : Entity(posX, posY)
{
	this->width = width;
	this->height = height;
	this->bulletCount = bulletCount;

	gun = sf::RectangleShape({ width, height });
	gun.setPosition({ posX, posY });
	gun.setFillColor(sf::Color::Green);

	bulletMax = 10;

	reloadCooldown = sf::seconds(1.5f);
	reloadClock.stop();

	shootCooldown = sf::seconds(0.5f);
}

Gun::~Gun()
{

}

void Gun::update()
{
	// Reload
	if (reloadClock.isRunning() && reloadClock.getElapsedTime() >= reloadCooldown)
	{
		bulletCount = bulletMax;
		reloadClock.reset();

		std::cout << "Reloaded!" << std::endl;
	}
}

void Gun::shoot(std::vector<Bullet>& bullets)
{
	if (shootClock.getElapsedTime() >= shootCooldown && !reloadClock.isRunning()) {
		if (bulletCount > 0) {
			std::cout << "Fire!" << std::endl;

			bullets.emplace_back(posX + width + 10, posY + height / 2, 5, 10);
			bulletCount--;
			shootClock.restart();
		}
		else {
			std::cout << "No bullets left!" << std::endl;
		}
	}
	else {
		std::cout << "Cooldown active, can't shoot yet!" << std::endl;
	}
}

void Gun::reload()
{
	if (bulletCount == bulletMax)
	{
		std::cout << "Gun is already full!" << std::endl;
		return;
	}

	if (!reloadClock.isRunning())
	{
		std::cout << "Start Reloading..." << std::endl;
		reloadClock.start();
	}
	else {
		std::cout << "Actualy Reloading..." << std::endl;
	}
}