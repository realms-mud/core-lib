//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Paired Breath Economy", "Reduce Breath Shear's "
        "authored stamina cost by two.", 20, "breath-shear",
        "paired-swords", "Breath Shear", "decrease cost", 2);
}
