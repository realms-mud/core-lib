//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pyromaniac's Focus");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "obsessive focus on fire magic, significantly enhancing the "
        "effectiveness of debilitating flame effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 29
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/divine-fire-potency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Heat Metal": 25,
        "Flame Lash": 25,
        "Incinerate": 25,
        "Consuming Flames": 25,
        "Blazing Wrath": 25,
        "Soulfire": 25,
        "Purging Flames": 25,
        "Celestial Inferno": 25
    ]));
    addSpecification("affected research type", "percentage");
}
