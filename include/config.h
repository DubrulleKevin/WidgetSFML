#pragma once

#if !defined(WIDGETSFML_STATIC)

// Windows compilers need specific (and different) keywords for export and import
#define WIDGETSFML_API_EXPORT __declspec(dllexport)
#define WIDGETSFML_API_IMPORT __declspec(dllimport)

// For Visual C++ compilers, we also need to turn off this annoying C4251 warning
#ifdef _MSC_VER

#pragma warning(disable: 4251)

#else // Linux, FreeBSD, Mac OS X

#if __GNUC__ >= 4

// GCC 4 has special keywords for showing/hidding symbols,
// the same keyword is used for both importing and exporting
#define WIDGETSFML_API_EXPORT __attribute__ ((__visibility__ ("default")))
#define WIDGETSFML_API_IMPORT __attribute__ ((__visibility__ ("default")))

#else

// GCC < 4 has no mechanism to explicitely hide symbols, everything's exported
#define WIDGETSFML_API_EXPORT
#define WIDGETSFML_API_IMPORT

#endif

#endif

#else

// Static build doesn't need import/export macros
#define WIDGETSFML_API_EXPORT
#define WIDGETSFML_API_IMPORT

#endif

#if defined(WIDGETSFML_EXPORT)

#define WIDGETSFML_API WIDGETSFML_API_EXPORT

#else

#define WIDGETSFML_API WIDGETSFML_API_IMPORT

#endif