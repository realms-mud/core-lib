//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/training-fortress.c");
    setShortDescription("The Aegis Academy's drill floor");
    addItem("/lib/environment/items/military/training-dummy.c", "north");
    addItem("/lib/environment/items/military/weapon-rack.c", "east");
    addObject("/areas/eledhel/central-city/characters/aegis-cadet.c");
    addExit("east", "/areas/eledhel/central-city/aegis-academy/1x0.c");
    addExit("south", "/areas/eledhel/central-city/aegis-academy/0x1.c");
}
