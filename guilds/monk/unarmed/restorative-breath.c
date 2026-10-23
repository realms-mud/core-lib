//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Restorative Breath", "Guiding breath through recovery "
        "adds three points to Centering Breath's healing.", 15,
        "centering-breath", "unarmed", "Centering Breath", "bonus", 3);
}
