#pragma once

#ifndef ZIMG_CCDEP_H_
#define ZIMG_CCDEP_H_

#if defined(_MSC_VER)
  #define FORCE_INLINE __forceinline
#elif defined(__GNUC__)
  #define FORCE_INLINE __attribute__((always_inline))
#else
  #define FORCE_INLINE
#endif

#if defined(_MSC_VER) || defined(__GNUC__)
  #define RESTRICT __restrict
#else
  #define RESTRICT
#endif

#if defined(_MSC_VER)
  #define ASSUME_CONDITION(x) __assume((x))
#elif defined(__GNUC__)
  #define ASSUME_CONDITION(x) do { if (!(x)) __builtin_unreachable(); } while (0)
#else
  #define ASSUME_CONDITION(x) ((void)0)
#endif

#if !((defined(_MSC_VER) && !defined(_CPPUNWIND)) || (defined(__GNUC__) && !defined(__EXCEPTIONS)))
  #define TRY try
  #define TRY_FUNC_BEGIN try
  #define TRY_FUNC_END
  #define CATCH(T) catch (T)
  #define CATCH_T(T, e) catch (T e)
  #define CATCH_ALL catch (...)
  #define THROW(e) throw e
  #define RETHROW throw
#else
  [[noreturn]] void zimg_x_abort();
  #define TRY if (true)
  #define TRY_FUNC_BEGIN {
  #define TRY_FUNC_END }
  #define CATCH(T) if (false)
  #define CATCH_T(T, e) if (false) for (T e = *(T *)0; false; )
  #define CATCH_ALL if (false)
  #define THROW(e) zimg_x_abort()
  #define RETHROW zimg_x_abort()
#endif

#endif /* ZIMG_CCDEP_H_ */
