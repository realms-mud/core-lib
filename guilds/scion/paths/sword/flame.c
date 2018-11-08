//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/flame/flames.c");
    addResearchElement("lib/guilds/scion/paths/sword/flame/flameblade.c");

    addChild("lib/guilds/scion/paths/sword/flame/flames.c",
        "lib/guilds/scion/paths/sword/flame/root.c");
    addChild("lib/guilds/scion/paths/sword/flame/flameblade.c",
        "lib/guilds/scion/paths/sword/flame/root.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of the Flame");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy as flame.");

        addResearchElement("lib/guilds/scion/paths/sword/flame/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/flame/root.c");

        FirstLevel();
    }
}
