//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Searing Brand");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "sustain an intense fire enchantment on their blade, branding foes "
        "with searing heat that lingers beyond the initial strike.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/flame-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 5
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "two-handed sword", "short sword",
        "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 60);

    addSpecification("bonus fire enchantment", 5);
    addSpecification("bonus fire attack", 5);

    addSpecification("command template", "searing brand");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade erupts with searing heat, flames licking along the steel in a brand of molten fury.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## ##Infinitive::allow## the searing brand to fade, flames guttering into nothing.");
}
