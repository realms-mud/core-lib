//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Force Brand");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research allows the battlemage to "
        "sustain a concentrated force enchantment on their blade, each "
        "strike hitting with amplified arcane impact.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/energy-edge.c",
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
    addSpecification("bonus energy enchantment", 5);
    addSpecification("bonus energy attack", 5);

    addSpecification("command template", "force brand");
    addSpecification("use ability activate message",
        "Concentrated arcane force sheathes ##InitiatorPossessive## blade in a rippling corona of raw power.");
    addSpecification("use ability deactivate message", "The force brand "
        "dissipates from ##InitiatorPossessive## blade.");
}
