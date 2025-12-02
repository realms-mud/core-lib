//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private object configuration = getService("configuration");

/////////////////////////////////////////////////////////////////////////////
private string buildBaseBanner(string location, string charset, int noGap)
{
    string ret = "";    
    string leftCharacter;
    string rightCharacter;

    switch (charset)
    {
        case "unicode": 
        {
            ret = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
                "-=-=-=-=-=-=-=-=-";

            switch (location)
            {
                case "top":
                {
                    leftCharacter = "\u2554";
                    rightCharacter = "\u2557";
                    break;
                }
                case "bottom":
                {
                    leftCharacter = "\u255a";
                    rightCharacter = "\u255d";
                    break;
                }
                default:
                {
                    leftCharacter = "\u2560";
                    rightCharacter = "\u2563";
                    break;
                }
            }
            break;
        }
        case "ascii":
        {
            ret = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
                "-=-=-=-=-=-=-=-=-";
            leftCharacter = "+";
            rightCharacter = "+";
            break;
        }
        default:
        {
            ret = sprintf("%78s", "");
            leftCharacter = " ";
            rightCharacter = " ";
            break;
        }
    }

    return leftCharacter + ret + rightCharacter + "\n";
}

/////////////////////////////////////////////////////////////////////////////
public varargs string buildBanner(string colorConfiguration, string charset,
    string location, string type, string area, int noGap)
{
    string ret = buildBaseBanner(location, charset, noGap);

    string leftDivider;
    string rightDivider;
    switch (charset)
    {
        case "ascii": 
        {
            leftDivider = "+";
            rightDivider = "+";
            break;
        }
        case "unicode": 
        {
            leftDivider = "\u2561";
            rightDivider = "\u255e";
            break;
        }
        default:
        {
            leftDivider = " ";
            rightDivider = " ";
            break;
        }
    }    
    
    string banner = "";
    if (!noGap)
    {
        banner = sprintf("%s %s%s %s", leftDivider, capitalize(type),
            (area ? " " + capitalize(area) : ""), rightDivider);
    }

    int startingPoint = 40 - (sizeof(banner) / 2) - (charset == "unicode");

    for (int i = startingPoint; i < (startingPoint + sizeof(banner)); i++)
    {
        ret[i] = banner[i - startingPoint];
    }

    if (charset == "unicode")
    {
        ret = regreplace(ret, "(-|=)", "\u2550", 1);
    }

    return configuration->decorate(ret, "any", "dividers", colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
public string divider(string colorConfiguration, string charset)
{
    string divider = "";
    switch (charset)
    {
        case "ascii": 
        {
            divider = "|";
            break;
        }
        case "unicode": 
        {
            divider = "\u2551";
            break;
        }
        default:
        {
            divider = " ";
            break;
        }
    }
    return configuration->decorate(divider, "any", "dividers", 
        colorConfiguration);
}

/////////////////////////////////////////////////////////////////////////////
public string banneredContent(string colorConfiguration, string charset,
    string content)
{
    string divider = divider(colorConfiguration, charset);

    int textLength = unicodeIsSingleCharacter() ? textWidth(content) :
        (75 + sizeof(content) - textWidth(content));

    string formatString = "%s %-" + to_string(textLength) + "s %s\n";

    return sprintf(formatString, divider, content, divider);
}
