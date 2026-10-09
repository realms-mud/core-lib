//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the "
        "Spell Ward defensive ward, providing substantial magical and "
            "physical protection.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/arcane-shield.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 15);
    addSpecification("cooldown", 60);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus defense", 3);

    addSpecification("command template", "spell ward");
    addSpecification("use ability activate message", "A Spell Ward "
        "materializes around ##InitiatorName##.");
    addSpecification(
        "use ability deactivate message",
        "The Spell Ward fades.");
}
