//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addDecorator("ruined interior large staired entrance left");

    addExitWithDoor("south",
        "/areas/tol-dhurath/temple-interior/8x2.c");
    addExit("east",
        "/areas/tol-dhurath/temple-interior/9x3.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/8x4.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    mapping colors = ([
        "pillar":([
            "none": "",
            "grayscale": "\x1b[0;38;5;243;1m",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;243;1m",
            "24-bit": "\x1b[0;38;2;118;118;128;1m",
        ]),
    ]);

    baseIcon[2][0] = sprintf("%s%s%s", colors["pillar"][color],
        (charset == "unicode") ? "\u238a" : "*",
        (colors["pillar"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
