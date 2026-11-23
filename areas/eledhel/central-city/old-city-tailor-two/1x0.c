//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setInterior("/lib/environment/interiors/workshop.c");
    setShortDescription("A private fitting room with a full-length mirror");
    addItem("/lib/environment/items/furniture/mirror.c", "north");
    addItem("/lib/environment/items/furniture/chair.c", "west");
    addExit("west",
        "/areas/eledhel/central-city/old-city-tailor-two/0x0.c");
}
