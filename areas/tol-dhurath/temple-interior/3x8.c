//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/tol-dhurath/state-machine/tol-dhurath-quest.c");

    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior-to-exterior north-south hallway west exit");

    addExit("east", "/areas/tol-dhurath/temple-interior/4x8.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/3x9.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/3x7.c");
}
