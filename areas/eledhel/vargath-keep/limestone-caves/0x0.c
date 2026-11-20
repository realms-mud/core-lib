//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave south-east passage");
    setShortDescription("A leaf-covered shaft opens into cold limestone");
    addFeature("/lib/environment/features/landforms/crag.c", "north");
    addFeature("/lib/environment/features/water/ravine-creek.c", "east");
    addExit("up", "/areas/eledhel/vargath-keep/approach/4x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/limestone-caves/1x0.c");
}
