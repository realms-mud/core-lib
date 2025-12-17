//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Devourer");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "ability to devour the dreams and mental energy of others, converting "
        "it into their own power.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 29 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/ethereal-shroud.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus senses", 5);
    addSpecification("bonus heal spell points rate", 2);
    addSpecification("bonus heal hit points rate", 1);
}
