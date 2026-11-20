//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest-clearing.c");
    setShortDescription("The orchard's woodland edge");
    addDecorator("farm track T-east");
    addFeature("/lib/environment/features/trees/hazel-stand.c", "west");
    addFeature("/lib/environment/features/plants/blackberry-bramble.c",
        "east");
    addItem("/lib/environment/items/objects/boundary-stone.c", "south");
    addExit("south", "/areas/eledhel/central-rural/21x5.c");
    addExit("east", "/areas/eledhel/central-rural/22x6.c");
    addExit("north", "/areas/eledhel/central-rural/21x7.c");
}
