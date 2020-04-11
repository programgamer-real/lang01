#include "identifier.hpp"


#include "tokenizer.hpp"
#include "any_token.hpp"


namespace tokens
{
	ostream& operator<<(ostream& os, const identifier& token)
	{
		os << "[" << token.type << ": " << token.source_slice << "]";
		return os;
	}
}