//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The Endur cattle pens and hay ricks");
    addDecorator("village stable");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/eledhel/estates/endur/grounds/2x2.c");
}
