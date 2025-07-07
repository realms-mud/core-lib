//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    setShortDescription("a mock trading port");
    setAdditionalLongDescription("This is a mock trading port for testing purposes. It is "
        "specifically designed to BE a port with all trading facilities.");
}

/////////////////////////////////////////////////////////////////////////////
public int isPort()
{
    return 1; // This IS a port
}

/////////////////////////////////////////////////////////////////////////////
public string getPortName()
{
    return "Mock Trading Port";
}

/////////////////////////////////////////////////////////////////////////////
public int getItemPrice(string item)
{
    return 100; // Default price for testing
}
