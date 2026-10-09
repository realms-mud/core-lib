//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elven Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches an ancient elven "
        "warding spell that provides magical protection.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/root.c",
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
    addSpecification("cooldown", 30);
    addSpecification("bonus resist magical", 5);
    addSpecification("bonus resist evil", 3);
    addSpecification("command template", "elven ward");
    addSpecification("use ability activate message", "An ancient elven ward "
        "shimmers into existence around ##InitiatorName##.");
    addSpecification(
        "use ability deactivate message",
        "The elven ward fades.");
}
