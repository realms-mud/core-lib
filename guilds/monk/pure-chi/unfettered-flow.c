//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Unfettered Flow", "Release unnecessary muscular effort "
        "while circulating chi, adding one to stamina recovery bonuses.",
        30, 3, "/guilds/monk/pure-chi/deep-recollection.c", ([]));
    addSpecification("bonus recover stamina points", 1);
}
