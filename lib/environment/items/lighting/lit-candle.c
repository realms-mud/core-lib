//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lit candle");
    displayName("candle");
    addAlias("candle");

    addDescriptionTemplate("an unlit candle");
    addActiveSourceOfLight(8, "a lit candle", 1);
}
