//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialTheory("Grappling Mechanics", "Efficient leverage adds three "
        "points to Crushing Embrace's stamina drain, without immobilizing "
        "the opponent.", 20, "crushing-embrace", "unarmed",
        "Crushing Embrace", "bonus", 3);
}
