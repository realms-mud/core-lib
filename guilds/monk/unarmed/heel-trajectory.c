//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Heel Trajectory", "Studying the rising arc adds three "
        "points to Rising Heel's damage formula.", 15, "rising-heel",
        "unarmed", "Rising Heel", "bonus", 3);
}
