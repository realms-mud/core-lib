//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Daedrun's Regret");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the legendary muse Daedrun's advanced vocal techniques.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 37 ]));
    addPrerequisite("guilds/bard/lyrics/daedruns-sorrow.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Daedrun's Lament": 100,
        "Daedrun's Fury": 100,
    ]));
    addSpecification("affected research type", "percentage");
}
