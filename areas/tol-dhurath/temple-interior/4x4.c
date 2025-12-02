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

    setTerrain("/lib/environment/terrain/ruin-exterior.c");
    addDecorator("ruined interior courtyard");

    addExit("east", "/areas/tol-dhurath/temple-interior/5x4.c");
    addExit("north", "/areas/tol-dhurath/temple-interior/4x5.c");
}
