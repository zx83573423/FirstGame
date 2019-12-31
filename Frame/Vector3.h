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
	//����
	float Length() const 
	{
		return sqrt(x * x + y * y + z * z);
	}
	//�����ļӷ�
	CVector3 operator + (const CVector3& that)const
	{
		return CVector3(x + that.x, y + that.y, z + that.z);
	}
	//�����ļ���
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
	//����������
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
	//����������
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
	//��λ����
	CVector3 Normalize()const
	{
		float len = Length();
		assert(!ZERO(len));
		return CVector3(x / len, y / len, z / len);
	}
	//���
	float Dot(const CVector3& that)const
	{
		return x * that.x + y * that.y + z * that.z;
	}
	//��������that�����ļн�(�ǻ���ֵ)
	float Angle(const CVector3& that)
	{
		float dc = x * that.x + y * that.y + z * that.z;
		float l = Length() * that.Length();
		return acos(dc / l);
	}
	//ͶӰ
	CVector3 Projection(const CVector3& that)
	{
		float AdotB = x*that.x+y*that.y+z*that.z;
		float Bdepingfang = that.x*that.x+that.y*that.y+that.z*that.z;

		return that * (AdotB / Bdepingfang);
	}

	//���
	CVector3 Cross(const CVector3& that)
	{
		return CVector3(y*that.z-z*that.y, z*that.x-x*that.z,  x*that.y-y*that.x);
	}
};


