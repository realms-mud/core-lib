//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior courtyard");
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
        "floor":([
            "none": "",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;23m",
            "24-bit": "\x1b[0;38;2;8;10;12m",
        ]),
        "wall":([
            "none": "",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;234m",
            "24-bit": "\x1b[0;38;2;25;28;25m",
        ]),
    ]);

    baseIcon[1][1] = sprintf("%s%s%s", colors["wall"][color],
        (charset == "unicode") ? "\xe2\x95\x94" : " ",
        (colors["wall"][color] != "") ? "\x1b[0m" : "");

    baseIcon[1][2] = sprintf("%s%s%s", colors["wall"][color],
        (charset == "unicode") ? "\xe2\x95\x97" : " ",
        (colors["wall"][color] != "") ? "\x1b[0m" : "");

    baseIcon[2][1] = sprintf("%s%s%s", colors["wall"][color],
        (charset == "unicode") ? "\xe2\x95\xac" : " ",
        (colors["wall"][color] != "") ? "\x1b[0m" : "");

    baseIcon[2][2] = sprintf("%s%s%s", colors["wall"][color],
        (charset == "unicode") ? "\xe2\x95\xac" : " ",
        (colors["wall"][color] != "") ? "\x1b[0m" : "");

    baseIcon[1][0] = sprintf("%s%s%s", colors["floor"][color],
        (charset == "unicode") ? "\xe2\x96\x85" : " ",
        (colors["floor"][color] != "") ? "\x1b[0m" : "");

    baseIcon[2][0] = sprintf("%s%s%s", colors["pillar"][color],
        (charset == "unicode") ? "\xe2\x8e\x8a" : "*",
        (colors["pillar"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
