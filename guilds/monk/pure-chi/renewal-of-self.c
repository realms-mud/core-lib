//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Renewal of Self", "Commit a large measure of chi to "
        "restore your wounds and stamina in one long recovery cycle.",
        30, 4, "/guilds/monk/pure-chi/heart-mending.c", ([]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 90);
    addSpecification("command template", "chi renewal of self");
    addSpecification("use ability message",
        "##InitiatorName## settle##InitiatorReflexive## into renewal.");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":32, "range":8 ]) }));
    addSpecification("increase stamina points", ({
        ([ "probability":100, "base damage":18, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.2 ]) }));
}
