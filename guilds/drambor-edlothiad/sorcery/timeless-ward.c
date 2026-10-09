//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Timeless Ward");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "An ancient ward drawing on timeless "
        "elven protective magic.");
    addPrerequisite(
        "/guilds/drambor-edlothiad/sorcery/greater-ward.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 17
        ]));
    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 70);
    addSpecification("cooldown", 60);
    addSpecification("bonus resist magical", 10);
    addSpecification("bonus resist evil", 8);
    addSpecification("bonus resist undead", 8);
    addSpecification("bonus defense", 5);
    addSpecification("command template", "timeless ward");
    addSpecification("use ability activate message", "Ancient elven runes "
        "spiral around ##InitiatorName##, forming a timeless ward of "
            "protection.");
    addSpecification(
        "use ability deactivate message",
        "The timeless ward fades.");
}
