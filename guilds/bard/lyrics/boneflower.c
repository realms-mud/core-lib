//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Boneflower");
    addSpecification("source", "bard");
    addSpecification("description", "This research attunes the "
        "'Danse Macabre' research to bring forth significantly "
        "more lethal skeletons.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 33
    ]));

    addPrerequisite("/guilds/bard/lyrics/danse-macabre.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("related research", ({
        "/guilds/bard/lyrics/danse-macabre.c" }));
}
