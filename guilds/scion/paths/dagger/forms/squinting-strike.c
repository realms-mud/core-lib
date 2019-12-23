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
        addSpecification("name", "Squinting Strike");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a master stab maneuver - the squinting strike maneuver. This is a high "
            "horizontal stab maneuver dealt from the from-the-roof guard that ends in "
            "an upper hanger on the opposite side, typically targetting the "
            "head or right shoulder. This breaks the plough and the langort "
            "guards and is also a very effective counter to the over-stab maneuver.");
        
        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 20 ]));

        addPrerequisite("guilds/scion/paths/dagger/forms/thrusting.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/dagger/forms/langort.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/dagger/forms/over-strike.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/dagger/forms/the-plough.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus dagger", 1);
        addSpecification("bonus short sword", 1);

        addSpecification("bonus attack", 2);
        addSpecification("bonus defense", 2);
    }
}
