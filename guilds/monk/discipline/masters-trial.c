//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/mastery-trial.h"

protected void Setup()
{
    monkMasteryTrial("Master's Trial", 30, 40,
        "mastery-of-fundamentals", ({
        ({ "unarmed", "empty-hand", "empty-hand-theory" }),
        ({ "katana", "decisive-cut", "decisive-angle" }),
        ({ "bludgeon", "pressing-shaft", "long-reach-geometry" }),
        ({ "bludgeon", "taxing-contact", "contact-geometry" }),
        ({ "bludgeon", "burdening-blow", "anvil-geometry" }),
        ({ "pure-chi", "centered-release", "resonance-theory" }),
        ({ "paired-swords", "returning-cut", "paired-return-rhythm" }),
        ({ "odachi", "returning-arc", "longblade-return-theory" }),
        ({ "archery", "returning-shot", "return-trajectory" }),
        ({ "kama", "returning-hook", "hook-return-theory" }),
        ({ "claw", "returning-rake", "rake-return-theory" })
    }));
}
