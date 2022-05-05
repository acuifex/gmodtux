#include "util.h"
#include "../settings.h"

std::wstring Util::StringToWstring(std::string str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

	try
	{
		return converter.from_bytes(str);
	}
	catch (std::range_error)
	{
		std::wostringstream s;
		s << str.c_str();
		return s.str();
	}
}
/* Get Epoch timestamp in ms */
long Util::GetEpochTime()
{
	auto duration = std::chrono::system_clock::now().time_since_epoch();

	return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

std::string Util::ToLower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), (int (*)(int))std::tolower);
	
	return str;
}

std::string Util::ToUpper(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), (int (*)(int))std::toupper);
	
	return str;
}