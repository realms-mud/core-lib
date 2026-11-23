//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The old road fades beside the mill lane");
    addDecorator("village tree");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addItem("/lib/environment/items/objects/milestone.c", "west");
    addExit("east", "/areas/eledhel/dhorlen/1x2.c");
}
