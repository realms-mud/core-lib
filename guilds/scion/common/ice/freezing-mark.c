//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Freezing Mark");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the freezing mark technique. This form enhances "
            "the Scion's offensive spells.");
        Setup();

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 13 ]));
        addPrerequisite(
            sprintf("lib/guilds/scion/paths/%s/ice/chill-the-blood.c", WeaponType),
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", ([
            "Ice Bolt":5,
            "Ice Javelin": 5,
            "Frost Wave": 5,
            "Blizzard": 5,
            "Call of Winter": 10
        ]));
    }
}
