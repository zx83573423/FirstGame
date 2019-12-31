#pragma once
#include <math.h>
#include <assert.h>
//判断a是不是0值
#define ZERO(a)  ((a)>=-0.001&&(a)<=0.001)
class CVector2
{
public:	
	float x;
	float y;

	static CVector2 up;
	static CVector2 down;
	static CVector2 left;
	static CVector2 right;
	static CVector2 zero;

	CVector2(float xx = 0.0f,float yy = 0.0f)
	{
		x = xx;
		y = yy;
	}
	void Set(float xx,float yy)
	{
		x = xx;
		y = yy;
	}
	//长度
	float Length() const 
	{
		return sqrt(x * x + y * y);
	}
	//向量的加法
	CVector2 operator + (const CVector2& that)const
	{
		return CVector2(x + that.x, y + that.y);
	}
	//向量的减法
	CVector2 operator - (const CVector2& that)const
	{
		return CVector2(x - that.x, y - that.y);
	}
	CVector2& operator += (const CVector2& that)
	{
		x = x + that.x;
		y = y + that.y;
		return *this;
	}
	CVector2& operator -= (const CVector2& that)
	{
		x = x - that.x;
		y = y - that.y;
		return *this;
	}
	//向量的数乘
	CVector2 operator * (float a)const
	{
		return CVector2(x * a, y * a);
	}
	CVector2& operator *= (float a)
	{
		x *= a;
		y *= a;
		return *this;
	}
	//向量的数除
	CVector2 operator / (float a)const
	{
		assert(!ZERO(a));
		return CVector2(x / a, y / a);
	}
	CVector2& operator /= (float a)
	{
		x /= a;
		y /= a;
		return *this;
	}
	//单位向量
	CVector2 Normalize()const
	{
		float len = Length();
		assert(!ZERO(len));
		return CVector2(x / len, y / len);
	}
	//点乘
	float Dot(const CVector2& that)const
	{
		return x * that.x + y * that.y;
	}
	//求本向量和that向量的夹角(是弧度值)
	float Angle(const CVector2& that)
	{
		float dc = x * that.x + y * that.y;
		float l = Length() * that.Length();
		return acos(dc / l);
	}
	//投影
	CVector2 Projection(const CVector2& that)
	{
		float AdotB = x*that.x+y*that.y;
		float Bdepingfang = that.x*that.x+that.y*that.y;

		return CVector2(
			that.x * (AdotB / Bdepingfang),
			that.y * (AdotB / Bdepingfang));
	}
};


