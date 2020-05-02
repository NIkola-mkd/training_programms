#include "Exception.h"
#pragma once


Exception::Exception(const char* err)
{
	err_ = err;
}

const char* Exception::getError() const
{
	return err_;
}
