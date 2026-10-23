//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Rake Economy", "Avoid wasted tension in a short "
        "thrust: Measured Rake costs two less stamina.",
        15, "rake-geometry", "claw", "Measured Rake", "decrease cost", 2);
}
