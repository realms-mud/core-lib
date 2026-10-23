//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Ward Triage", "Read which wounds most urgently need "
        "chi. Sheltering Touch gains three healing through its research "
        "modifier and becomes available for study.",
        20, 2, "/guilds/monk/mana-shield/ward-mending.c", ([]));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([ "Sheltering Touch":3 ]));
}
