//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Recovery Cycle", "Trace the interval between absorbed "
        "blows. Opens stamina-to-spell-point conversion while warded.",
        10, 1, "/guilds/monk/mana-shield/ward-anatomy.c", ([]));
    addSpecification("related research", ({
        "/guilds/monk/mana-shield/breath-conversion.c",
        "/guilds/monk/mana-shield/recovery-habit.c" }));
}
