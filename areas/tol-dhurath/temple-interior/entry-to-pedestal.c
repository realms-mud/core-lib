//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();

    setInterior("/lib/environment/interiors/ruin-hallway.c");
    addFeature("/areas/tol-dhurath/features/amethyst-floor.c");
    addFeature("/areas/tol-dhurath/features/amethyst-ceiling.c");
    addDecorator("ruined interior north-south hallway");
    addDecorator("ruined interior north-south hallway east entry",
        "quest complete");

    addExit("north",
        "/areas/tol-dhurath/temple-interior/12x3.c");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/pedestal-1x1.c",
        "entered room");
    addExit("south",
        "/areas/tol-dhurath/temple-interior/pedestal-1x1.c",
        "uhrdalen left");
    addExit("east",
        "/areas/tol-dhurath/temple-interior/chamber-of-kings.c",
        "quest complete");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");
}
