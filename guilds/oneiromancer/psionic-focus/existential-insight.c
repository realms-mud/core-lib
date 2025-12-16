//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Existential Insight");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of exploiting existential fears and the terror of "
        "meaninglessness in their attacks.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 24 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/existential-dread.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/psionic-focus/nightmare-affinity.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Existential Dread": 25,
        "Perception Warp": 20,
        "Nightmare Fist": 20,
        "Psychic Scream": 15
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus senses", 3);
    addSpecification("bonus wisdom", 1);
}
