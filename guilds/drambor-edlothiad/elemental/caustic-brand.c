//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Caustic Brand");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "sustain a potent acid enchantment, their blade continuously "
        "weeping caustic fluid that dissolves defenses.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/acid-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 60);
    addSpecification("bonus acid enchantment", 5);
    addSpecification("bonus acid attack", 5);

    addSpecification("command template", "caustic brand");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade weeps with virulent acid, the caustic brand hissing against the air.");
    addSpecification("use ability deactivate message", "The caustic brand "
        "dries from ##InitiatorPossessive## blade.");
}
