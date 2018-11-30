//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void CommonResearch()
{
    addResearchElement("lib/instances/research/crafting/weapons/common/annealing.c");
    addChild("lib/instances/research/crafting/weapons/common/annealing.c",
        "lib/instances/research/crafting/weapons/axes/craftBasicAxe.c");

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
public void CraftAxeResearch()
{
    addResearchElement("lib/instances/research/crafting/weapons/axes/craftDoubleAxe.c");
    addChild("lib/instances/research/crafting/weapons/axes/craftDoubleAxe.c",
        "lib/instances/research/crafting/weapons/axes/craftBasicAxe.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/craftExoticAxe.c");
    addChild("lib/instances/research/crafting/weapons/axes/craftExoticAxe.c",
        "lib/instances/research/crafting/weapons/axes/craftBasicAxe.c");
}

/////////////////////////////////////////////////////////////////////////////
public void Techniques()
{
    addResearchElement("lib/instances/research/crafting/weapons/axes/kheleds-tradition.c");
    addChild("lib/instances/research/crafting/weapons/axes/kheleds-tradition.c",
        "lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/kheleds-way.c");
    addChild("lib/instances/research/crafting/weapons/axes/kheleds-way.c",
        "lib/instances/research/crafting/weapons/axes/kheleds-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/kheleds-legacy.c");
    addChild("lib/instances/research/crafting/weapons/axes/kheleds-legacy.c",
        "lib/instances/research/crafting/weapons/axes/kheleds-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/kheleds-fury.c");
    addChild("lib/instances/research/crafting/weapons/axes/kheleds-fury.c",
        "lib/instances/research/crafting/weapons/axes/kheleds-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/maeliths-tradition.c");
    addChild("lib/instances/research/crafting/weapons/axes/maeliths-tradition.c",
        "lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/maeliths-way.c");
    addChild("lib/instances/research/crafting/weapons/axes/maeliths-way.c",
        "lib/instances/research/crafting/weapons/axes/maeliths-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/maeliths-legacy.c");
    addChild("lib/instances/research/crafting/weapons/axes/maeliths-legacy.c",
        "lib/instances/research/crafting/weapons/axes/maeliths-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/khazuraths-tradition.c");
    addChild("lib/instances/research/crafting/weapons/axes/khazuraths-tradition.c",
        "lib/instances/research/crafting/weapons/axes/maeliths-legacy.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/khazuraths-way.c");
    addChild("lib/instances/research/crafting/weapons/axes/khazuraths-way.c",
        "lib/instances/research/crafting/weapons/axes/khazuraths-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/khazuraths-legacy.c");
    addChild("lib/instances/research/crafting/weapons/axes/khazuraths-legacy.c",
        "lib/instances/research/crafting/weapons/axes/khazuraths-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/khed-arun.c");
    addChild("lib/instances/research/crafting/weapons/axes/khed-arun.c",
        "lib/instances/research/crafting/weapons/axes/khazuraths-legacy.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/khuz-no-dai.c");
    addChild("lib/instances/research/crafting/weapons/axes/khuz-no-dai.c",
        "lib/instances/research/crafting/weapons/axes/khed-arun.c");

    addResearchElement("lib/instances/research/crafting/weapons/axes/khazuraths-gift.c");
    addChild("lib/instances/research/crafting/weapons/axes/khazuraths-gift.c",
        "lib/instances/research/crafting/weapons/axes/khuz-no-dai.c");

}


/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Axe Forging");
        Description("This research tree tracks the knowledge required to craft axes");
        Source("crafting");
        addPrerequisite("weapon smithing", 
            (["type":"skill", "value" : 3]));
        addPrerequisite("lib/instances/research/crafting/weapons/craftWeapons.c",
            (["type":"research"]));
        addResearchElement("lib/instances/research/crafting/weapons/axes/craftBasicAxe.c");
        TreeRoot("lib/instances/research/crafting/weapons/axes/craftBasicAxe.c");

        CommonResearch();
        CraftAxeResearch();
        Techniques();
    }
}
