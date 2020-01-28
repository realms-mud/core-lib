//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private object configuration = getDictionary("configuration");

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

            if (!noGap)
            {
                ret += "=-=-";
            }

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
            leftDivider = "\xe2\x95\xa1";
            rightDivider = "\xe2\x95\x9e";
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

    int startingPoint = ((charset == "unicode") * 2) + 40 - (sizeof(banner) / 2);

    for (int i = startingPoint; i < (startingPoint + sizeof(banner)); i++)
    {
        ret[i] = banner[i - startingPoint];
    }

    if (charset == "unicode")
    {
        ret = regreplace(ret, "(-|=)", "\xe2\x95\x90", 1);
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
            divider = "\xe2\x95\x91";
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
    int padding = sizeof(content) - sizeof(regreplace(content, "(\x1b[^m]+m)", "", 1));
    string formatString = "%s %-" + to_string(75 + padding) + "s %s\n";

    return sprintf(formatString, divider, content, divider);
}
