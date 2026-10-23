//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Sheltering Touch", "While your own ward is active, "
        "guide chi into another person's injuries. This heals health "
        "without granting the target a mana shield.",
        20, 3, "/guilds/monk/mana-shield/ward-triage.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 16);
    addSpecification("cooldown", 36);
    addSpecification("command template", "chi sheltering touch on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## guide##InitiatorReflexive## a sheltering "
        "touch of chi into ##TargetName##'s wounds.");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":20, "range":6 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.2 ]),
        ([ "type":"research", "name":"Ward Triage",
            "research item":"/guilds/monk/mana-shield/ward-triage.c",
            "base value":1, "formula":"additive", "rate":3.0 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/mana-shield/conservation-of-motion.c":2 ]));
}
