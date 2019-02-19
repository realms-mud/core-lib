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
        addSpecification("name", "Sweeping Frost");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of the sweeping frost technique. This form enhances "
            "the scion's Frost Brand and Ice Brand abilities.");
        Setup();

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 3 ]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/ice/frost-brand.c", WeaponType),
            (["type":"research"]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", ([
            "Frost Brand":2,
            "Ice Brand" : 3
        ]));
    }
}
