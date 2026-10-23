//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Anchored Haft", "Anchor the war hammer's haft in a "
        "controlled grip, granting two hammer skill while a war hammer "
        "with the hammer type occupies the primary slot.", 10, 2,
        "/guilds/monk/bludgeon/hammer-counterweight.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("bonus hammer", 2);
}
