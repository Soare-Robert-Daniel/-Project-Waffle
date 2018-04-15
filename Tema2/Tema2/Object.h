#include "stdafx.h"
#pragma once
class Object
{
public:
	Object();
	virtual int getPret() { return 0; };
	virtual void afisare() {};
	virtual ~Object();
};

