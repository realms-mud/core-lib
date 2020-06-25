//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior south wall");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getDictionary("region")->iconColor(
        decoratorType(), color);

    mapping colors = ([
        "pillar":([
            "none": "",
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;243;1m",
            "24-bit": "\x1b[0;38;2;118;118;128;1m",
        ]),
        "dais":([
            "none": "",
            "3-bit": "\x1b[0;41;36m",
            "8-bit": "\x1b[0;48;5;52;38;5;235m",
            "24-bit": "\x1b[0;48;2;12;12;10;38;2;56;62;56m",
        ]),
        "throne":([
            "none": "",
            "3-bit": "\x1b[0;41;36m",
            "8-bit": "\x1b[0;48;5;52;38;5;235m",
            "24-bit": "\x1b[0;48;2;12;12;10;38;2;112;162;106m",
        ]),
    ]);

    baseIcon[0][2] = sprintf("%s%s%s", colors["pillar"][color],
        (charset == "unicode") ? "\xe2\x97\x8e" : "*",
        (colors["pillar"][color] != "") ? "\x1b[0m" : "");
    baseIcon[0][1] = sprintf("%s%s%s", colors["dais"][color],
        (charset == "unicode") ? "\xe2\x94\x90" : "*",
        (colors["dais"][color] != "") ? "\x1b[0m" : "");
    baseIcon[0][0] = sprintf("%s%s%s", colors["dais"][color],
        (charset == "unicode") ? "\xe2\x96\xa4" : "*",
        (colors["dais"][color] != "") ? "\x1b[0m" : "");
    baseIcon[1][1] = sprintf("%s%s%s", colors["dais"][color],
        (charset == "unicode") ? "\xe2\x94\x82" : "*",
        (colors["dais"][color] != "") ? "\x1b[0m" : "");
    baseIcon[1][0] = sprintf("%s%s%s", colors["throne"][color],
        (charset == "unicode") ? "\xe2\x99\x94" : "L",
        (colors["throne"][color] != "") ? "\x1b[0m" : "");

    baseIcon[2][1] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\xe2\x95\xa7" : "*",
        (baseColor != "") ? "\x1b[0m" : "");

    return baseIcon;
}