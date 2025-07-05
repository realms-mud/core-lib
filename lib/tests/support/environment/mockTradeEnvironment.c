//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("a mock testing environment");
    setAdditionalLongDescription("This is a mock environment for testing purposes. It is "
        "specifically designed to NOT be a port.");
}

/////////////////////////////////////////////////////////////////////////////
public int isPort()
{
    return 0; // This is NOT a port
}
