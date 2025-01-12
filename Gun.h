#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Bullet.h"

class Gun : public Entity
{
private:
	sf::RectangleShape gun;
	int width;
	int height;
	int bulletCount;
	int bulletMax;
	sf::Clock reloadClock;
	sf::Time reloadCooldown;
	sf::Clock shootClock;
	sf::Time shootCooldown;

public:
	Gun(float posX, float posY, float width, float height, int bulletCount);
	~Gun();

	void update() override;
	void shoot(std::vector<Bullet>& bullets);
	void reload();

	// Getters
	sf::RectangleShape getGun() { return gun; }
	int getBulletCount() const { return bulletCount; }
	int getBulletMax() const { return bulletMax; }
	sf::Clock getReloadClock() const { return reloadClock; }
	sf::Clock getShootClock() const { return shootClock; }
};

