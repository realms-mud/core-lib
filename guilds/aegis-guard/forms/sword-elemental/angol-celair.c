//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Angol Celair");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with "
        "mystic knowledge that enhances elemental magical attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 25
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-elemental/angol-anwar.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ambar": 15,
        "Naurtho": 15,
        "Heleg": 15,
        "Glauro": 15,
        "Geilo": 15,
        "Alagos": 15,
        "Lhorn": 15,
        "Gwaeren": 15,
        "Luithia": 15,
        "Gonatsai": 15,
        "Lhacha": 15
    ]));
    addSpecification("affected research type", "percentage");
}
