//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Ward Mending", "Spend spell points to mend injuries "
        "while the existing ward remains active. This replenishes health, "
        "not a separate shield or absorption reserve.",
        10, 2, "/guilds/monk/mana-shield/ward-anatomy.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 30);
    addSpecification("command template", "chi ward mending");
    addSpecification("use ability message",
        "##InitiatorName## mend##InitiatorReflexive## wounds "
        "beneath the quiet ward.");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":12, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.15 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/guarded-breath.c":1 ]));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/renewing-rhythm.c":4 ]));
}
