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
        addSpecification("name", "Centhlein Dravn");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master hew - the squinting hew. This is a high "
            "horizontal hew dealt from the from-the-roof guard that ends in "
            "an upper hanger on the opposite side, typically targetting the "
            "head or right shoulder. This breaks the plough and the langort "
            "guards and is also a very effective counter to the over-hew.");
        
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 20 ]));

        addSpecification("affected research", ([
            "Dravo": 15,
            "Naetho": 15,
            "Maetha": 15
        ]));

        addPrerequisite("guilds/aegis-guard/forms/sword/nistaros.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword/sathataen.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword/thar-dravn.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword/an-craban.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus dagger", 1);
        addSpecification("bonus short sword", 1);
        addSpecification("bonus long sword", 1);
        addSpecification("bonus hand and a half sword", 1);
        addSpecification("bonus two-handed sword", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus defense", 2);
        addSpecification("equivalence", "squinting hew");
    }
}
