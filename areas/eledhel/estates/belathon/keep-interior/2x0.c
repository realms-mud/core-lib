//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/study.c");
    setShortDescription("A private study overlooking the outer ward.");
    addFeature("/lib/environment/features/floors/stone-floor.c");
    addDecorator("keep interior floor");
    addExit("west",
        "/areas/eledhel/estates/belathon/keep-interior/1x0.c");
}
