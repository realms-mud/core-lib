//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "east");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "west");
    addObject("/guilds/monk/teachers/lian.c");
    addObject("/guilds/monk/teachers/ren.c");
    addObject("/guilds/monk/teachers/sora.c");
    addObject("/guilds/monk/teachers/iori.c");
    addExit("out", "/areas/eledhel/southern-city/11x5.c");
}
