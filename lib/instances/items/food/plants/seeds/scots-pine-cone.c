//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Scots Pine Cone");
    set("short", "Scots Pine Cone");
    set("aliases", ({ "scots pine cone", "cone", "pinecone", "conifer cone", "pine cone" }));
    set("blueprint", "scots pine cone");
}
