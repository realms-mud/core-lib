//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Sentinel Meditation", "Reserve ten maximum stamina to "
        "gain three defense, sacrificing two weapon attack and spending "
        "one spell point per received hit. No absorption layer is added.",
        30, 4, "/guilds/monk/mana-shield/elastic-defense.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 10);
    addSpecification("bonus defense", 3);
    addSpecification("penalty to weapon attack", 2);
    addSpecification("per hit received cost", ([ "spell points":1 ]));
    addSpecification("command template", "chi sentinel meditation");
    addSpecification("use ability activate message",
        "##InitiatorName## enter##InitiatorReflexive## sentinel meditation.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## end##InitiatorReflexive## sentinel meditation.");
}
