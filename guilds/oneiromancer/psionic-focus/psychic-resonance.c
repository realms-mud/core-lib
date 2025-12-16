//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psychic Resonance");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating resonant psychic frequencies that amplify "
        "area attacks and enhance mental devastation.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 28 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/psychic-scream.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/psionic-focus/cognitive-mastery.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Psychic Scream": 25,
        "Soul Flense": 20,
        "Nightmare Fist": 15,
        "Mind Annihilation": 10
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spellcraft", 3);
    addSpecification("bonus magical essence", 2);
}
