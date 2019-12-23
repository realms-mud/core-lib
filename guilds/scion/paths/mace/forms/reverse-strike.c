//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Reverse Strike");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of how to transition from the boar guard into a "
            "reverse strike.");
        addSpecification("limited by", (["equipment":({ "mace", "flail" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 10 ]));

        addPrerequisite("guilds/scion/paths/mace/forms/the-boar.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/mace/forms/striking.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus mace", 1);
        addSpecification("bonus flail", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus damage", 1);
    }
}
