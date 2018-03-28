#pragma once

template <typename T, u32 NUM>
struct TVector
{
	T Data[NUM];
};

template <typename T, u32 NUM>
struct TVector2 : public TVector<T, NUM>
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

template <typename T, u32 NUM>
struct TVector3 : public TVector2<T, NUM>
{
	TVector3()
	{}

	TVector3(T InX, T InY, T InZ)
	{
		SetX(InX);
		SetY(InY);
		SetZ(InZ);
	}

	void SetZ(const T InValue)
	{
		this->Data[2] = InValue;
	}

	T GetZ() const
	{
		return this->Data[2];
	}
};

typedef TVector2<f32, 2> Vector2f;
typedef TVector2<u32, 2> Vector2i;
typedef TVector3<f32, 3> Vector3f;
typedef TVector3<u32, 3> Vector3i;
