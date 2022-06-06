#pragma once

#include <unordered_map>
#include <zconf.h>
#include <fstream>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "SDK/SDK.h"
#include "Utils/draw.h"
#include "Utils/util.h"
#include "Utils/util_sdk.h"
#include "GTGUI/gtgui.h"

enum class AutostrafeType : int
{
    AS_FORWARDS,
    AS_BACKWARDS,
    AS_LEFTSIDEWAYS,
    AS_RIGHTSIDEWAYS,
    AS_RAGE,
};

class ColorVar
{
public:
    ImColor color;
    bool rainbow;
    float rainbowSpeed;

    ColorVar() {}

    ColorVar(ImColor color)
    {
        this->color = color;
        this->rainbow = false;
        this->rainbowSpeed = 0.5f;
    }

    ImColor Color()
    {
        ImColor result = /*this->rainbow ? Util::GetRainbowColor(this->rainbowSpeed) :*/ this->color;
        result.Value.w = this->color.Value.w;
        return result;
    }
};

namespace Settings
{

	namespace SkyBox
	{
        extern bool enabled;
        extern const char* name;
	}

	namespace DisablePostProcessing
	{
        extern bool enabled;
	}

	namespace NoFog
	{
        extern bool enabled;
	}

	namespace ESP
	{
        extern bool enabled;
	}
	
	namespace Bhop
	{
        extern bool enabled;
	}

	namespace ScreenshotCleaner
	{
        extern bool enabled;
	}

    namespace UI
    {
        extern ColorVar mainColor;
        extern ColorVar bodyColor;
        extern ColorVar fontColor;
        extern ColorVar accentColor;

        namespace Windows
        {
            namespace Main
            {
                extern int posX;
                extern int posY;
                extern int sizeX;
                extern int sizeY;
                extern bool open;
                extern bool reload; // True on config load, used to change Window Position.
            }
            namespace Colors
            {
                extern int posX;
                extern int posY;
                extern int sizeX;
                extern int sizeY;
                extern bool open;
                extern bool reload; // True on config load, used to change Window Position.
            }
        }
        namespace Fonts
        {
            namespace ESP
            {
                extern char* family;
                extern int size;
                extern int flags;
            }
        }
    }


    bool RegisterConVars();
}
