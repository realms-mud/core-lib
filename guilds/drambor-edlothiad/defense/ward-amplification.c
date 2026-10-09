//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ward Amplification");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research enhances all "
        "defensive ward abilities.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/defense/spell-resistance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 11
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spell Ward": 25, "Mystic Barrier": 25, "Arcane Aegis": 25,
        "Shield of Ages": 25, "Invulnerability": 25, "Immortal Aegis": 25,
        "Absolute Protection": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
