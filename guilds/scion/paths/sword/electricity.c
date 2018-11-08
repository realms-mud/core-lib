//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/sparks.c");
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shockblade.c");

    addChild("lib/guilds/scion/paths/sword/electricity/sparks.c",
        "lib/guilds/scion/paths/sword/electricity/root.c");
    addChild("lib/guilds/scion/paths/sword/electricity/shockblade.c",
        "lib/guilds/scion/paths/sword/electricity/root.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of the Bolt");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy as electrical power.");

        addResearchElement("lib/guilds/scion/paths/sword/electricity/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/electricity/root.c");

        FirstLevel();
    }
}
