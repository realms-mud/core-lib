//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Mace Head Alignment", "Study contact with a mace, flanged "
        "mace, or morning star. Opens mace instruction and shortens "
        "Compact Blow's cooldown by one second.", 10, 2,
        "/guilds/monk/bludgeon/impact-theory.c", ([
        "equipment":([
            "type":"mace",
            "blueprint":({ "mace", "flanged mace", "morning star" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([ "Compact Blow":1 ]));
}
