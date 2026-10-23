//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Lucid Mind", "Interrupt the habit of wasteful exertion, "
        "adding one to the existing spell-point reduction bonus.",
        30, 3, "/guilds/monk/pure-chi/perfect-economy.c", ([]));
    addSpecification("bonus reduce spell points", 1);
}
