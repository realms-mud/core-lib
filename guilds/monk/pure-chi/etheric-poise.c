//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Etheric Poise", "Keep your internal current from "
        "resonating with hostile energy, granting two energy resistance.",
        20, 2, "/guilds/monk/pure-chi/resonance-theory.c", ([]));
    addSpecification("bonus resist energy", 2);
}
