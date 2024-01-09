//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Megor Pilin");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with "
        "mystic knowledge that enhances mundane archery attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 21
        ]));
    addPrerequisite("/guilds/aegis-guard/forms/bow/alag-pilin.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Bregol Adleg": 15,
        "Umba ai Adleg": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
