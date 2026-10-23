//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Heavy Leverage", "Study the effort needed to resist "
        "the odachi's hilt: adds three to Pommel Drive's stamina drain.",
        10, "pommel-drive", "odachi", "Pommel Drive", "bonus", 3);
}
