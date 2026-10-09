//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Voltaic Brand");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "sustain a powerful electrical enchantment, wreathing their blade "
        "in continuous arcs of voltaic energy.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/shock-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 7
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 60);
    addSpecification("bonus electricity enchantment", 5);
    addSpecification("bonus electricity attack", 5);

    addSpecification("command template", "voltaic brand");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade crackles with arcing electricity, the voltaic brand discharging sparks.");
    addSpecification("use ability deactivate message", "The voltaic brand "
        "dissipates from ##InitiatorPossessive## blade.");
}
