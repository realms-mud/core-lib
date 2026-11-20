//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("Hador's stable and horse paddock");
    addDecorator("village stable");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("south", "/areas/eledhel/estates/hador/grounds/2x2.c");
}
