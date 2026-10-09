//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Barrier");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the "
        "Mystic Barrier defensive ward, providing substantial magical and "
            "physical protection.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/spell-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 9
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 25);
    addSpecification("cooldown", 60);
    addSpecification("bonus defense", 8);
    addSpecification("bonus resist magical", 6);

    addSpecification("command template", "mystic barrier");
    addSpecification("use ability activate message", "A Mystic Barrier "
        "materializes around ##InitiatorName##.");
    addSpecification(
        "use ability deactivate message",
        "The Mystic Barrier fades.");
}
