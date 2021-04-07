//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bronadui Hannas");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a high guard to high attack transition to use during "
        "combination attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 25
        ]));
    addPrerequisite("guilds/aegis-guard/forms/sword-combinations/laeg-hannas.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Godrebh ai Megil": 10
    ]));
    addSpecification("affected research type", "percentage");
}
