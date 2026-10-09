//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Warrior Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research enhances all "
        "arcane warrior combat abilities.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/arcane/enhanced-reflexes.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 31
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arcane Haste": 25, "Combat Focus": 25, "Whirlwind Stance": 25,
        "Lightning Reflexes": 25, "Arcane Fury": 25, "Storm Dancer": 25,
        "Avatar of War": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
