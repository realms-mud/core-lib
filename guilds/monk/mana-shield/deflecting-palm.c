//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Deflecting Palm", "Project a ward-guided palm of chi "
        "that exhausts an opponent's stamina instead of injuring flesh.",
        15, 3, "/guilds/monk/mana-shield/refuge-theory.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 10);
    addSpecification("cooldown", 24);
    addSpecification("command template", "chi deflecting palm at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## direct##InitiatorReflexive## a deflecting "
        "palm of chi into ##TargetName##'s stance.");
    addSpecification("damage type", "energy");
    addSpecification("damage stamina points", ({
        ([ "probability":100, "base damage":14, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.15 ]) }));
}
