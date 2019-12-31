#include "CStaticObject.h"

CStaticObject::CStaticObject()
{
	m_dwType = OBJECT_TYPE_STATIC;
}

std::string CStaticObject::Print()
{
	return "Static Object";
}
