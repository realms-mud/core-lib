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

    setInterior("/lib/environment/interiors/ruin-gatehouse.c");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");

    addExitWithDoor("north",
        "/areas/tol-dhurath/temple-interior/7x4.c",
        "/lib/environment/doors/portcullis.c");
    addExitWithDoor("south", 
        "/areas/tol-dhurath/temple-exterior/6x7.c",
        "/lib/environment/doors/keep-gate.c");

    addDecorator("ruined interior south gatehouse");
}
