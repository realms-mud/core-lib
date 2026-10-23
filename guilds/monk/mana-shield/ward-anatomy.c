//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Ward Anatomy", "Study how Mindful Ward diverts damage "
        "into spell points. Opens guarded recovery and watchful defenses "
        "without changing the ward's absorption ratio or reservation.",
        10, 1, "/guilds/monk/mana-shield/mindful-ward.c", ([]));
    addSpecification("related research", ({
        "/guilds/monk/mana-shield/ward-mending.c",
        "/guilds/monk/mana-shield/sentry-focus.c" }));
}
