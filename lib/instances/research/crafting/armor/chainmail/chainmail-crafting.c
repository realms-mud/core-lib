//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void CommonResearch()
{
    addResearchElement("lib/instances/research/crafting/armor/common/annealing.c");
    addChild("lib/instances/research/crafting/armor/common/annealing.c",
    "lib/instances/research/crafting/armor/chainmail/craftChainmail.c");

    addResearchElement("lib/instances/research/crafting/armor/common/slack-quenching.c");
    addChild("lib/instances/research/crafting/armor/common/slack-quenching.c",
    "lib/instances/research/crafting/armor/common/annealing.c");

    addResearchElement("lib/instances/research/crafting/armor/common/quenching.c");
    addChild("lib/instances/research/crafting/armor/common/quenching.c",
    "lib/instances/research/crafting/armor/common/slack-quenching.c");

    addResearchElement("lib/instances/research/crafting/armor/common/tempering.c");
    addChild("lib/instances/research/crafting/armor/common/tempering.c",
    "lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/armor/common/stepped-tempering.c");
    addChild("lib/instances/research/crafting/armor/common/stepped-tempering.c",
    "lib/instances/research/crafting/armor/common/tempering.c");

    addResearchElement("lib/instances/research/crafting/armor/common/austempering.c");
    addChild("lib/instances/research/crafting/armor/common/austempering.c",
    "lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/armor/common/stepped-quenching.c");
    addChild("lib/instances/research/crafting/armor/common/stepped-quenching.c",
    "lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/armor/common/case-hardening.c");
    addChild("lib/instances/research/crafting/armor/common/case-hardening.c",
    "lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/armor/common/differential-hardening.c");
    addChild("lib/instances/research/crafting/armor/common/differential-hardening.c",
    "lib/instances/research/crafting/armor/common/stepped-tempering.c");

    addResearchElement("lib/instances/research/crafting/armor/common/folding.c");
    addChild("lib/instances/research/crafting/armor/common/folding.c",
    "lib/instances/research/crafting/armor/common/annealing.c");

    addResearchElement("lib/instances/research/crafting/armor/common/pattern-welding.c");
    addChild("lib/instances/research/crafting/armor/common/pattern-welding.c",
    "lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("lib/instances/research/crafting/armor/common/wrapping.c");
    addChild("lib/instances/research/crafting/armor/common/wrapping.c",
    "lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("lib/instances/research/crafting/armor/common/forge-welding.c");
    addChild("lib/instances/research/crafting/armor/common/forge-welding.c",
    "lib/instances/research/crafting/armor/common/annealing.c");

    addResearchElement("lib/instances/research/crafting/armor/common/mystic-folding.c");
    addChild("lib/instances/research/crafting/armor/common/mystic-folding.c",
    "lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("lib/instances/research/crafting/armor/common/mystic-quenching.c");
    addChild("lib/instances/research/crafting/armor/common/mystic-quenching.c",
    "lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("lib/instances/research/crafting/armor/common/mystic-wrapping.c");
    addChild("lib/instances/research/crafting/armor/common/mystic-wrapping.c",
    "lib/instances/research/crafting/armor/common/mystic-folding.c");

    addResearchElement("lib/instances/research/crafting/armor/common/mystic-welding.c");
    addChild("lib/instances/research/crafting/armor/common/mystic-welding.c",
    "lib/instances/research/crafting/armor/common/mystic-wrapping.c");
}

/////////////////////////////////////////////////////////////////////////////
public void Techniques()
{
    addResearchElement("lib/instances/research/crafting/armor/chainmail/kheleds-tradition.c");
    addChild("lib/instances/research/crafting/armor/chainmail/kheleds-tradition.c",
    "lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/kheleds-way.c");
    addChild("lib/instances/research/crafting/armor/chainmail/kheleds-way.c",
    "lib/instances/research/crafting/armor/chainmail/kheleds-tradition.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/kheleds-legacy.c");
    addChild("lib/instances/research/crafting/armor/chainmail/kheleds-legacy.c",
    "lib/instances/research/crafting/armor/chainmail/kheleds-way.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/kheleds-aegis.c");
    addChild("lib/instances/research/crafting/armor/chainmail/kheleds-aegis.c",
    "lib/instances/research/crafting/armor/chainmail/kheleds-way.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/maeliths-tradition.c");
    addChild("lib/instances/research/crafting/armor/chainmail/maeliths-tradition.c",
    "lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/maeliths-way.c");
    addChild("lib/instances/research/crafting/armor/chainmail/maeliths-way.c",
    "lib/instances/research/crafting/armor/chainmail/maeliths-tradition.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/maeliths-legacy.c");
    addChild("lib/instances/research/crafting/armor/chainmail/maeliths-legacy.c",
    "lib/instances/research/crafting/armor/chainmail/maeliths-way.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/khazuraths-tradition.c");
    addChild("lib/instances/research/crafting/armor/chainmail/khazuraths-tradition.c",
    "lib/instances/research/crafting/armor/chainmail/maeliths-legacy.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/khazuraths-way.c");
    addChild("lib/instances/research/crafting/armor/chainmail/khazuraths-way.c",
    "lib/instances/research/crafting/armor/chainmail/khazuraths-tradition.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/khazuraths-legacy.c");
    addChild("lib/instances/research/crafting/armor/chainmail/khazuraths-legacy.c",
    "lib/instances/research/crafting/armor/chainmail/khazuraths-way.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/khed-arun.c");
    addChild("lib/instances/research/crafting/armor/chainmail/khed-arun.c",
    "lib/instances/research/crafting/armor/chainmail/khazuraths-legacy.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/khuz-no-dai.c");
    addChild("lib/instances/research/crafting/armor/chainmail/khuz-no-dai.c",
    "lib/instances/research/crafting/armor/chainmail/khed-arun.c");

    addResearchElement("lib/instances/research/crafting/armor/chainmail/khazuraths-gift.c");
    addChild("lib/instances/research/crafting/armor/chainmail/khazuraths-gift.c",
    "lib/instances/research/crafting/armor/chainmail/khuz-no-dai.c");

}


/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Chainmail Crafting");
    Description("This research tree tracks the knowledge required to craft "
        "chainmail");
    Source("crafting");
    addPrerequisite("weapon smithing", 
        (["type":"skill", "value" : 3]));
    addPrerequisite("lib/instances/research/crafting/armor/craftArmor.c",
        (["type":"research"]));

    addResearchElement("lib/instances/research/crafting/armor/chainmail/craftChainmail.c");
    TreeRoot("lib/instances/research/crafting/armor/chainmail/craftChainmail.c");

    CommonResearch();
    Techniques();
}
