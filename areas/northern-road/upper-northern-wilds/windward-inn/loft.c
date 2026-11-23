//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/bedroom.c");
    addItem("/lib/environment/items/furniture/bed.c", "north");
    addItem("/lib/environment/items/furniture/bed.c", "south");
    addItem("/lib/environment/items/furniture/chest.c", "east");

    addExit("east", "/areas/northern-road/upper-northern-wilds/windward-inn/common-room.c");
}
