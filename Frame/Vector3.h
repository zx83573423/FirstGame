#pragma once
#include "vector2.h"

class CVector3
{
public:	
	float x;
	float y;
	float z;

	CVector3(float xx = 0.0f,float yy = 0.0f,float zz = 0.0f)
	{
		x = xx;
		y = yy;
		z = zz;
	}
	//长度
	float Length() const 
	{
		return sqrt(x * x + y * y + z * z);
	}
	//向量的加法
	CVector3 operator + (const CVector3& that)const
	{
		return CVector3(x + that.x, y + that.y, z + that.z);
	}
	//向量的减法
	CVector3 operator - (const CVector3& that)const
	{
		return CVector3(x - that.x, y - that.y, z - that.z);
	}
	CVector3& operator += (const CVector3& that)
	{
		x = x + that.x;
		y = y + that.y;
		z = z + that.z;
		return *this;
	}
	CVector3& operator -= (const CVector3& that)
	{
		x = x - that.x;
		y = y - that.y;
		z = z - that.z;
		return *this;
	}
	//向量的数乘
	CVector3 operator * (float a)const
	{
		return CVector3(x * a, y * a, z * a);
	}
	CVector3& operator *= (float a)
	{
		x *= a;
		y *= a;
		z *= a;
		return *this;
	}
	//向量的数除
	CVector3 operator / (float a)const
	{
		assert(!ZERO(a));
		return CVector3(x / a, y / a, z / a);
	}
	CVector3& operator /= (float a)
	{
		x /= a;
		y /= a;
		z /= a;
		return *this;
	}
	//单位向量
	CVector3 Normalize()const
	{
		float len = Length();
		assert(!ZERO(len));
		return CVector3(x / len, y / len, z / len);
	}
	//点乘
	float Dot(const CVector3& that)const
	{
		return x * that.x + y * that.y + z * that.z;
	}
	//求本向量和that向量的夹角(是弧度值)
	float Angle(const CVector3& that)
	{
		float dc = x * that.x + y * that.y + z * that.z;
		float l = Length() * that.Length();
		return acos(dc / l);
	}
	//投影
	CVector3 Projection(const CVector3& that)
	{
		float AdotB = x*that.x+y*that.y+z*that.z;
		float Bdepingfang = that.x*that.x+that.y*that.y+that.z*that.z;

		return that * (AdotB / Bdepingfang);
	}

	//叉乘
	CVector3 Cross(const CVector3& that)
	{
		return CVector3(y*that.z-z*that.y, z*that.x-x*that.z,  x*that.y-y*that.x);
	}
};


