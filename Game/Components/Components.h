// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMPONENTS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMPONENTS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMPONENTS_EXPORTS
#define COMPONENTS_API __declspec(dllexport)
#else
#define COMPONENTS_API __declspec(dllimport)
#endif

// This class is exported from the Components.dll
class COMPONENTS_API CComponents {
public:
	CComponents(void);
	// TODO: add your methods here.
};

extern COMPONENTS_API int nComponents;

COMPONENTS_API int fnComponents(void);