//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("candelabra");

    addAlias("candleholder");
    addAlias("candle holder");

    addDescriptionTemplate("an ornate metal candelabra with several unlit candles");

    // Candelabras provide more light than single candles or torches
    addActiveSourceOfLight(10, "an ornate metal candelabra with several "
        "lit candles casting a warm, flickering light", 1);
}
