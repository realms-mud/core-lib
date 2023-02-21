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
    addDecorator("ruined interior-to-exterior east-west hallway south exit");

    addExit("west", "/areas/tol-dhurath/temple-interior/5x9.c");
    addExit("east", "/areas/tol-dhurath/temple-interior/7x9.c");
    addExit("south", "/areas/tol-dhurath/temple-interior/6x8.c");
}
