//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Circulation Theory", "Study the return path of spent chi. "
        "This opens cleansing and stamina restoration without a new pool.",
        15, 2, "/guilds/monk/pure-chi/restorative-breath.c", ([]));
    addSpecification("related research", ({
        "/guilds/monk/pure-chi/cleansing-breath.c",
        "/guilds/monk/pure-chi/returning-current.c" }));
}
