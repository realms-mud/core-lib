//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addDecorator("ruined interior courtyard");
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
        "floor":([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;23m",
            "24-bit": "\x1b[0;38;2;8;10;12m",
        ]),
        "wall":([
            "none": "",
            "grayscale": "\x1b[0;38;5;234m",
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;234m",
            "24-bit": "\x1b[0;38;2;25;28;25m",
        ]),
    ]);

    baseIcon[1][0] = sprintf("%s%s%s", colors["wall"][color],
        (charset == "unicode") ? "\u2554" : " ",
        (colors["wall"][color] != "") ? "\x1b[0m" : "");

    baseIcon[1][1] = sprintf("%s%s%s", colors["wall"][color],
        (charset == "unicode") ? "\u2557" : " ",
        (colors["wall"][color] != "") ? "\x1b[0m" : "");

    baseIcon[2][0] = sprintf("%s%s%s", colors["wall"][color],
        (charset == "unicode") ? "\u256c" : " ",
        (colors["wall"][color] != "") ? "\x1b[0m" : "");

    baseIcon[2][1] = sprintf("%s%s%s", colors["wall"][color],
        (charset == "unicode") ? "\u256c" : " ",
        (colors["wall"][color] != "") ? "\x1b[0m" : "");

    baseIcon[1][2] = sprintf("%s%s%s", colors["floor"][color],
        (charset == "unicode") ? "\u2585" : " ",
        (colors["floor"][color] != "") ? "\x1b[0m" : "");

    baseIcon[2][2] = sprintf("%s%s%s", colors["pillar"][color],
        (charset == "unicode") ? "\u238a" : "*",
        (colors["pillar"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
