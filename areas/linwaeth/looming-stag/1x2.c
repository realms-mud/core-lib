//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/inn.c");
    setShortDescription("The Looming Stag's stair and guest loft");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/furniture/bed.c", "none");
    addExit("north", "/areas/linwaeth/looming-stag/1x1.c");
}
