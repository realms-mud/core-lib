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
        addSpecification("name", "Freezing Shield");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the freezing shield technique. This form enhances "
            "the Scion's defensive spells.");
        Setup();

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 31 ]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/ice/ice-shroud.c", WeaponType),
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", (["Ice Shroud": 5 ]));
    }
}
