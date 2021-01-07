//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Faen Celair");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge to decrease the cost for which they can use their "
            "elemental magic skills.");

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 19
            ]));
        addPrerequisite("guilds/aegis-guard/forms/sword-elemental/elemental-root.c",
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
            "Gonatsai": 15
        ]));
        addSpecification("affected research type", "decrease cost");
    }
}
