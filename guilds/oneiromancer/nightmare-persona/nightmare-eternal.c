//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Eternal");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "ultimate mastery of the nightmare persona. They have become a "
        "nightmare eternal - a being of absolute terror whose power rivals "
        "the oldest horrors of the dream realm.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 67 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/primordial-fear.c",
        (["type":"research"]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/deathless-horror.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 10);
    addSpecification("bonus spirit", 8);
    addSpecification("bonus senses", 8);
    addSpecification("bonus attack", 12);
    addSpecification("bonus damage", 10);
    addSpecification("bonus spell points", 125);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus wisdom", 2);
}
