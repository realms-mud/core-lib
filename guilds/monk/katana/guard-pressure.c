//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Guard Pressure", "Applying pressure efficiently adds "
        "three points to Guard Breaker's stamina drain.", 20,
        "guard-breaker", "katana", "Guard Breaker", "bonus", 3);
}
