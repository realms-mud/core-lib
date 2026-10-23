//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Breath Economy", "Reducing tension lowers Centering "
        "Breath's authored stamina cost by two.", 20, "restorative-breath",
        "unarmed", "Centering Breath", "decrease cost", 2);
}
