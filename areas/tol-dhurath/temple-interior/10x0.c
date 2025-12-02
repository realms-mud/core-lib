//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setInterior("/lib/environment/interiors/ruin-great-hall.c");
    addDecorator("ruined interior south wall");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getService("region")->iconColor(
        decoratorType(), color);

    mapping colors = ([
        "pillar":([
            "none": "",
            "grayscale": "\x1b[0;38;5;243;1m",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;243;1m",
            "24-bit": "\x1b[0;38;2;118;118;128;1m",
        ]),
        "dais":([
            "none": "",
            "grayscale": "\x1b[0;38;5;235m",
            "3-bit": "\x1b[0;41;36m",
            "8-bit": "\x1b[0;48;5;52;38;5;235m",
            "24-bit": "\x1b[0;48;2;12;12;10;38;2;56;62;56m",
        ]),
        "throne":([
            "none": "",
            "grayscale": "\x1b[0;48;5;232;38;5;235m",
            "3-bit": "\x1b[0;41;36m",
            "8-bit": "\x1b[0;48;5;52;38;5;235m",
            "24-bit": "\x1b[0;48;2;12;12;10;38;2;112;162;106m",
        ]),
    ]);

    baseIcon[0][2] = sprintf("%s%s%s", colors["pillar"][color],
        (charset == "unicode") ? "\u25ce" : "*",
        (colors["pillar"][color] != "") ? "\x1b[0m" : "");
    baseIcon[0][1] = sprintf("%s%s%s", colors["dais"][color],
        (charset == "unicode") ? "\u2510" : "*",
        (colors["dais"][color] != "") ? "\x1b[0m" : "");
    baseIcon[0][0] = sprintf("%s%s%s", colors["dais"][color],
        (charset == "unicode") ? "\u25a4" : "*",
        (colors["dais"][color] != "") ? "\x1b[0m" : "");
    baseIcon[1][1] = sprintf("%s%s%s", colors["dais"][color],
        (charset == "unicode") ? "\u2502" : "*",
        (colors["dais"][color] != "") ? "\x1b[0m" : "");
    baseIcon[1][0] = sprintf("%s%s%s", colors["throne"][color],
        (charset == "unicode") ? "\u2654" : "L",
        (colors["throne"][color] != "") ? "\x1b[0m" : "");

    baseIcon[2][1] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u2567" : "*",
        (baseColor != "") ? "\x1b[0m" : "");

    return baseIcon;
}
