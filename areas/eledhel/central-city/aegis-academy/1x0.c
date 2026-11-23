//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/training-fortress.c");
    setShortDescription("The Aegis Academy's weapons room");
    addItem("/lib/environment/items/military/weapon-rack.c", "north");
    addItem("/lib/environment/items/furniture/bench.c", "west");
    addExit("west", "/areas/eledhel/central-city/aegis-academy/0x0.c");
}
