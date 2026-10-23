//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Inward Listening", "Notice disruptions in breath and "
        "posture before they become visible, improving perception by two.",
        20, 2, "/guilds/monk/pure-chi/contemplative-focus.c", ([]));
    addSpecification("bonus perception", 2);
}
