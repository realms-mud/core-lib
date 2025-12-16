//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Focused Intent");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of how to sharpen their mental focus, increasing the "
        "effectiveness of basic psionic attacks.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 3 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/mind-spike.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Mind Spike": 10,
        "Psychic Lash": 10
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus mind", 1);
    addSpecification("bonus senses", 1);
}
