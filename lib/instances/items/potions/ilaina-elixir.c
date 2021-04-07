//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/potion.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Ilaina's Elixir");
    set("short", "Ilaina's Elixir");
    set("aliases", ({ "elixir", "potion", "ilaina's elixir" }));
    set("blueprint", "ilaina's elixir");
}
