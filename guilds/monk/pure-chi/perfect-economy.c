//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Perfect Economy", "End a major circulation precisely "
        "when its work is done. Heart Mending and Centered Release each "
        "cost two fewer spell points.",
        30, 3, "/guilds/monk/pure-chi/channel-economy.c", ([]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Heart Mending":2,
        "Centered Release":2 ]));
}
