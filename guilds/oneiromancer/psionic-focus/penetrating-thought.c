//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Penetrating Thought");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to pierce through mental defenses, making their "
        "psionic attacks more difficult to resist.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 8 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/focused-intent.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Mind Spike": 15,
        "Psychic Lash": 15,
        "Thought Crush": 10,
        "Neural Sever": 10
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 2);
    addSpecification("bonus resist psionic", 3);
}
