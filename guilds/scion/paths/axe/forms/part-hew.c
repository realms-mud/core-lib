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
        addSpecification("name", "Part Hew");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master hew - the part hew. This is a vertical "
            "descending hew that ends in the fool's guard. This hew is dealt "
            "to the opponent's head where the hair parts - thus its name. This "
            "hew is used to break the fool guard.");
        
        addSpecification("limited by", (["equipment":({ "axe" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 23 ]));

        addPrerequisite("lib/guilds/scion/paths/axe/forms/the-fool.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/axe/forms/over-hew.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus axe", 1);
        addSpecification("bonus attack", 1);
        addSpecification("bonus defense", 1);
    }
}
