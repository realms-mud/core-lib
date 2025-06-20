//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("chandelier");
    addAlias("candle chandelier");
    addAlias("hanging chandelier");

    addDescriptionTemplate("an ornate chandelier hangs from the ceiling, its "
        "candles unlit");
    addActiveSourceOfLight(8, "an ornate chandelier blazes with candlelight, "
        "illuminating the room with a warm, golden glow", 1);

    addItemTemplate("the chandelier is wrought of iron and brass, adorned with "
        "curved arms and dangling crystals. Wax drips from the candleholders.");
}
