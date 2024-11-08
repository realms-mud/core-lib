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

    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior north wall");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getDictionary("region")->iconColor(
        decoratorType(), color);

    mapping colors = ([
        "pillar":([
            "none": "",
            "grayscale": "\x1b[0;38;5;243;1m",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;243;1m",
            "24-bit": "\x1b[0;38;2;118;118;128;1m",
        ]),
    ]);

    baseIcon[0][0] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u256c" : "+",
        (baseColor != "") ? "\x1b[0m" : "");
    baseIcon[2][2] = sprintf("%s%s%s", colors["pillar"][color],
        (charset == "unicode") ? "\u25ce" : "*",
        (colors["pillar"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
