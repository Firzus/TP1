#include "Bullet.h"

Bullet::Bullet(float posX, float posY, float radius, float speed) : Entity(posX, posY)
{
	this->radius = radius;
	this->speed = speed;

	bullet = sf::CircleShape(radius);
	bullet.setOrigin({ radius, radius });
	bullet.setPosition({ posX, posY });
	bullet.setFillColor(sf::Color::Red);
}

Bullet::~Bullet()
{

}

void Bullet::update()
{
	posX += speed;

	// Update bullet position
	bullet.setPosition({ posX, posY });
}