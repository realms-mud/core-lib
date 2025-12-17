//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Walker");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "ability to walk between dreams and reality with greater ease, "
        "enhancing their perception and magical recovery.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 13 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/fearsome-visage.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus senses", 3);
    addSpecification("bonus perception", 3);
    addSpecification("bonus heal spell points rate", 1);
}
