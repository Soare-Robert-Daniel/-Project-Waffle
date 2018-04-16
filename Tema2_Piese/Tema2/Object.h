#include "stdafx.h"
#pragma once
class Object
{
public:
	Object();
	virtual int getPret() { return -1; };
	virtual void afisare() { cout << "Nimic\n"; };
	virtual ~Object();
};

