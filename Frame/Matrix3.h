#pragma once
#include "Vector2.h"
#define _M11 0
#define _M12 1
#define _M13 2
#define _M21 3
#define _M22 4
#define _M23 5
#define _M31 6
#define _M32 7
#define _M33 8


class CMatrix3
{
	friend void M3_MUL_M3(CMatrix3* a, CMatrix3* b, CMatrix3* m3);
	friend CVector2 operator * (CVector2 v, CMatrix3 m);
	float m[9];
public:
	CMatrix3()
	{
		Identity();
	}
	//单位矩阵
	void Identity()
	{
		// 1 0 0
		// 0 1 0 
		// 0 0 1
		m[_M11] = 1.0f; m[_M12] = 0.0f; m[_M13] = 0.0f; 
		m[_M21] = 0.0f; m[_M22] = 1.0f; m[_M23] = 0.0f; 
		m[_M31] = 0.0f; m[_M32] = 0.0f; m[_M33] = 1.0f; 
	}
	//平移矩阵
	void Translate(float x, float y)
	{
		// 1 0 0
		// 0 1 0 
		// x y 1
		m[_M11] = 1.0f; m[_M12] = 0.0f; m[_M13] = 0.0f; 
		m[_M21] = 0.0f; m[_M22] = 1.0f; m[_M23] = 0.0f; 
		m[_M31] = x   ; m[_M32] = y   ; m[_M33] = 1.0f; 
	}
	//缩放矩阵
	void Scale(float x, float y)
	{
		// x 0 0
		// 0 y 0 
		// 0 0 1
		m[_M11] = x   ; m[_M12] = 0.0f; m[_M13] = 0.0f; 
		m[_M21] = 0.0f; m[_M22] = y   ; m[_M23] = 0.0f; 
		m[_M31] = 0.0f; m[_M32] = 0.0f; m[_M33] = 1.0f; 
	}
	//旋转矩阵
	void Rotate(float a)
	{
		// cos(a)  sin(a) 0
		// -sin(a) cos(a) 0 
		// 0       0      1
		float ca = cos(a);
		float sa = sin(a);
		m[_M11] = ca  ; m[_M12] = sa  ; m[_M13] = 0.0f; 
		m[_M21] = -sa ; m[_M22] = ca  ; m[_M23] = 0.0f; 
		m[_M31] = 0.0f; m[_M32] = 0.0f; m[_M33] = 1.0f; 
	}

	//这种写法效率不高，因为返回值是Matrix3，拷贝的数据太多了
	//数学：   M1 * M2 = M3
	//调用     M3 = M1 * M2
	//Matrix3 operator * (const Matrix3& that)
	//{
	//	//			M1			*			M2
	//	//m[_M11] m[_M12] m[_M13]	that.m[_M11] that.m[_M12] that.m[_M13]
	//	//m[_M21] m[_M22] m[_M23]	that.m[_M21] that.m[_M22] that.m[_M23]
	//	//m[_M31] m[_M32] m[_M33]	that.m[_M31] that.m[_M32] that.m[_M33]
	//	Matrix3 m3;
	//	m3.m[_M11] = m[_M11]*that.m[_M11] + m[_M12]*that.m[_M21] + m[_M13]*that.m[_M31];
	//	m3.m[_M12] = m[_M11]*that.m[_M12] + m[_M12]*that.m[_M22] + m[_M13]*that.m[_M32];
	//	m3.m[_M13] = m[_M11]*that.m[_M13] + m[_M12]*that.m[_M23] + m[_M13]*that.m[_M33];

	//	m3.m[_M21] = m[_M21]*that.m[_M11] + m[_M22]*that.m[_M21] + m[_M23]*that.m[_M31];
	//	m3.m[_M22] = m[_M21]*that.m[_M12] + m[_M22]*that.m[_M22] + m[_M23]*that.m[_M32];
	//	m3.m[_M23] = m[_M21]*that.m[_M13] + m[_M22]*that.m[_M23] + m[_M23]*that.m[_M33];

	//	m3.m[_M31] = m[_M31]*that.m[_M11] + m[_M32]*that.m[_M21] + m[_M33]*that.m[_M31];
	//	m3.m[_M32] = m[_M31]*that.m[_M12] + m[_M32]*that.m[_M22] + m[_M33]*that.m[_M32];
	//	m3.m[_M33] = m[_M31]*that.m[_M13] + m[_M32]*that.m[_M23] + m[_M33]*that.m[_M33];
	//	return m3;
	//}
};

//向量 * 矩阵 = 向量

//全局的运算符重载
inline CVector2 operator * (CVector2 v, CMatrix3 m)
{
	//					 m[_M11]  m[_M12]  m[_M13]  
	//  [v.x  v.y  1] *	 m[_M21]  m[_M22]  m[_M23] = [v.x*m[_M11]+v.y*m[_M21]+m[_M31]   v.x*m[_M12]+v.y*m[_M22]+m[_M32]    v.x*m[_M13]+v.y*m[_M23]+m[_M33] ]    
	//					 m[_M31]  m[_M32]  m[_M33]  

	float a = v.x*m.m[_M11]+v.y*m.m[_M21]+m.m[_M31];
	float b = v.x*m.m[_M12]+v.y*m.m[_M22]+m.m[_M32];
	float c = v.x*m.m[_M13]+v.y*m.m[_M23]+m.m[_M33];
	return CVector2(a/c, b/c);
}
//矩阵乘以矩阵
inline void M3_MUL_M3(CMatrix3* a, CMatrix3* b, CMatrix3* m3)
{
	m3->m[_M11] = a->m[_M11]*b->m[_M11] + a->m[_M12]*b->m[_M21] + a->m[_M13]*b->m[_M31];
	m3->m[_M12] = a->m[_M11]*b->m[_M12] + a->m[_M12]*b->m[_M22] + a->m[_M13]*b->m[_M32];
	m3->m[_M13] = a->m[_M11]*b->m[_M13] + a->m[_M12]*b->m[_M23] + a->m[_M13]*b->m[_M33];
																			 
	m3->m[_M21] = a->m[_M21]*b->m[_M11] + a->m[_M22]*b->m[_M21] + a->m[_M23]*b->m[_M31];
	m3->m[_M22] = a->m[_M21]*b->m[_M12] + a->m[_M22]*b->m[_M22] + a->m[_M23]*b->m[_M32];
	m3->m[_M23] = a->m[_M21]*b->m[_M13] + a->m[_M22]*b->m[_M23] + a->m[_M23]*b->m[_M33];
																			 
	m3->m[_M31] = a->m[_M31]*b->m[_M11] + a->m[_M32]*b->m[_M21] + a->m[_M33]*b->m[_M31];
	m3->m[_M32] = a->m[_M31]*b->m[_M12] + a->m[_M32]*b->m[_M22] + a->m[_M33]*b->m[_M32];
	m3->m[_M33] = a->m[_M31]*b->m[_M13] + a->m[_M32]*b->m[_M23] + a->m[_M33]*b->m[_M33];
}
