//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lit torch");
    displayName("torch");
    addAlias("torch");

    addDescriptionTemplate("an unlit torch");
    addActiveSourceOfLight(8, "a lit torch", 1);
}
