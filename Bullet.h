#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

class Bullet : public Entity
{
private:
	sf::CircleShape bullet;
	float radius;
	float speed;

	// DATA ONLY
	int windowWidth = 600;
	int windowHeight = 400;

public:
	Bullet(float posX, float posY, float radius, float speed);
	~Bullet();

	void update() override;

	sf::CircleShape getBullet() { return bullet; };

	// Getters
	float getRadius() const { return radius; }
	float getSpeed() const { return speed; }
};