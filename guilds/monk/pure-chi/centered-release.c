//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Centered Release", "Release energy from an unmoving "
        "center. Unified Current adds three strength to this projection.",
        20, 3, "/guilds/monk/pure-chi/resonance-theory.c", ([]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 30);
    addSpecification("command template", "chi centered release at ##Target##");
    addSpecification("use ability message",
        "A centered release of chi strikes ##TargetName## "
        "from ##InitiatorName##'s open palm.");
    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":30, "range":8 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.2 ]),
        ([ "type":"research", "name":"Unified Current",
            "research item":"/guilds/monk/pure-chi/unified-current.c",
            "base value":1, "formula":"additive", "rate":3.0 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/perfect-economy.c":2 ]));
}
