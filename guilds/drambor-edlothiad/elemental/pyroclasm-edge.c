//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pyroclasm Edge");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the pinnacle of "
        " fire blade mastery. The battlemage sustains a devastating volcanic "
        "enchantment that turns their blade into a weapon of cataclysmic "
            "fire.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/blazing-vortex.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 45
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "two-handed sword", "short sword",
        "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 50);
    addSpecification("cooldown", 90);

    addSpecification("bonus fire enchantment", 15);
    addSpecification("bonus fire attack", 15);
    addSpecification("bonus damage", 8);

    addSpecification("command template", "pyroclasm edge");
    addSpecification("use ability activate message",
        "##InitiatorPossessive::Name## blade ignites with volcanic fury, superheated stone and flame cascading along its length.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## ##Infinitive::quench## the pyroclasm enchantment, the volcanic fury subsiding.");
}
