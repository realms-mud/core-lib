//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Mastery");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research deepens the battlemage's "
        "command of shadow energy, enhancing all shadow-based blade "
            "enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/umbral-brand.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 23
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Shadow Edge": 25,
        "Umbral Brand": 25,
        "Void Blade": 25,
        "Oblivion Edge": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
