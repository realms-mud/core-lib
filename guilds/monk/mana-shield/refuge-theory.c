//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Refuge Theory", "Separate defensive posture from "
        "absorption. Opens brief bracing and magical resistance without "
        "adding another mana-shield layer.",
        15, 2, "/guilds/monk/mana-shield/sentry-focus.c", ([]));
    addSpecification("related research", ({
        "/guilds/monk/mana-shield/brace-the-spirit.c",
        "/guilds/monk/mana-shield/refuge-posture.c" }));
}
