//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("Lord Gunther Hrondil receives visitors in "
        "the keep's hall.");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addExit("west", "/areas/hrondil/keep-interior/0x0.c");
    addExit("east", "/areas/hrondil/keep-interior/2x0.c");
    addObject("/areas/hrondil/characters/gunther-hrondil.c");
}
