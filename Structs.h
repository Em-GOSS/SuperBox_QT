#pragma once
struct Vector2
{
public:
	int x;
	int y;
	Vector2()
	{
		this->x = -1;
		this->y = -1;
	}
	Vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Vector2 operator + (const Vector2& other)
	{
		return Vector2(this->x + other.x, this->y + other.y);
	}
	
};

	


