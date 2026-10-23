//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Guarded Ward Breath", "Keep attention on the ward while "
        "repairing wounds. Ward Mending costs one fewer spell point.",
        10, 1, "/guilds/monk/mana-shield/ward-anatomy.c", ([]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([ "Ward Mending":1 ]));
}
