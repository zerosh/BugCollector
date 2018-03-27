#pragma once

template <typename T, u32 NUM>
struct TVector
{
	T Data[NUM];
};

template <typename T>
struct TVector2 : public TVector<T, 2>
{
	TVector2()
	{}

	TVector2(T InX, T InY)
	{
		SetX(InX);
		SetY(InY);
	}

	void SetX(const T InValue)
	{
		this->Data[0] = InValue;
	}

	void SetY(const T InValue)
	{
		this->Data[1] = InValue;
	}

	T GetX() const
	{
		return this->Data[0];
	}

	T GetY() const
	{
		return this->Data[1];
	}
};

typedef TVector2<f32> Vector2f;
typedef TVector2<u32> Vector2i;
