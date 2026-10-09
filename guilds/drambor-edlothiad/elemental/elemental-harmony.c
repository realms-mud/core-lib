//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Harmony");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research provides a deeper "
        "understanding  of how all elements relate, universally boosting "
            "elemental blade enchantments.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/elemental/channeling-efficiency.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 17
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Flame Edge": 15,
        "Searing Brand": 15,
        "Frost Edge": 15,
        "Glacial Brand": 15,
        "Shock Edge": 15,
        "Voltaic Brand": 15,
        "Acid Edge": 15,
        "Caustic Brand": 15,
        "Energy Edge": 15,
        "Force Brand": 15,
        "Shadow Edge": 15,
        "Umbral Brand": 15,
        "Arcane Edge": 15,
        "Mystic Brand": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
