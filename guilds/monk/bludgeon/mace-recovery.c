//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Mace Recovery", "Recover the heavy head through a short "
        "circle. Compact Blow, Taxing Contact, and Centerline Crush each "
        "cost one less stamina with a mace-school primary.", 15, 2,
        "/guilds/monk/bludgeon/compact-blow.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Compact Blow":1,
        "Taxing Contact":1,
        "Centerline Crush":1
    ]));
}
