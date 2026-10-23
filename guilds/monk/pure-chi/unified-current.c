//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Unified Current", "Reconcile force and stillness. "
        "Centered Release gains three strength; Silent Thunder gains "
        "ten percent of its base projection.",
        30, 3, "/guilds/monk/pure-chi/centered-release.c", ([]));
    addSpecification("affected research type", "bonus");
    addSpecification("affected research", ([ "Centered Release":3 ]));
}
