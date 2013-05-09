 // Components.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Components.h"


// This is an example of an exported variable
COMPONENTS_API int nComponents=0;

// This is an example of an exported function.
COMPONENTS_API int fnComponents(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Components.h for the class definition
CComponents::CComponents()
{
	return;
}
