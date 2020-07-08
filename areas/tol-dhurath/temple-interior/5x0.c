//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-room.c");
    addDecorator("ruined interior southwest corner");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getDictionary("region")->iconColor(
        decoratorType(), color);

    baseIcon[2][0] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\xe2\x95\xa9" : "+",
        (baseColor != "") ? "\x1b[0m" : baseColor);

    return baseIcon;
}
