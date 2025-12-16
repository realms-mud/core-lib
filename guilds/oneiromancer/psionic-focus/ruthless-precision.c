//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ruthless Precision");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of striking at the most vulnerable points of the psyche, "
        "enhancing attacks that target specific mental faculties.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "oneiromancer",
          "value": 12 ]));

    addPrerequisite("/guilds/oneiromancer/psionic-focus/neural-sever.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Neural Sever": 15,
        "Ego Rend": 15,
        "Dream Fang": 10
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus senses", 2);
    addSpecification("bonus spellcraft", 2);
}
