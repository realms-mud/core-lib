//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Supreme Nightmare");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "ultimate nightmare persona. They have become the supreme nightmare, "
        "a being of terror and power whose very existence warps the boundary "
        "between dreams and reality.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 51 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/dream-tyrant.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 8);
    addSpecification("bonus spirit", 5);
    addSpecification("bonus senses", 5);
    addSpecification("bonus psionic attack", 25);
    addSpecification("bonus attack", 8);
    addSpecification("bonus damage", 6);
    addSpecification("bonus spell points", 100);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus wisdom", 1);
}
