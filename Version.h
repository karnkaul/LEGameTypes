#pragma once
#include <string>
#include "StdTypes.h"

namespace Core
{
struct Version
{
private:
	u32 major = 0;
	u32 minor = 0;
	u32 patch = 0;
	u32 tweak = 0;

public:
	Version();
	Version(u32 major, u32 minor, u32 patch, u32 tweak);
	Version(std::string_view serialised);

public:
	u32 Major() const;
	u32 Minor() const;
	u32 Patch() const;
	u32 Tweak() const;
	std::string ToString() const;

	bool Upgrade(const Version& rhs);

	bool operator==(const Version& rhs);
	bool operator!=(const Version& rhs);
	bool operator<(const Version& rhs);
	bool operator<=(const Version& rhs);
	bool operator>(const Version& rhs);
	bool operator>=(const Version& rhs);
};
} // namespace Core
