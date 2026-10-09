//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Protection");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the "
        "Absolute Protection defensive ward, providing substantial magical "
            "and physical protection.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/immortal-aegis.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 63
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 220);
    addSpecification("stamina point cost", 110);
    addSpecification("cooldown", 60);
    addSpecification("bonus defense", 30);
    addSpecification("bonus resist magical", 25);

    addSpecification("command template", "absolute protection");
    addSpecification("use ability activate message", "A Absolute Protection "
        "materializes around ##InitiatorName##.");
    addSpecification(
        "use ability deactivate message",
        "The Absolute Protection fades.");
}
