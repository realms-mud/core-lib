//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Squinting Smite");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master smite - the squinting smite. This is a high "
            "horizontal smite dealt from the from-the-roof guard that ends in "
            "an upper hanger on the opposite side, typically targetting the "
            "head or right shoulder. This breaks the plough and the langort "
            "guards and is also a very effective counter to the over-smite.");
        
        addSpecification("limited by", (["equipment":({ "mace", "flail" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 20 ]));

        addPrerequisite("guilds/scion/paths/mace/forms/striking.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/mace/forms/langort.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/mace/forms/over-smite.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/mace/forms/the-plough.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus mace", 1);
        addSpecification("bonus flail", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus defense", 2);
    }
}
