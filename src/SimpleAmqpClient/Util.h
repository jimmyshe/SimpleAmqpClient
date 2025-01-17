#ifndef SIMPLEAMQPCLIENT_UTIL_H
#define SIMPLEAMQPCLIENT_UTIL_H
/*
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MIT
 *
 * Copyright (c) 2010-2013 Alan Antonuk
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * ***** END LICENSE BLOCK *****
 */

//#ifdef WIN32
//#ifdef SimpleAmqpClient_EXPORTS
//#define SIMPLEAMQPCLIENT_EXPORT __declspec(dllexport)
//#else
//#define SIMPLEAMQPCLIENT_EXPORT __declspec(dllimport)
//#endif
//#else
//#define SIMPLEAMQPCLIENT_EXPORT
//#endif
//
//#if defined(__GNUC__) || defined(__clang__)
//#define SAC_DEPRECATED(msg) __attribute__((deprecated(msg)))
//#elif defined(_MSC_VER)
//#define SAC_DEPRECATED(msg) __declspec(deprecated(msg))
//#else
//#define SAC_DEPRECATED(msg)
//#endif

#define SIMPLEAMQPCLIENT_EXPORT
#define SAC_DEPRECATED(msg)


#endif  // SIMPLEAMQPCLIENT_UTIL_H
