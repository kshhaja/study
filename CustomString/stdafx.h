#pragma once

#ifdef SHFRAMEWORK_DLL
#ifdef SHFRAMEWORK_EXPORTS
#define SHFRAMEWORK_API __declspec(dllexport)
#else
#define SHFRAMEWORK_API __declspec(dllimport)
#endif
#else
#define SHFRAMEWORK_API
#endif