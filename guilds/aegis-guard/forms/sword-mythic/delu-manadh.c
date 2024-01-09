//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Delu Manadh");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances mythic magical attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 65
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-mythic/delu-eiliant.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Auth": 25,
        "Sereg": 25,
        "Guruthos": 25,
        "Lhutha": 25,
        "Angolo": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
