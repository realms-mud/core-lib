//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Brace the Spirit", "While warded, spend chi for twelve "
        "seconds of braced defense. The brief posture grants three defense "
        "and does not absorb damage itself.",
        15, 3, "/guilds/monk/mana-shield/refuge-theory.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 40);
    addSpecification("duration", 12);
    addSpecification("bonus defense", 3);
    addSpecification("command template", "chi brace the spirit");
    addSpecification("use ability message",
        "##InitiatorName## brace##InitiatorReflexive## beneath the ward.");
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/economical-refuge.c":1 ]));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/defensive-timing.c":6 ]));
}
