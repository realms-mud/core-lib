//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lhegren Gwaelphilin");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the cost for which they can use their "
        "mundane archery skills.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 16
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/bow/bregol-gwaelphilin.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Bregol Adleg": 10,
        "Umba ai Adleg": 10,
    ]));
    addSpecification("affected research type", "decrease cost");
}
