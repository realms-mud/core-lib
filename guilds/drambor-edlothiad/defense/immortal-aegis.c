//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Immortal Aegis");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the "
        "Immortal Aegis defensive ward, providing substantial magical and "
            "physical protection.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/invulnerability.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 170);
    addSpecification("stamina point cost", 85);
    addSpecification("cooldown", 60);
    addSpecification("bonus defense", 25);
    addSpecification("bonus resist magical", 22);

    addSpecification("command template", "immortal aegis");
    addSpecification("use ability activate message", "A Immortal Aegis "
        "materializes around ##InitiatorName##.");
    addSpecification(
        "use ability deactivate message",
        "The Immortal Aegis fades.");
}
