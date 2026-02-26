//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/keep.c");
    addFeature("/lib/environment/features/landforms/hill.c", "north");
    addItem("/lib/environment/items/lighting/lit-torch.c", "east");
    addItem("/lib/environment/items/lighting/lit-torch.c", "west");

    addDecorator("village keep gate");

    addExit("south", "/areas/argalen-keep/surrounding/12x7.c");
    addExit("north",
        "/areas/argalen-keep/keep-interior/5x0.c");
}
