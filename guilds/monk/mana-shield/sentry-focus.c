//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Sentry Focus", "Reserve six maximum stamina for "
        "watchful defense. Gain two defense; this is not another ward.",
        10, 2, "/guilds/monk/mana-shield/ward-anatomy.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("stamina point cost", 6);
    addSpecification("cooldown", 6);
    addSpecification("bonus defense", 2);
    addSpecification("command template", "chi sentry focus");
    addSpecification("use ability activate message",
        "##InitiatorName## settle##InitiatorReflexive## into a sentry's watch.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## release##InitiatorReflexive## the sentry's watch.");
}
