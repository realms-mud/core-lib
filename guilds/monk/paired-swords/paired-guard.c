//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Guard", "Keep one blade ready while the other "
        "recovers: +1 parry with the specified pair.", 10, 1,
        "companion-grip", "paired-swords");
    addSpecification("bonus parry", 1);
}
