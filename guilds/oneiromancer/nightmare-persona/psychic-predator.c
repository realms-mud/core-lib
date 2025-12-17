//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psychic Predator");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "instincts of a psychic predator, able to sense weakness and strike "
        "with devastating precision.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 21 ]));

    addPrerequisite("/guilds/oneiromancer/nightmare-persona/mind-shield.c",
        (["type":"research"]));

    addSpecification("limited by", (["research active":
        "/guilds/oneiromancer/nightmare-persona/persona-root.c"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 4);
    addSpecification("bonus senses", 3);
    addSpecification("bonus psionic attack", 25);
}
