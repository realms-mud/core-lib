//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior east-west hallway");
    setShortDescription("A short tunnel enters the keep beneath the hill");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/eledhel/vargath-keep/canyon/4x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/keep-interior/1x2.c");
}
