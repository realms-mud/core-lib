//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/spirit/chill.c");
    addResearchElement("lib/guilds/scion/paths/sword/spirit/phantasmalblade.c");

    addChild("lib/guilds/scion/paths/sword/spirit/chill.c",
        "lib/guilds/scion/paths/sword/spirit/root.c");
    addChild("lib/guilds/scion/paths/sword/spirit/phantasmalblade.c",
        "lib/guilds/scion/paths/sword/spirit/root.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of the Spirit");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy as part of "
            "the spirit realm.");

        addResearchElement("lib/guilds/scion/paths/sword/spirit/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/spirit/root.c");

        FirstLevel();
    }
}
