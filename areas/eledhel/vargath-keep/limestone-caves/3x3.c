//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/cave.c");
    addDecorator("cave north-east passage");
    setShortDescription("A curtain of flowstone hides a narrow crawl");
    addFeature("/lib/environment/features/landforms/crag.c", "east");
    addExit("north", "/areas/eledhel/vargath-keep/limestone-caves/3x2.c");
    addExit("east", "/areas/eledhel/vargath-keep/limestone-caves/4x3.c");
}
