//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Horizon Cut", "Deliver one broad odachi cut against "
        "a single opponent in the same room; this is not an area attack.",
        15, "longblade-distance", "odachi", "damage hit points",
        28, 4, 18, 22, "horizon-geometry");
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/odachi/horizon-rhythm.c":4
    ]));
}
