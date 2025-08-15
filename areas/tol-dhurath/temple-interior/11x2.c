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

    setInterior("/lib/environment/interiors/ruin-great-hall.c");
    addFeature("/lib/environment/features/floors/ruined-marble-floor.c");
    addItem("/lib/environment/items/lighting/sconce.c", "east");
    addItem("/lib/environment/items/columns/ruined-pillar.c", "west");
    addDecorator("ruined interior northeast corner north entry");

    addExit("west",
        "/areas/tol-dhurath/temple-interior/9x2.c");
    addExitWithDoor("north",
        "/areas/tol-dhurath/temple-interior/11x3.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/11x1.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getService("region")->iconColor(
        decoratorType(), color);

    baseIcon[2][2] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u2560" : "+",
        (baseColor != "") ? "\x1b[0m" : baseColor);

    return baseIcon;
}
