//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Boon of Landros");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the legendary muse Landros's advanced vocal techniques.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 25 ]));
    addPrerequisite("guilds/bard/lyrics/a-rhyme-of-the-deep.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Lay of Landros": 50,
        "Song for Aelin": 50,
    ]));
    addSpecification("affected research type", "percentage");
}
