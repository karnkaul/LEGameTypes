#include <string>
#include <vector>
#include "Version.h"
#include "Utils.h"

#if __linux__
#undef major
#undef minor
#undef patch
#endif

namespace Core
{
namespace
{
u32 Parse(const std::vector<std::string>& vec, size_t idx)
{
	return (vec.size() > idx) ? static_cast<u32>(Strings::ToS32(vec[idx], 0)) : 0;
}
} // namespace

Version::Version() = default;

Version::Version(u32 major, u32 minor, u32 patch, u32 tweak) : major(major), minor(minor), patch(patch), tweak(tweak) {}

Version::Version(std::string_view serialised)
{
	auto tokens = Strings::Tokenise(serialised, '.', {});
	major = Parse(tokens, 0);
	minor = Parse(tokens, 1);
	patch = Parse(tokens, 2);
	tweak = Parse(tokens, 3);
}

u32 Version::Major() const
{
	return major;
}

u32 Version::Minor() const
{
	return minor;
}

u32 Version::Patch() const
{
	return patch;
}

u32 Version::Tweak() const
{
	return tweak;
}

std::string Version::ToString() const
{
	static constexpr size_t MAX = 3 + 1 + 3 + 1 + 3 + 1 + 3;
	std::string ret;
	ret.reserve(MAX);
	ret += Strings::ToString(major);
	ret += ".";
	ret += Strings::ToString(minor);
	ret += ".";
	ret += Strings::ToString(patch);
	ret += ".";
	ret += Strings::ToString(tweak);
	return ret;
}

bool Version::Upgrade(const Version& rhs)
{
	if (*this < rhs)
	{
		*this = rhs;
		return true;
	}
	return false;
}

bool Version::operator==(const Version& rhs)
{
	return major == rhs.major && minor == rhs.minor && patch == rhs.patch && tweak == rhs.tweak;
}

bool Version::operator!=(const Version& rhs)
{
	return !(*this == rhs);
}

bool Version::operator<(const Version& rhs)
{
	return (major < rhs.major) || (major == rhs.major && minor < rhs.minor)
		   || (major == rhs.major && minor == rhs.minor && patch < rhs.patch)
		   || (major == rhs.major && minor == rhs.minor && patch == rhs.patch && tweak < rhs.tweak);
}

bool Version::operator<=(const Version& rhs)
{
	return (*this == rhs) || (*this < rhs);
}

bool Version::operator>(const Version& rhs)
{
	return (major > rhs.major) || (major == rhs.major && minor > rhs.minor)
		   || (major == rhs.major && minor == rhs.minor && patch > rhs.patch)
		   || (major == rhs.major && minor == rhs.minor && patch == rhs.patch && tweak > rhs.tweak);
}

bool Version::operator>=(const Version& rhs)
{
	return (*this == rhs) || (*this > rhs);
}
} // namespace Core
