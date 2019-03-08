//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Mutating Attack");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of how to change a displaced hew into a strike or "
            "a displaced strike into a hew.");
        addSpecification("limited by", (["equipment":({ "axe" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 14 ]));

        addPrerequisite("lib/guilds/scion/paths/axe/forms/doubling.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/axe/forms/hew.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/axe/forms/striking.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus axe", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus damage", 1);
    }
}
