#pragma once
#include "Vector3.h"
#define _M11 0
#define _M12 1
#define _M13 2
#define _M21 3
#define _M22 4
#define _M23 5
#define _M31 6
#define _M32 7
#define _M33 8

#define _M14 9
#define _M24 10
#define _M34 11
#define _M41 12
#define _M42 13
#define _M43 14
#define _M44 15

class CMatrix4
{
	friend void M4_MUL_M4(CMatrix4* a, CMatrix4* b, CMatrix4* m3);
	friend CVector3 operator * (CVector3 v, CMatrix4 m);
	float m[16];
public:
	CMatrix4()
	{
		Identity();
	}
	//µ¥Î»¾ØÕó
	void Identity()
	{
		// 1 0 0 0
		// 0 1 0 0
		// 0 0 1 0
		// 0 0 0 1
		m[_M11] = 1.0f; m[_M12] = 0.0f; m[_M13] = 0.0f;  m[_M14] = 0.0f; 
		m[_M21] = 0.0f; m[_M22] = 1.0f; m[_M23] = 0.0f;  m[_M24] = 0.0f; 
		m[_M31] = 0.0f; m[_M32] = 0.0f; m[_M33] = 1.0f;  m[_M34] = 0.0f; 
		m[_M41] = 0.0f; m[_M42] = 0.0f; m[_M43] = 0.0f;  m[_M44] = 1.0f; 
	}
	//Æ½ÒÆ¾ØÕó
	void Translate(float x, float y,float z)
	{
		// 1 0 0 0
		// 0 1 0 0
		// 0 0 1 0 
		// x y z 1

		m[_M11] = 1.0f; m[_M12] = 0.0f; m[_M13] = 0.0f; m[_M14] = 0.0f;
		m[_M21] = 0.0f; m[_M22] = 1.0f; m[_M23] = 0.0f; m[_M24] = 0.0f;
		m[_M31] = 0.0f; m[_M32] = 0.0f; m[_M33] = 1.0f; m[_M34] = 0.0f;
		m[_M41] = x   ; m[_M42] = y   ; m[_M43] = z   ; m[_M44] = 1.0f;
	}
	//Ëõ·Å¾ØÕó
	void Scale(float x, float y,float z)
	{
		// x 0 0 0
		// 0 y 0 0 
		// 0 0 z 0 
		// 0 0 0 1
		m[_M11] = x   ; m[_M12] = 0.0f; m[_M13] = 0.0f; m[_M14] = 0.0f;
		m[_M21] = 0.0f; m[_M22] = y   ; m[_M23] = 0.0f; m[_M24] = 0.0f;
		m[_M31] = 0.0f; m[_M32] = 0.0f; m[_M33] = z   ; m[_M34] = 0.0f;
		m[_M41] = 0.0f; m[_M42] = 0.0f; m[_M43] = 0.0f; m[_M44] = 1.0f;
	}
	//Ðý×ª¾ØÕó
	void RotateZ(float a)
	{
		// cos(a)  sin(a) 0  0
		// -sin(a) cos(a) 0  0
		// 0       0     0  0
		// 0       0      0  1
		float ca = cos(a);
		float sa = sin(a);
		m[_M11] = ca  ; m[_M12] = sa  ; m[_M13] = 0.0f; m[_M14] = 0.0f;
		m[_M21] = -sa ; m[_M22] = ca  ; m[_M23] = 0.0f; m[_M24] = 0.0f;
		m[_M31] = 0.0f; m[_M32] = 0.0f; m[_M33] = 1.0f; m[_M34] = 0.0f;
		m[_M41] = 0.0f; m[_M42] = 0.0f; m[_M43] = 0.0f;	m[_M44] = 1.0f;
	}
	//Ðý×ª¾ØÕó
	void RotateX(float a)
	{
		// 1       0     0      0
		// 0    cos(a)  sin(a)  0
		// 0    -sin(a) cos(a)  0		
		// 0       0      0     1
		float ca = cos(a);
		float sa = sin(a);
		m[_M11] = 1.0f; m[_M12] = 0   ; m[_M13] = 0.0f; m[_M14] = 0.0f;
		m[_M21] = 0   ; m[_M22] = ca  ; m[_M23] = sa; m[_M24] = 0.0f;
		m[_M31] = 0   ; m[_M32] = -sa  ; m[_M33] = ca; m[_M34] = 0.0f;
		m[_M41] = 0.0f; m[_M42] = 0.0f; m[_M43] = 0.0f;	m[_M44] = 1.0f;
	}
	//Ðý×ª¾ØÕó
	void RotateY(float a)
	{
		// cos(a)  0       -sin(a)   0 
		// 0       1        0       0
		// sin(a)  cos(a)   0		0
		// 0       0        0       1
		float ca = cos(a);
		float sa = sin(a);
		m[_M11] = ca;   m[_M12] = 0   ; m[_M13] = -sa;  m[_M14] = 0.0f;
		m[_M21] = 0.0f; m[_M22] = 1.0f; m[_M23] = 0.0f; m[_M24] = 0.0f;
		m[_M31] = sa  ; m[_M32] = 0.0f; m[_M33] = ca;   m[_M34] = 0.0f;
		m[_M41] = 0.0f; m[_M42] = 0.0f; m[_M43] = 0.0f;	m[_M44] = 1.0f;
	}
};

//ÏòÁ¿ * ¾ØÕó = ÏòÁ¿

//È«¾ÖµÄÔËËã·ûÖØÔØ
inline CVector3 operator * (CVector3 v, CMatrix4 m)
{
	//					     m[_M11]  m[_M12]  m[_M13]  m[_M14]
	//  [v.x  v.y  v.z 1] *	 m[_M21]  m[_M22]  m[_M23]  m[_M24]   
	//					     m[_M31]  m[_M32]  m[_M33]  m[_M34]
	//					     m[_M41]  m[_M42]  m[_M43]  m[_M44]
	float a = v.x*m.m[_M11]+v.y*m.m[_M21]+v.z*m.m[_M31]+m.m[_M41];
	float b = v.x*m.m[_M12]+v.y*m.m[_M22]+v.z*m.m[_M32]+m.m[_M42];
	float c = v.x*m.m[_M13]+v.y*m.m[_M23]+v.z*m.m[_M33]+m.m[_M43];
	float d = v.x*m.m[_M14]+v.y*m.m[_M24]+v.z*m.m[_M34]+m.m[_M44];
	return CVector3(a/d, b/d, c/d);
}
//¾ØÕó³ËÒÔ¾ØÕó
inline void M4_MUL_M4(CMatrix4* a, CMatrix4* b, CMatrix4* m3)
{
	m3->m[_M11] = a->m[_M11]*b->m[_M11] + a->m[_M12]*b->m[_M21] + a->m[_M13]*b->m[_M31] + a->m[_M14]*b->m[_M41];
	m3->m[_M12] = a->m[_M11]*b->m[_M12] + a->m[_M12]*b->m[_M22] + a->m[_M13]*b->m[_M32] + a->m[_M14]*b->m[_M42];
	m3->m[_M13] = a->m[_M11]*b->m[_M13] + a->m[_M12]*b->m[_M23] + a->m[_M13]*b->m[_M33] + a->m[_M14]*b->m[_M43];
	m3->m[_M14] = a->m[_M11]*b->m[_M14] + a->m[_M12]*b->m[_M24] + a->m[_M13]*b->m[_M34] + a->m[_M14]*b->m[_M44];

	m3->m[_M21] = a->m[_M21]*b->m[_M11] + a->m[_M22]*b->m[_M21] + a->m[_M23]*b->m[_M31] + a->m[_M24]*b->m[_M41];
	m3->m[_M22] = a->m[_M21]*b->m[_M12] + a->m[_M22]*b->m[_M22] + a->m[_M23]*b->m[_M32] + a->m[_M24]*b->m[_M42];
	m3->m[_M23] = a->m[_M21]*b->m[_M13] + a->m[_M22]*b->m[_M23] + a->m[_M23]*b->m[_M33] + a->m[_M24]*b->m[_M43];
	m3->m[_M24] = a->m[_M21]*b->m[_M14] + a->m[_M22]*b->m[_M24] + a->m[_M23]*b->m[_M34] + a->m[_M24]*b->m[_M44];
	
	m3->m[_M31] = a->m[_M31]*b->m[_M11] + a->m[_M32]*b->m[_M21] + a->m[_M33]*b->m[_M31] + a->m[_M34]*b->m[_M41];
	m3->m[_M32] = a->m[_M31]*b->m[_M12] + a->m[_M32]*b->m[_M22] + a->m[_M33]*b->m[_M32] + a->m[_M34]*b->m[_M42];
	m3->m[_M33] = a->m[_M31]*b->m[_M13] + a->m[_M32]*b->m[_M23] + a->m[_M33]*b->m[_M33] + a->m[_M34]*b->m[_M43];
	m3->m[_M34] = a->m[_M31]*b->m[_M14] + a->m[_M32]*b->m[_M24] + a->m[_M33]*b->m[_M34] + a->m[_M34]*b->m[_M44];

	m3->m[_M41] = a->m[_M41]*b->m[_M11] + a->m[_M42]*b->m[_M21] + a->m[_M43]*b->m[_M31] + a->m[_M44]*b->m[_M41];
	m3->m[_M42] = a->m[_M41]*b->m[_M12] + a->m[_M42]*b->m[_M22] + a->m[_M43]*b->m[_M32] + a->m[_M44]*b->m[_M42];
	m3->m[_M43] = a->m[_M41]*b->m[_M13] + a->m[_M42]*b->m[_M23] + a->m[_M43]*b->m[_M33] + a->m[_M44]*b->m[_M43];
	m3->m[_M44] = a->m[_M41]*b->m[_M14] + a->m[_M42]*b->m[_M24] + a->m[_M43]*b->m[_M34] + a->m[_M44]*b->m[_M44];
}

