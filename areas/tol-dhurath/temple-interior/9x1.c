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
    addItem("/lib/environment/items/lighting/skylight.c");
    addItem("/lib/environment/items/columns/ruined-pillar.c", "west");

    addDecorator("ruined interior floor");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/11x1.c");
    addExit("west",
        "/areas/tol-dhurath/temple-interior/8x1.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/9x2.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/9x0.c");
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

    baseIcon[1][0] = sprintf("%s%s%s", colors["pillar"][color],
        (charset == "unicode") ? "\xe2\x97\x8e" : "*",
        (colors["pillar"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
