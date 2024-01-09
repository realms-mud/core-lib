//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Faen Manadh");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the cost for which they can use their "
        "elemental magic skills.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 39
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-elemental/faen-edlothia.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ambar": 10,
        "Naurtho": 10,
        "Heleg": 10,
        "Glauro": 10,
        "Geilo": 10,
        "Alagos": 10,
        "Lhorn": 10,
        "Gwaeren": 10,
        "Luithia": 10,
        "Gonatsai": 10,
        "Lhacha": 10
    ]));
    addSpecification("affected research type", "decrease cost");
}
