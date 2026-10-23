//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Economical Breath", "Waste less chi during small "
        "projections. Needle of Chi costs one fewer spell point.",
        10, 1, "/guilds/monk/pure-chi/chi-anatomy.c", ([]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([ "Needle of Chi":1 ]));
}
