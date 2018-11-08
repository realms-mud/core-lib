//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/evocation/mysticspike.c");
    addResearchElement("lib/guilds/scion/paths/sword/evocation/energyblade.c");

    addChild("lib/guilds/scion/paths/sword/evocation/mysticspike.c",
        "lib/guilds/scion/paths/sword/evocation/root.c");
    addChild("lib/guilds/scion/paths/sword/evocation/energyblade.c",
        "lib/guilds/scion/paths/sword/evocation/root.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of Evocation");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the knowledge to "
            "express their raw magical energy as pure magical essence "
            "given form.");

        addResearchElement("lib/guilds/scion/paths/sword/evocation/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/evocation/root.c");

        FirstLevel();
    }
}
