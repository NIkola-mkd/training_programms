#pragma once

class Exception
{

private:

	const char* err_;

public:

	Exception(const char* err);

	const char* getError() const;

};