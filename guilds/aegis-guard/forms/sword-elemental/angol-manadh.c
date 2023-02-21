//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Angol Manadh");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with "
        "mystic knowledge that enhances elemental magical attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 55
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-elemental/angol-eiliant.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ambar": 25,
        "Naurtho": 25,
        "Heleg": 25,
        "Glauro": 25,
        "Geilo": 25,
        "Alagos": 25,
        "Lhorn": 25,
        "Gwaeren": 25,
        "Luithia": 25,
        "Gonatsai": 25,
        "Lhacha": 25
    ]));
    addSpecification("affected research type", "percentage");
}
