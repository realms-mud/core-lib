//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addDecorator("ruined interior east-west hallway");

    addExit("east",
        "/areas/tol-dhurath/temple-interior/5x2.c");
    addExit("west",
        "/areas/tol-dhurath/temple-interior/3x2.c");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getDictionary("region")->iconColor(
        decoratorType(), color);

    baseIcon[0][2] = sprintf("%s%s%s", baseColor,
        (charset == "unicode") ? "\u256c" : "+",
        (baseColor != "") ? "\x1b[0m" : "");

    return baseIcon;
}
