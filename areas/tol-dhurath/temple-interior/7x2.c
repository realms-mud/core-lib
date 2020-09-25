//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    mapping colors = ([
        "exit":([
            "none":"",
            "grayscale": "\x1b[0;38;5;253;1m",
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;100;1m",
            "24-bit": "\x1b[0;38;2;142;102;38;1m",
        ]),
    ]);

    baseIcon[0][1] = sprintf("%s%s%s", colors["exit"][color],
        (charset == "unicode") ? "\u21d3" : "-",
        (colors["exit"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
