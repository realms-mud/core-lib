//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setStateMachine("/areas/argalen-keep/state-machine/argalen-keep-quest.c");

    setInterior("/lib/environment/interiors/courtyard.c");
    addItem("/lib/environment/items/furniture/bench.c", "north");
    addDecorator("keep interior floor");
    addObject("/areas/argalen-keep/characters/galadhel/galadhel.c");
    addObject("/areas/argalen-keep/characters/halgaladh/halgaladh.c");

    addExit("south",
        "/areas/argalen-keep/keep-interior/5x0.c");
    addExit("north",
        "/areas/argalen-keep/keep-interior/5x2.c");
    addExit("west",
        "/areas/argalen-keep/keep-interior/4x1.c");
    addExit("east",
        "/areas/argalen-keep/keep-interior/6x1.c");
}
