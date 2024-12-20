//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Delu Celair");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances mythic magical attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 35
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-mythic/delu-anwar.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Auth": 15,
        "Sereg": 15,
        "Guruthos": 15,
        "Lhutha": 15,
        "Angolo": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
