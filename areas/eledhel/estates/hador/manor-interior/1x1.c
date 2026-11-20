//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior.c");
    setShortDescription("The steward's room at Hador Manor");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addObject("/areas/eledhel/estates/hador/characters/steward.c");
    addExit("east", "/areas/eledhel/estates/hador/manor-interior/2x1.c");
}
