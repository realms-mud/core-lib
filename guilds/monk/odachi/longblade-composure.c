//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Composure", "Keep the body controlled "
        "under the odachi's momentum: +1 constitution.", 25, 3,
        "longblade-guard", "odachi");
    addSpecification("bonus constitution", 1);
}
