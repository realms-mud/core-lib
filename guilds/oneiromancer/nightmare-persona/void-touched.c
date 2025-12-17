//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Void Touched");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with a "
        "connection to the void between dreams, a place of absolute "
        "emptiness that amplifies their nightmare power.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 57 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/abyssal-mind.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 7);
    addSpecification("bonus spirit", 5);
    addSpecification("bonus spell points", 80);
}
