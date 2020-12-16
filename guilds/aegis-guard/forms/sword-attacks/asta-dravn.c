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
        addSpecification("name", "Asta Dravn");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master hew - the part hew. This is a vertical "
            "descending hew that ends in the fool's guard. This hew is dealt "
            "to the opponent's head where the hair parts - thus its name. This "
            "hew is used to break the fool guard.");
        
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 23 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword-guarding/an-foph.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword-attacks/thar-dravn.c",
            (["type":"research"]));

        addSpecification("affected research", ([
            "Dravo": 15,
            "Maetha": 15
        ]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus dagger", 1);
        addSpecification("bonus short sword", 1);
        addSpecification("bonus long sword", 1);
        addSpecification("bonus hand and a half sword", 1);
        addSpecification("bonus two-handed sword", 1);
        addSpecification("bonus attack", 1);
        addSpecification("bonus defense", 1);
        addSpecification("equivalence", "part hew");
    }
}
