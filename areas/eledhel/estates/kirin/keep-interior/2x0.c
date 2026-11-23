//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addObject("/areas/eledhel/estates/kirin/characters/haldor.c");
    addObject("/areas/eledhel/estates/kirin/characters/aeryn.c");

    addDecorator("keep interior floor");

    addExit("west", "/areas/eledhel/estates/kirin/keep-interior/1x0.c");
}
