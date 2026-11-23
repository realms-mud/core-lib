//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The entry hall of Erator Keep");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addExit("west", "/areas/eledhel/estates/erator/grounds/2x1.c");
    addExit("east", "/areas/eledhel/estates/erator/keep-interior/1x0.c");
}
