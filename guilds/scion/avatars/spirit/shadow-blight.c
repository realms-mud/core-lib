//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Blight");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research gives your "
        "avatar the `Shadow Blight' spell.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "Scion of Dhuras Guild",
        "value": 27
    ]));

    addPrerequisite("/guilds/scion/avatars/spirit/spirit-shards.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/scion/avatars/spirit/root.c",
    }));
}
