//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Brand");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "sustain a pure magical enchantment on their blade, each strike "
        "resonating with raw arcane power.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/arcane-edge.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 9
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
    addSpecification("bonus magical enchantment", 5);
    addSpecification("bonus magical attack", 5);

    addSpecification("command template", "mystic brand");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade pulses with enigmatic arcane energies, the mystic brand humming with power.");
    addSpecification("use ability deactivate message", "The mystic brand "
        "fades from ##InitiatorPossessive## blade.");
}
