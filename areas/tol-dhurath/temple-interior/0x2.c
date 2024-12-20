//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setInterior("/lib/environment/interiors/ruin-room.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "west");

    addDecorator("ruined interior west wall");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    mapping colors = ([
        "dais":([
            "none": "",
            "grayscale": "\x1b[0;48;5;236;38;5;248m",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;48;5;17;38;5;75m",
            "24-bit": "\x1b[0;48;2;0;0;60;38;2;90;175;255m",
        ]),
        "arms":([
            "none": "",
            "grayscale": "\x1b[0;48;5;234;38;5;244m",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;48;5;88;38;5;80;1m",
            "24-bit": "\x1b[0;48;2;60;0;0;38;2;160;200;255;1m",
        ])
    ]);

    baseIcon[0][1] = sprintf("%s%s%s", colors["arms"][color],
        (charset == "unicode") ? "\u2572" : "\\",
        (colors["arms"][color] != "") ? "\x1b[0m" : "");
    baseIcon[1][1] = sprintf("%s%s%s", colors["dais"][color],
        (charset == "unicode") ? "\u2384" : "*",
        (colors["arms"][color] != "") ? "\x1b[0m" : "");
    baseIcon[2][1] = sprintf("%s%s%s", colors["arms"][color],
        (charset == "unicode") ? "\u2571" : "/",
        (colors["arms"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
