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
        addSpecification("name", "Squinting Hew");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master hew - the squinting hew. This is a high "
            "horizontal hew dealt from the from-the-roof guard that ends in "
            "an upper hanger on the opposite side, typically targetting the "
            "head or right shoulder. This breaks the plough and the langort "
            "guards and is also a very effective counter to the over-hew.");
        
        addSpecification("limited by", (["equipment":({
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 20 ]));

        addPrerequisite("lib/guilds/scion/paths/sword/forms/thrusting.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/sword/forms/langort.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/sword/forms/over-hew.c",
            (["type":"research"]));
        addPrerequisite("lib/guilds/scion/paths/sword/forms/the-plough.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus long sword", 1);
        addSpecification("bonus hand and a half sword", 1);
        addSpecification("bonus two-handed sword", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus defense", 2);
    }
}
