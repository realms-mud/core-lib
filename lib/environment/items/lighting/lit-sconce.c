//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("lit sconce");
    displayName("sconce");
    addAlias("sconce");

    addDescriptionTemplate("an unlit sconce");
    addActiveSourceOfLight(8, "a lit sconce", 1);
}
