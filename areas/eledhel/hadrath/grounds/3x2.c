//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

public void Setup()
{
    setTerrain("/lib/environment/terrain/plains.c");
    setShortDescription("The watch barracks yard");
    addDecorator("village square");
    addItem("/lib/environment/items/lighting/lit-torch.c", "north");
    addExit("west", "/areas/eledhel/hadrath/grounds/2x2.c");
    addExit("north", "/areas/eledhel/hadrath/grounds/3x1.c");
}
