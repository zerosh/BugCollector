#pragma once
#include "../Types.h"


class CColor
{
private:
	f32 Data[4];
public:
	CColor();

	CColor(const f32 InRed, const f32 InGreen, const f32 InBlue, const f32 InAlpha);

	void Set(const f32 InRed, const f32 InGreen, const f32 InBlue, const f32 InAlpha);
	void SetRed(const f32 InValue);
	void SetGreen(const f32 InValue);
	void SetBlue(const f32 InValue);
	void SetAlpha(const f32 InValue);

	f32 GetR() const;
	f32 GetG() const;
	f32 GetB() const;
	f32 GetA() const;
};
