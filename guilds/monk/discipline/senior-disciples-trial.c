//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/mastery-trial.h"

protected void Setup()
{
    monkMasteryTrial("Senior Disciple's Trial", 20, 20, "adepts-focus", ({
        ({ "unarmed", "sapping-palm", "meridian-lore" }),
        ({ "katana", "rising-cut", "rising-lines" }),
        ({ "bludgeon", "sweeping-arc", "staff-economy" }),
        ({ "bludgeon", "compact-blow", "mace-recovery" }),
        ({ "bludgeon", "falling-head", "hammer-return" }),
        ({ "pure-chi", "driving-wave", "pulse-cadence" }),
        ({ "paired-swords", "crossing-cut", "crossing-lines" }),
        ({ "odachi", "horizon-cut", "horizon-geometry" }),
        ({ "archery", "crosswind-shot", "crosswind-geometry" }),
        ({ "kama", "reaping-cut", "reaping-lines" }),
        ({ "claw", "crossing-rake", "crossing-talons" })
    }));
}
