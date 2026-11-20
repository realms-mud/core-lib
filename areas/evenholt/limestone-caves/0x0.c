//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-east passage");
    setShortDescription("The hidden shaft and cold entry chamber");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addFeature("/lib/environment/features/water/ravine-creek.c", "south");
    addExit("up", "/areas/evenholt/grounds/20x0.c");
    addExit("east", "/areas/evenholt/limestone-caves/1x0.c");
}
