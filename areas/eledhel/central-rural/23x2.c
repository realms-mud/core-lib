//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/craft-workroom.c");
    setShortDescription("The stream mill's grinding room");
    addDecorator("keep interior north entry alcove");
    addItem("/lib/environment/items/crafts/flour-sack.c", "west");
    addItem("/lib/environment/items/records/ledger-desk.c", "east");
    addItem("/lib/environment/items/lighting/window.c", "south");
    addItem("/lib/environment/items/lighting/oil-lamp.c", "east");
    addObject("/areas/eledhel/central-rural/characters/torven/torven.c");
    addExitWithDoor("north", "/areas/eledhel/central-rural/23x3.c",
        "/lib/environment/doors/plank-door.c");
}
