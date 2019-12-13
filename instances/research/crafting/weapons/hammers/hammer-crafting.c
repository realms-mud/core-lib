//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void CommonResearch()
{
    addResearchElement("lib/instances/research/crafting/weapons/common/annealing.c");
    addChild("lib/instances/research/crafting/weapons/common/annealing.c",
        "lib/instances/research/crafting/weapons/hammers/craftBasicHammer.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/slack-quenching.c");
    addChild("lib/instances/research/crafting/weapons/common/slack-quenching.c",
        "lib/instances/research/crafting/weapons/common/annealing.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/quenching.c");
    addChild("lib/instances/research/crafting/weapons/common/quenching.c",
        "lib/instances/research/crafting/weapons/common/slack-quenching.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/tempering.c");
    addChild("lib/instances/research/crafting/weapons/common/tempering.c",
        "lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/stepped-tempering.c");
    addChild("lib/instances/research/crafting/weapons/common/stepped-tempering.c",
        "lib/instances/research/crafting/weapons/common/tempering.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/austempering.c");
    addChild("lib/instances/research/crafting/weapons/common/austempering.c",
        "lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/stepped-quenching.c");
    addChild("lib/instances/research/crafting/weapons/common/stepped-quenching.c",
        "lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/case-hardening.c");
    addChild("lib/instances/research/crafting/weapons/common/case-hardening.c",
        "lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/differential-hardening.c");
    addChild("lib/instances/research/crafting/weapons/common/differential-hardening.c",
        "lib/instances/research/crafting/weapons/common/stepped-tempering.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/folding.c");
    addChild("lib/instances/research/crafting/weapons/common/folding.c",
        "lib/instances/research/crafting/weapons/common/annealing.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/pattern-welding.c");
    addChild("lib/instances/research/crafting/weapons/common/pattern-welding.c",
        "lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/wrapping.c");
    addChild("lib/instances/research/crafting/weapons/common/wrapping.c",
        "lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/forge-welding.c");
    addChild("lib/instances/research/crafting/weapons/common/forge-welding.c",
        "lib/instances/research/crafting/weapons/common/annealing.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/mystic-folding.c");
    addChild("lib/instances/research/crafting/weapons/common/mystic-folding.c",
        "lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/mystic-quenching.c");
    addChild("lib/instances/research/crafting/weapons/common/mystic-quenching.c",
        "lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/mystic-wrapping.c");
    addChild("lib/instances/research/crafting/weapons/common/mystic-wrapping.c",
        "lib/instances/research/crafting/weapons/common/mystic-folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/common/mystic-welding.c");
    addChild("lib/instances/research/crafting/weapons/common/mystic-welding.c",
        "lib/instances/research/crafting/weapons/common/mystic-wrapping.c");
}

/////////////////////////////////////////////////////////////////////////////
public void CraftHammerResearch()
{
    addResearchElement("lib/instances/research/crafting/weapons/hammers/craftWarHammer.c");
    addChild("lib/instances/research/crafting/weapons/hammers/craftWarHammer.c",
        "lib/instances/research/crafting/weapons/hammers/craftBasicHammer.c");
}

/////////////////////////////////////////////////////////////////////////////
public void Techniques()
{
    addResearchElement("lib/instances/research/crafting/weapons/hammers/aegraths-tradition.c");
    addChild("lib/instances/research/crafting/weapons/hammers/aegraths-tradition.c",
        "lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/aegraths-way.c");
    addChild("lib/instances/research/crafting/weapons/hammers/aegraths-way.c",
        "lib/instances/research/crafting/weapons/hammers/aegraths-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/aegraths-legacy.c");
    addChild("lib/instances/research/crafting/weapons/hammers/aegraths-legacy.c",
        "lib/instances/research/crafting/weapons/hammers/aegraths-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/aegraths-fury.c");
    addChild("lib/instances/research/crafting/weapons/hammers/aegraths-fury.c",
        "lib/instances/research/crafting/weapons/hammers/aegraths-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/tengredhs-tradition.c");
    addChild("lib/instances/research/crafting/weapons/hammers/tengredhs-tradition.c",
        "lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/tengredhs-way.c");
    addChild("lib/instances/research/crafting/weapons/hammers/tengredhs-way.c",
        "lib/instances/research/crafting/weapons/hammers/tengredhs-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/tengredhs-legacy.c");
    addChild("lib/instances/research/crafting/weapons/hammers/tengredhs-legacy.c",
        "lib/instances/research/crafting/weapons/hammers/tengredhs-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/dhurgils-tradition.c");
    addChild("lib/instances/research/crafting/weapons/hammers/dhurgils-tradition.c",
        "lib/instances/research/crafting/weapons/hammers/tengredhs-legacy.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/dhurgils-way.c");
    addChild("lib/instances/research/crafting/weapons/hammers/dhurgils-way.c",
        "lib/instances/research/crafting/weapons/hammers/dhurgils-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/dhurgils-legacy.c");
    addChild("lib/instances/research/crafting/weapons/hammers/dhurgils-legacy.c",
        "lib/instances/research/crafting/weapons/hammers/dhurgils-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/cuerth-faer.c");
    addChild("lib/instances/research/crafting/weapons/hammers/cuerth-faer.c",
        "lib/instances/research/crafting/weapons/hammers/dhurgils-legacy.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/khel-ma-druek.c");
    addChild("lib/instances/research/crafting/weapons/hammers/khel-ma-druek.c",
        "lib/instances/research/crafting/weapons/hammers/cuerth-faer.c");

    addResearchElement("lib/instances/research/crafting/weapons/hammers/dhurgils-gift.c");
    addChild("lib/instances/research/crafting/weapons/hammers/dhurgils-gift.c",
        "lib/instances/research/crafting/weapons/hammers/khel-ma-druek.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Axe Forging");
        Description("This research tree tracks the knowledge required to craft hammers");
        Source("crafting");
        addPrerequisite("weapon smithing", 
            (["type":"skill", "value" : 3]));
        addPrerequisite("lib/instances/research/crafting/weapons/craftWeapons.c",
            (["type":"research"]));
        addResearchElement("lib/instances/research/crafting/weapons/hammers/craftBasicHammer.c");
        TreeRoot("lib/instances/research/crafting/weapons/hammers/craftBasicHammer.c");

        CommonResearch();
        CraftHammerResearch();
        Techniques();
    }
}
