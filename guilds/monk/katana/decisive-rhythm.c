//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Decisive Rhythm", "Recovering the finishing rhythm "
        "reduces Decisive Cut's cooldown by four seconds.", 30,
        "decisive-angle", "katana", "Decisive Cut", "decrease cooldown", 4);
}
