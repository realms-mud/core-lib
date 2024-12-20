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
    addItem("/lib/environment/items/lighting/sconce.c", "south");
    addDecorator("ruined interior north-west corner hallway");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/3x0.c");
    addExit("north",
        "/areas/tol-dhurath/temple-interior/4x1.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getDictionary("region")->iconColor(
        decoratorType(), color);

    baseIcon[2][2] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u2569" : "+",
        (baseColor != "") ? "\x1b[0m" : baseColor);

    return baseIcon;
}
