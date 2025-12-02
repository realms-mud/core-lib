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

    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "south");
    addDecorator("ruined interior west alcove north entry");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/1x3.c");
    addExitWithDoor("north",
        "/areas/tol-dhurath/temple-interior/0x4.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getService("region")->iconColor(
        decoratorType(), color);

    baseIcon[2][0] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u2560" : "+",
        (baseColor != "") ? "\x1b[0m" : baseColor);

    return baseIcon;
}
