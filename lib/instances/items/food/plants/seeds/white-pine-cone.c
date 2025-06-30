//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "White Pine Cone");
    set("short", "White Pine Cone");
    set("aliases", ({ "white pine cone", "cone", "pinecone", "conifer cone", "pine cone" }));
    set("blueprint", "white pine cone");
}
