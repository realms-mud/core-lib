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
        addSpecification("name", "Part Smite");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master smite - the part smite. This is a vertical "
            "descending smite that ends in the fool's guard. This smite is dealt "
            "to the opponent's head where the hair parts - thus its name. This "
            "smite is used to break the fool guard.");
        
        addSpecification("limited by", (["equipment":({ "mace", "flail" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 23 ]));

        addPrerequisite("lib/guilds/scion/paths/mace/forms/the-fool.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/mace/forms/over-smite.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus mace", 1);
        addSpecification("bonus flail", 1);
        addSpecification("bonus attack", 1);
        addSpecification("bonus defense", 1);
    }
}
