//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin-great-hall.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "west");
    addDecorator("ruined interior northwest corner");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/9x2.c");
    addExitWithDoor("north",
        "/areas/tol-dhurath/temple-interior/8x3.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/8x1.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getDictionary("region")->iconColor(
        decoratorType(), color);

    mapping colors = ([
        "door":([
            "none":"",
            "3-bit" : "\x1b[0;33m",
            "8-bit" : "\x1b[0;38;5;100m",
            "24-bit" : "\x1b[0;38;2;102;102;38m",
        ]),
    ]);

    baseIcon[0][1] = sprintf("%s%s%s", colors["door"][color],
        (charset == "unicode") ? "\xe2\x96\x94" : "-",
        (colors["door"][color] != "") ? "\x1b[0m" : "");
    baseIcon[0][2] = sprintf("%s%s%s", colors["door"][color],
        (charset == "unicode") ? "\xe2\x96\x94" : "-",
        (colors["door"][color] != "") ? "\x1b[0m" : "");
    baseIcon[0][0] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\xe2\x95\xac" : "+",
        (baseColor != "") ? "\x1b[0m" : "");

    return baseIcon;
}
