//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Void Mastery");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of drawing upon the absolute emptiness of the void, "
        "enhancing the most devastating psionic techniques.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 36 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/void-thought.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/psionic-focus/psychic-resonance.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/psionic-focus/annihilating-will.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Void Thought": 30,
        "Mind Annihilation": 20,
        "Dream Eater": 25,
        "Psychic Scream": 15
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 5);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus wisdom", 1);
}