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
        addSpecification("name", "Ruth Dravn");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master hew - the wrath hew. This is a powerful "
            "diagonal hewing stroke dealt from the wrath guard and ending "
            "in a wechsel guard on the opposite side. When used to displace "
            "another hew, the impact and blade binding will result in the hew "
            "ending in a hanging parry.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 15 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword-attacks/thar-dravn.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword-guarding/tirnruth.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword-guarding/gwisten.c",
            (["type":"research"]));

        addSpecification("affected research", ([
            "Dravo": 15,
            "Naetho": 15,
            "Raeg": 15,
            "Lanc": 15,
            "Gleina": 15
        ]));
        addSpecification("affected research type", "percentage");

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus dagger", 1);
        addSpecification("bonus short sword", 1);
        addSpecification("bonus long sword", 1);
        addSpecification("bonus hand and a half sword", 1);
        addSpecification("bonus two-handed sword", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus damage", 2);
        addSpecification("equivalence", "wrath hew");
    }
}
