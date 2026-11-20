//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-east passage");
    setShortDescription("The stalactite choke");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addExit("north", "/areas/evenholt/limestone-caves/1x0.c");
    addExit("east", "/areas/evenholt/limestone-caves/2x1.c");
}
