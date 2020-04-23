#ifndef HEADER_TOKENS_ANY_TOKEN_DEFINED
#define HEADER_TOKENS_ANY_TOKEN_DEFINED


#include "../libs.hpp"
#include "every_token.hpp"


// Comma-separated list of all valid token types
#define TOKENS_EVERY empty, upline, newline, identifier, numeric, quoted_string, short_string, delimiter, operator_t, invalid

// Comma-separated list of all tokens that can be matched
#define TOKENS_MATCHABLE upline, newline, identifier, numeric, quoted_string, short_string, delimiter, operator_t, invalid

// Comma-separated list of all tokens that contain literal values
#define TOKENS_LITERAL numeric, quoted_string, short_string


namespace tokens
{
	// A custom variant type that can hold an empty token or any matchable token.
	class any_token: protected variant<TOKENS_EVERY>
	{
	public:
		using variant::variant;
		
		using variant::emplace;
		
		using variant::operator=;
		
		// Checks if this holds any of the given token type.
		template<typename... T>
		constexpr bool holds() const
		{ return (holds_alternative<T>(self) || ...); }
		
		// Checks if this holds any of the given token type and its contents match.
		template<typename... T>
		constexpr bool holds(const string_view& other_content) const
		{ return (holds_alternative<T>(self) || ...) && content() == other_content; }
		
		// Applies the given visitor object to the held token.
		template<typename V>
		decltype(auto) visit(V&& visitor)
		{ return std::visit(visitor, (variant&)self); }
		
		// Applies the given visitor object to the held token.
		template<typename V>
		decltype(auto) visit(V&& visitor) const
		{ return std::visit(visitor, (const variant&)self); }
		
		// Returns the held token's name.
		string_view name() const;
		
		// Returns the slice of source text obtained when the held token was matched.
		string_view source_slice() const;
		
		// Returns the contents of the token. (Not always the same as source_slice)
		string_view content() const;
		
		// Returns the line number where the held token was matched.
		size_t lineno() const;
		
		// Returns the indentation of the line where the held token was matched.
		int lineindent() const;
		
		// Returns the indentation of the line where the held token was matched.
		size_t leading_space() const;
		
		// Prints the token's text to an ostream.
		friend ostream& operator<<(ostream& os, const any_token& token);
		
		// Checks if the two given tokens are equal in value.
		friend bool operator==(const any_token& lhs, const any_token& rhs);
		
		// Checks if the two given tokens are different in value.
		friend bool operator!=(const any_token& lhs, const any_token& rhs);
	};
	
	ostream& operator<<(ostream& os, const vector<any_token>& tokens);
}


#else // HEADER_TOKENS_ANY_TOKEN_DEFINED


namespace tokens
{
	class any_token;
}


#endif // HEADER_TOKENS_ANY_TOKEN_DEFINED