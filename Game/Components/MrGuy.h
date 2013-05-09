#pragma once
#include "Components.h"
class COMPONENTS_API MrGuy : public CComponents
{
public:
	MrGuy(void);
	~MrGuy(void);
	void move(void);
	void shoot(void);
public:
	HBITMAP head;
	HBITMAP body;
	int location[2];
	int dirFacing;
};