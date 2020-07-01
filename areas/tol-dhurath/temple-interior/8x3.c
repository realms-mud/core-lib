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
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    mapping colors = ([
        "pillar":([
            "none": "",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;243;1m",
            "24-bit": "\x1b[0;38;2;118;118;128;1m",
        ]),
    ]);

    baseIcon[2][0] = sprintf("%s%s%s", colors["pillar"][color],
        (charset == "unicode") ? "\xe2\x8e\x8a" : "*",
        (colors["pillar"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
