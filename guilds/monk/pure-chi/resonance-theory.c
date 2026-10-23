//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Resonance Theory", "Distinguish the body's rhythm from "
        "the rhythm of its energy. Opens attacks on an opponent's reserves.",
        20, 2, "/guilds/monk/pure-chi/driving-wave.c", ([]));
    addSpecification("related research", ({
        "/guilds/monk/pure-chi/piercing-intent.c",
        "/guilds/monk/pure-chi/centered-release.c" }));
}
