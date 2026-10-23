//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Defensive Timing", "Recover breath between impacts. "
        "Breath Conversion recovers four seconds sooner and Brace the "
        "Spirit six seconds sooner.",
        15, 2, "/guilds/monk/mana-shield/recovery-cycle.c", ([]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Breath Conversion":4,
        "Brace the Spirit":6 ]));
}
