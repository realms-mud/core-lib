//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Annihilating Will");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of channeling their will into devastating attacks that "
        "can obliterate consciousness itself.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 32 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/mind-annihilation.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/psionic-focus/existential-insight.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Mind Annihilation": 25,
        "Soul Flense": 25,
        "Dream Eater": 20,
        "Void Thought": 15
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 3);
    addSpecification("bonus damage", 3);
}
