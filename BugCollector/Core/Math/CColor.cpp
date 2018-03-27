#include "CColor.h"



CColor::CColor()
{

}

CColor::CColor(const f32 InRed, const f32 InGreen, const f32 InBlue, const f32 InAlpha)
{
	Set(InRed, InGreen, InBlue, InAlpha);
}

void CColor::Set(const f32 InRed, const f32 InGreen, const f32 InBlue, const f32 InAlpha)
{
	SetRed(InRed);
	SetGreen(InGreen);
	SetBlue(InBlue);
	SetAlpha(InAlpha);
}

void CColor::SetRed(const f32 InValue)
{
	Data[0] = InValue;
}

void CColor::SetGreen(const f32 InValue)
{
	Data[1] = InValue;
}

void CColor::SetBlue(const f32 InValue)
{
	Data[2] = InValue;
}

void CColor::SetAlpha(const f32 InValue)
{
	Data[3] = InValue;
}

f32 CColor::GetR() const
{
	return Data[0];
}

f32 CColor::GetG() const
{
	return Data[1];
}

f32 CColor::GetB() const
{
	return Data[2];
}

f32 CColor::GetA() const
{
	return Data[3];
}
