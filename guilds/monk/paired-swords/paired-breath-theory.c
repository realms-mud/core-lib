//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Paired Breath Theory", "Coordinate blade pressure "
        "with the opponent's concentration: adds three to Breath Shear's "
        "spell-point drain.", 15, "breath-shear", "paired-swords",
        "Breath Shear", "bonus", 3);
}
