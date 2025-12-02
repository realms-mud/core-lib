//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/domains/trading/tradingPort.c";

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
public int getItemPrice(string item)
{   
    if(item == "/lib/instances/items/books/book.c")
    {
        return 1500;
    }
    item = regreplace(item, "^.*\/([^/]+)\.c$", "\\1", 1);
    return (to_int(item[0]) - 96) * 100;
}
