#pragma once
#include <math.h>
#include <assert.h>
//�ж�a�ǲ���0ֵ
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
	//����
	float Length() const 
	{
		return sqrt(x * x + y * y);
	}
	//�����ļӷ�
	CVector2 operator + (const CVector2& that)const
	{
		return CVector2(x + that.x, y + that.y);
	}
	//�����ļ���
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
	//����������
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
	//����������
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
	//��λ����
	CVector2 Normalize()const
	{
		float len = Length();
		assert(!ZERO(len));
		return CVector2(x / len, y / len);
	}
	//���
	float Dot(const CVector2& that)const
	{
		return x * that.x + y * that.y;
	}
	//��������that�����ļн�(�ǻ���ֵ)
	float Angle(const CVector2& that)
	{
		float dc = x * that.x + y * that.y;
		float l = Length() * that.Length();
		return acos(dc / l);
	}
	//ͶӰ
	CVector2 Projection(const CVector2& that)
	{
		float AdotB = x*that.x+y*that.y;
		float Bdepingfang = that.x*that.x+that.y*that.y;

		return CVector2(
			that.x * (AdotB / Bdepingfang),
			that.y * (AdotB / Bdepingfang));
	}
};


