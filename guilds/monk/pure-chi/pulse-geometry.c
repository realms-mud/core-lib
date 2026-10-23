//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Pulse Geometry", "Align a narrow energy front with the "
        "target. Needle of Chi gains two points of projection strength.",
        10, 1, "/guilds/monk/pure-chi/chi-anatomy.c", ([]));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([ "Needle of Chi":2 ]));
}
