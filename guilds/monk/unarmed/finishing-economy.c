//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Finishing Economy", "Eliminating wasted movement reduces "
        "Empty Hand's authored stamina cost by two.", 30,
        "empty-hand-theory", "unarmed", "Empty Hand", "decrease cost", 2);
}
