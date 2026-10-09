//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Umbral Brand");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "sustain a shadow enchantment on their blade, cloaking it in "
        "darkness that saps the strength of those it strikes.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/shadow-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 15
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 60);
    addSpecification("bonus shadow enchantment", 5);
    addSpecification("bonus shadow attack", 5);

    addSpecification("command template", "umbral brand");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade drinks in surrounding light, cloaked in writhing shadow.");
    addSpecification("use ability deactivate message", "The umbral brand "
        "recedes from ##InitiatorPossessive## blade.");
}
