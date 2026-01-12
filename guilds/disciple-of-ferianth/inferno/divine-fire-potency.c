//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Fire Potency");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "advanced knowledge of divine fire, greatly enhancing the power of "
        "all inferno abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 21
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/inferno-potency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Flame Touch": 25,
        "Fire Bolt": 25,
        "Burning Hands": 25,
        "Fireball": 25,
        "Pillar of Fire": 25,
        "Flame Strike": 25,
        "Fire Storm": 25,
        "Immolation": 25,
        "Hellfire": 25,
        "Infernal Blast": 25
    ]));
    addSpecification("affected research type", "percentage");
}
