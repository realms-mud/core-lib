//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Greater Elven Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches an enhanced elven "
        "warding spell with stronger protection.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/elven-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 45);
    addSpecification("bonus resist magical", 8);
    addSpecification("bonus resist evil", 5);
    addSpecification("bonus resist undead", 5);
    addSpecification("command template", "greater elven ward");
    addSpecification("use ability activate message", "An enhanced elven ward "
        "flares to life around ##InitiatorName##, its runes glowing "
            "brightly.");
    addSpecification(
        "use ability deactivate message",
        "The greater elven ward fades.");
}
