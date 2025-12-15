//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Retribution");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "knowledge that further enhances the cleric's divine offensive "
        "abilities.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/offense/ilryths-judgment.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Righteous Strike": 25,
        "Divine Torrent": 25,
        "Ilryth's Judgment": 25,
        "Righteous Tempest": 25,
        "Wrath of Ilyrth": 25,
        "Ilryth's Final Judgment": 25
    ]));
    addSpecification("affected research type", "percentage");
}
