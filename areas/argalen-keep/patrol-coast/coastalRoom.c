//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
protected void setUpCoastalRoom()
{
    setTerrain("/lib/environment/terrain/rocky-shoreline.c");
    addFeature("/lib/environment/features/water/rocky-sea-shore.c",
        "east");
}

/////////////////////////////////////////////////////////////////////////////
protected void setUpCoastalFarm()
{
    setTerrain("/lib/environment/terrain/farmland.c");
}
