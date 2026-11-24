//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/crypt.c");
    addItem("/lib/environment/items/objects/stone-pile.c", "west");
    addItem("/lib/environment/items/lighting/torch.c", "east");
    addExit("up",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/opened-mound.c");
    addExit("down",
        "/areas/northern-road/upper-northern-wilds/barrow-ridge/burial-chamber.c");
}
