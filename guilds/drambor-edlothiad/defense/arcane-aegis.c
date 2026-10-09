//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Aegis");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the "
        "Arcane Aegis defensive ward, providing substantial magical and "
            "physical protection.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/mystic-barrier.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 17
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 60);
    addSpecification("bonus defense", 12);
    addSpecification("bonus resist magical", 10);

    addSpecification("command template", "arcane aegis");
    addSpecification("use ability activate message", "A Arcane Aegis "
        "materializes around ##InitiatorName##.");
    addSpecification(
        "use ability deactivate message",
        "The Arcane Aegis fades.");
}
