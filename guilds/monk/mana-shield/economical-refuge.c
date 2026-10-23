//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Economical Refuge", "Use posture before force. Brace "
        "the Spirit saves one spell point and Measured Renewal saves "
        "two stamina through their own cost modifiers.",
        15, 2, "/guilds/monk/mana-shield/guarded-breath.c", ([]));
    addSpecification("affected research type", "decrease cost");
    addSpecification("affected research", ([
        "Brace the Spirit":1,
        "Measured Renewal":2 ]));
}
