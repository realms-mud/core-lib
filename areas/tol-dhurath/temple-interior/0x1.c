//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-room.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "west");
    addDecorator("ruined interior south-east corner hallway");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/2x1.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/0x0.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getDictionary("region")->iconColor(
        decoratorType(), color);

    baseIcon[0][0] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u2560" : "+",
        (baseColor != "") ? "\x1b[0m" : baseColor);

    return baseIcon;
}
