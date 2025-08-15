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
    addDecorator("ruined interior north alcove");

    addExit("up",
        "/areas/tol-dhurath/temple-interior-2nd-left/2x2.c");
    addExitWithDoor("south",
        "/areas/tol-dhurath/temple-interior/2x3.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    mapping colors = ([
        "stairs":([
            "none": "",
            "grayscale": "\x1b[0;38;5;253m",
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;226m",
            "24-bit": "\x1b[0;38;2;180;180;60m",
        ])
    ]);
    string baseColor = getService("region")->iconColor(
        decoratorType(), color);

    baseIcon[0][0] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u2566" : "+",
        (baseColor != "") ? "\x1b[0m" : baseColor);

    baseIcon[1][1] = sprintf("%s%s%s", colors["stairs"][color],
        (charset == "unicode") ? "\u25a4" : "+",
        (colors["stairs"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
