//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Measured Expenditure", "Match expenditure to the body's "
        "actual need. Restorative Chi Breath and Returning Current each save "
        "one spell point through their cost modifiers.",
        15, 2, "/guilds/monk/pure-chi/economical-breath.c", ([]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Restorative Chi Breath":1,
        "Returning Current":1 ]));
}
