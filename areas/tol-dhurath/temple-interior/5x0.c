//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior southwest corner");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/4x0.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/5x1.c");
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
