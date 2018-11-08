//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/forms/stabbing.c");
    addResearchElement("lib/guilds/scion/paths/sword/forms/from-the-roof.c");

    addChild("lib/guilds/scion/paths/sword/forms/stabbing.c",
        "lib/guilds/scion/paths/sword/root.c");
    addChild("lib/guilds/scion/paths/sword/forms/from-the-roof.c",
        "lib/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("The Way of the Sword");
        Description("");
        Source("Scion of Dhuras Guild");
        addResearchElement("lib/guilds/scion/paths/sword/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/root.c");

        FirstLevel();
    }
}
