//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

private object configuration = load_object("/lib/dictionaries/configurationDictionary.c");

/////////////////////////////////////////////////////////////////////////////
private string buildBaseBanner(string location, int useUnicode)
{
    string ret = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
            "-=-=-=-=-=-=-=-=-";
    string leftCharacter;
    string rightCharacter;

    if (!useUnicode)
    {
        leftCharacter = "+";
        rightCharacter = "+";
    }
    else
    {
        ret += "=-=-";
        switch (location)
        {
            case "top":
            {
                leftCharacter = "\xe2\x95\x94";
                rightCharacter = "\xe2\x95\x97";
                break;
            }
            case "bottom":
            {
                leftCharacter = "\xe2\x95\x9a";
                rightCharacter = "\xe2\x95\x9d";
                break;
            }
            default:
            {
                leftCharacter = "\xe2\x95\xa0";
                rightCharacter = "\xe2\x95\xa3";
                break;
            }
        }
    }

    return leftCharacter + ret + rightCharacter + "\n";
}

/////////////////////////////////////////////////////////////////////////////
public varargs string buildBanner(string colorConfiguration, int useUnicode,
    string location, string type, string area)
{
    string ret = buildBaseBanner(location, useUnicode);

    string banner = sprintf("%s %s%s %s", (useUnicode ? "\xe2\x95\xa1" : "+"),
        capitalize(type), (area ? " " + capitalize(area) : ""),
        (useUnicode ? "\xe2\x95\x9e" : "+"));

    int startingPoint = (useUnicode * 2) + 40 - (sizeof(banner) / 2);

    for (int i = startingPoint; i < (startingPoint + sizeof(banner)); i++)
    {
        ret[i] = banner[i - startingPoint];
    }

    if (useUnicode)
    {
        ret = regreplace(ret, "(-|=)", "\xe2\x95\x90", 1);
    }
    return configuration->decorate(ret, "any", "dividers", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
public string banneredContent(string colorConfiguration, int useUnicode,
    string content)
{
    string divider = configuration->decorate(useUnicode ? "\xe2\x95\x91" : "|",
        "any", "dividers", colorConfiguration);

    return sprintf("%s %s %s\n", divider, content, divider);
}
