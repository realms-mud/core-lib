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
        "lib/instances/research/crafting/weapons/swords/craftBasicSwords.c");

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
public void CraftSwordResearch()
{
    addResearchElement("lib/instances/research/crafting/weapons/swords/craftCurvedSwords.c");
    addChild("lib/instances/research/crafting/weapons/swords/craftCurvedSwords.c",
        "lib/instances/research/crafting/weapons/swords/craftBasicSwords.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/craftElegantSwords.c");
    addChild("lib/instances/research/crafting/weapons/swords/craftElegantSwords.c",
        "lib/instances/research/crafting/weapons/swords/craftBasicSwords.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/craftLongSwords.c");
    addChild("lib/instances/research/crafting/weapons/swords/craftLongSwords.c",
        "lib/instances/research/crafting/weapons/swords/craftBasicSwords.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/craftGreatSwords.c");
    addChild("lib/instances/research/crafting/weapons/swords/craftGreatSwords.c",
        "lib/instances/research/crafting/weapons/swords/craftLongSwords.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/craftExoticSwords.c");
    addChild("lib/instances/research/crafting/weapons/swords/craftExoticSwords.c",
        "lib/instances/research/crafting/weapons/swords/craftLongSwords.c");
}

/////////////////////////////////////////////////////////////////////////////
public void Techniques()
{
    addResearchElement("lib/instances/research/crafting/weapons/swords/rengils-tradition.c");
    addChild("lib/instances/research/crafting/weapons/swords/rengils-tradition.c",
        "lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/rengils-way.c");
    addChild("lib/instances/research/crafting/weapons/swords/rengils-way.c",
        "lib/instances/research/crafting/weapons/swords/rengils-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/rengils-legacy.c");
    addChild("lib/instances/research/crafting/weapons/swords/rengils-legacy.c",
        "lib/instances/research/crafting/weapons/swords/rengils-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/maeliths-tradition.c");
    addChild("lib/instances/research/crafting/weapons/swords/maeliths-tradition.c",
        "lib/instances/research/crafting/weapons/common/mystic-wrapping.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/maeliths-way.c");
    addChild("lib/instances/research/crafting/weapons/swords/maeliths-way.c",
        "lib/instances/research/crafting/weapons/swords/maeliths-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/maeliths-legacy.c");
    addChild("lib/instances/research/crafting/weapons/swords/maeliths-legacy.c",
        "lib/instances/research/crafting/weapons/swords/maeliths-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/daedruns-tradition.c");
    addChild("lib/instances/research/crafting/weapons/swords/daedruns-tradition.c",
        "lib/instances/research/crafting/weapons/swords/maeliths-legacy.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/daedruns-way.c");
    addChild("lib/instances/research/crafting/weapons/swords/daedruns-way.c",
        "lib/instances/research/crafting/weapons/swords/daedruns-tradition.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/daedruns-legacy.c");
    addChild("lib/instances/research/crafting/weapons/swords/daedruns-legacy.c",
        "lib/instances/research/crafting/weapons/swords/daedruns-way.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/impart-the-essence.c");
    addChild("lib/instances/research/crafting/weapons/swords/impart-the-essence.c",
        "lib/instances/research/crafting/weapons/swords/daedruns-legacy.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/enhance-the-essence.c");
    addChild("lib/instances/research/crafting/weapons/swords/enhance-the-essence.c",
        "lib/instances/research/crafting/weapons/swords/impart-the-essence.c");

    addResearchElement("lib/instances/research/crafting/weapons/swords/daedruns-gift.c");
    addChild("lib/instances/research/crafting/weapons/swords/daedruns-gift.c",
        "lib/instances/research/crafting/weapons/swords/impart-the-essence.c");

}


/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Swordsmithing");
        Description("This research tree tracks the knowledge required to craft knives, daggers, and swords");
        Source("crafting");
        addPrerequisite("weapon smithing", 
            (["type":"skill", "value" : 3]));
        addPrerequisite("lib/instances/research/crafting/weapons/craftWeapons.c",
            (["type":"research"]));
        addResearchElement("lib/instances/research/crafting/weapons/swords/craftBasicSwords.c");
        TreeRoot("lib/instances/research/crafting/weapons/swords/craftBasicSwords.c");

        CommonResearch();
        CraftSwordResearch();
        Techniques();
    }
}
