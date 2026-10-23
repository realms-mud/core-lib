//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Impact Theory", "Study contact and recovery to shorten "
        "Measured Impact's cooldown by one second. This foundation opens "
        "the staff, mace, and war hammer schools.", 10, 2,
        "/guilds/monk/bludgeon/settled-guard.c", ([
        "equipment":([
            "type":({ "staff", "mace", "hammer" }),
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([ "Measured Impact":1 ]));
}
