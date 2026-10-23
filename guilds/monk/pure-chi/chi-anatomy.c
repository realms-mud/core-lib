//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Chi Anatomy", "Trace the channels that carry spell-point "
        "chi. This lesson opens precision projection and restorative work.",
        10, 1, "/guilds/monk/pure-chi/focused-pulse.c", ([]));
    addSpecification("related research", ({
        "/guilds/monk/pure-chi/needle-of-chi.c",
        "/guilds/monk/pure-chi/restorative-breath.c" }));
}
