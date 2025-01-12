#pragma once

class Entity
{
protected:
	float posX;
	float posY;

public:
	Entity(float posX, float posY);
	virtual ~Entity() = default;

	virtual void update() = 0;

	float getPosX() const { return posX; }
	float getPosY() const { return posY; }
};