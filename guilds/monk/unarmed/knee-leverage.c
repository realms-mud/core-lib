//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Knee Leverage", "Understanding leverage adds three points "
        "to Disrupting Knee's stamina drain.", 10, "disrupting-knee",
        "unarmed", "Disrupting Knee", "bonus", 3);
}
