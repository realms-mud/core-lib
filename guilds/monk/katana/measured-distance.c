//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Measured Distance", "Reading an opponent's approach "
        "grants +1 dodge with a primary katana; it adds no reach mechanic.",
        15, 2, "blade-awareness", "katana");
    addSpecification("bonus dodge", 1);
}
