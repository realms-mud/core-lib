//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Singularity");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research represents the absolute "
        "apex  of elemental blade mastery. The battlemage creates a "
            "singularity of "
        "elemental force in their blade, a point where all elements converge "
        "into devastating unity.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/prismatic-blade.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 65
        ]));

    addSpecification("limited by", (["equipment": ({ "long sword",
            "hand and a half sword",
            "two-handed sword", "short sword",
            "dagger" }) ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);
    addSpecification("stamina point cost", 100);
    addSpecification("cooldown", 120);

    addSpecification("bonus fire enchantment", 8);
    addSpecification("bonus cold enchantment", 8);
    addSpecification("bonus electricity enchantment", 8);
    addSpecification("bonus energy enchantment", 8);
    addSpecification("bonus magical enchantment", 8);
    addSpecification("bonus damage", 12);
    addSpecification("bonus attack", 10);

    addSpecification("command template", "elemental singularity");
    addSpecification("use ability activate message", "All elemental forces "
        "collapse into a single point of devastating power within "
        "##InitiatorPossessive## blade - a singularity of pure destruction.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## ##Infinitive::release## the elemental singularity, the collapsed forces dissipating harmlessly.");
}
