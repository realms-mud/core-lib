//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Conservation of Motion", "Let intent finish the motion "
        "rather than spend more force. Sheltering Touch and Stillpoint "
        "Rebuke each cost two fewer spell points.",
        30, 3, "/guilds/monk/mana-shield/economical-refuge.c", ([]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Sheltering Touch":2,
        "Stillpoint Rebuke":2 ]));
}
