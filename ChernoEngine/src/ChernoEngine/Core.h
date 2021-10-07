#ifndef CORE_H
#define CORE_H

#ifdef CE_PLATFORM_WINDOWS
  #ifdef CE_DYNAMIC_LINK
    #ifdef CE_BUILD_DLL
      #define CHERNOENGINE_API __declspec(dllexport)
    #else
      #define CHERNOENGINE_API __declspec(dllimport)
    #endif
  #else
    #define CHERNOENGINE_API
  #endif
#else
  #error Engine only supports Windows platforms
#endif

#ifdef CE_ENABLE_ASSERTS
  #define CE_ASSERT(x, ...) { if(!x) { CE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();) } }
  #define CE_CORE_ASSERT(x, ...) { if(!x) { CE_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
  #define CE_ASSERT(x, ...)
  #define CE_CORE_ASSERT(x, ...)
#endif

#endif //end include guard
