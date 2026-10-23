//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/mastery-trial.h"

protected void Setup()
{
    monkMasteryTrial("Master Candidate's Trial", 25, 30,
        "inner-discipline", ({
        ({ "unarmed", "hammer-fist", "fist-compression" }),
        ({ "katana", "drawn-circle", "circular-mechanics" }),
        ({ "bludgeon", "draining-impact", "leverage-study" }),
        ({ "pure-chi", "piercing-intent", "resonance-theory" }),
        ({ "paired-swords", "opening-cut", "opening-geometry" }),
        ({ "odachi", "descending-arc", "longblade-descent-theory" }),
        ({ "archery", "descending-shot", "falling-trajectory" }),
        ({ "kama", "crescent-reap", "crescent-geometry" }),
        ({ "claw", "rising-talon", "rising-talon-theory" })
    }));
}
