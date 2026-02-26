//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setTerrain("/lib/environment/terrain/keep.c");
    addDecorator("keep interior courtyard");

    addExit("west",
        "/areas/argalen-keep/keep-interior/5x1.c");
}
