//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");
    setShortDescription("The outcast camp beyond the western fields");
    addDecorator("village square");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addItem("/lib/environment/items/lighting/camp-fire.c", "none");
    addExit("north", "/areas/linwaeth/11x7.c");
}
