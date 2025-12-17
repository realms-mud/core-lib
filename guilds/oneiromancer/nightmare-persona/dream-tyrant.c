//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Tyrant");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "power of a dream tyrant, one who rules over the realm of nightmares "
        "with absolute authority.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 45 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/avatar-of-nightmares.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 7);
    addSpecification("bonus senses", 5);
    addSpecification("bonus attack", 6);
    addSpecification("bonus damage", 5);
    addSpecification("bonus spell points", 75);
}
