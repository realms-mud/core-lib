//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("The Way of the Sword");
        Description("");
        Source("Scion of Dhuras Guild");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/root.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/soulspike.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/sparks.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/flames.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/frost.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/mysticspike.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/chill.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/soulblade.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/shockblade.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/flameblade.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/frostblade.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/phantasmalblade.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/energyblade.c");        addResearchElement("lib/tutorial/guilds/scion/paths/sword/stabbing.c");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/from-the-roof.c");
        TreeRoot("lib/tutorial/guilds/scion/paths/sword/root.c");

        addChild("lib/tutorial/guilds/scion/paths/sword/soulspike.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/sparks.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/flames.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/frost.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/mysticspike.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/chill.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/soulblade.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/shockblade.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/flameblade.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/frostblade.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/phantasmalblade.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/energyblade.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/stabbing.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
        addChild("lib/tutorial/guilds/scion/paths/sword/from-the-roof.c",
            "lib/tutorial/guilds/scion/paths/sword/root.c");
    }
}
