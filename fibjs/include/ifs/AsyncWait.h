/***************************************************************************
 *   Copyright (C) 2012 by Leo Hoo                                         *
 *   lion@9465.net                                                         *
 *                                                                         *
 ***************************************************************************/

#ifndef _AsyncWait_base_H_
#define _AsyncWait_base_H_

/**
 @author Leo Hoo <lion@9465.net>
 */

#include "../object.h"
#include "Handler.h"

namespace fibjs
{

class Handler_base;

class AsyncWait_base : public Handler_base
{
public:
	// AsyncWait_base
	virtual result_t end() = 0;

	DECLARE_CLASSINFO(AsyncWait_base);

public:
	static void s_end(const v8::FunctionCallbackInfo<v8::Value>& args);
};

}


namespace fibjs
{
	inline ClassInfo& AsyncWait_base::class_info()
	{
		static ClassData::ClassMethod s_method[] = 
		{
			{"end", s_end}
		};

		static ClassData s_cd = 
		{ 
			"AsyncWait", NULL, 
			1, s_method, 0, NULL, 0, NULL, NULL, NULL,
			&Handler_base::class_info()
		};

		static ClassInfo s_ci(s_cd);
		return s_ci;
	}


	inline void AsyncWait_base::s_end(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		METHOD_INSTANCE(AsyncWait_base);
		METHOD_ENTER(0, 0);

		hr = pInst->end();

		METHOD_VOID();
	}

}

#endif

