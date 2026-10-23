//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Spirit Anchor", "Keep your inner identity steady when "
        "foreign magic intrudes, granting three magical resistance.",
        30, 3, "/guilds/monk/pure-chi/etheric-poise.c", ([]));
    addSpecification("bonus resist magical", 3);
}
