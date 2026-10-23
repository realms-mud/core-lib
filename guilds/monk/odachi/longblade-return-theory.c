//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Longblade Return Theory", "Study the odachi's "
        "returning line: adds three to Returning Arc's damage formula.",
        25, "returning-arc", "odachi", "Returning Arc", "bonus", 3);
}
