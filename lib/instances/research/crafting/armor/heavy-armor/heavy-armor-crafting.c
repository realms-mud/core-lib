//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void CommonResearch()
{
    addResearchElement("/lib/instances/research/crafting/armor/common/annealing.c");
    addChild("/lib/instances/research/crafting/armor/common/annealing.c",
    "/lib/instances/research/crafting/armor/heavy-armor/craftHeavyArmor.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/slack-quenching.c");
    addChild("/lib/instances/research/crafting/armor/common/slack-quenching.c",
    "/lib/instances/research/crafting/armor/common/annealing.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/quenching.c");
    addChild("/lib/instances/research/crafting/armor/common/quenching.c",
    "/lib/instances/research/crafting/armor/common/slack-quenching.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/tempering.c");
    addChild("/lib/instances/research/crafting/armor/common/tempering.c",
    "/lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/stepped-tempering.c");
    addChild("/lib/instances/research/crafting/armor/common/stepped-tempering.c",
    "/lib/instances/research/crafting/armor/common/tempering.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/austempering.c");
    addChild("/lib/instances/research/crafting/armor/common/austempering.c",
    "/lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/stepped-quenching.c");
    addChild("/lib/instances/research/crafting/armor/common/stepped-quenching.c",
    "/lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/case-hardening.c");
    addChild("/lib/instances/research/crafting/armor/common/case-hardening.c",
    "/lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/differential-hardening.c");
    addChild("/lib/instances/research/crafting/armor/common/differential-hardening.c",
    "/lib/instances/research/crafting/armor/common/stepped-tempering.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/folding.c");
    addChild("/lib/instances/research/crafting/armor/common/folding.c",
    "/lib/instances/research/crafting/armor/common/annealing.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/pattern-welding.c");
    addChild("/lib/instances/research/crafting/armor/common/pattern-welding.c",
    "/lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/wrapping.c");
    addChild("/lib/instances/research/crafting/armor/common/wrapping.c",
    "/lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/forge-welding.c");
    addChild("/lib/instances/research/crafting/armor/common/forge-welding.c",
    "/lib/instances/research/crafting/armor/common/annealing.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/mystic-folding.c");
    addChild("/lib/instances/research/crafting/armor/common/mystic-folding.c",
    "/lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/mystic-quenching.c");
    addChild("/lib/instances/research/crafting/armor/common/mystic-quenching.c",
    "/lib/instances/research/crafting/armor/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/mystic-wrapping.c");
    addChild("/lib/instances/research/crafting/armor/common/mystic-wrapping.c",
    "/lib/instances/research/crafting/armor/common/mystic-folding.c");

    addResearchElement("/lib/instances/research/crafting/armor/common/mystic-welding.c");
    addChild("/lib/instances/research/crafting/armor/common/mystic-welding.c",
    "/lib/instances/research/crafting/armor/common/mystic-wrapping.c");
}

/////////////////////////////////////////////////////////////////////////////
public void CraftHeavyArmorResearch()
{
    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/craftPlateArmor.c",
    "/lib/instances/research/crafting/armor/heavy-armor/craftHeavyArmor.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/craftScaleArmor.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/craftScaleArmor.c",
    "/lib/instances/research/crafting/armor/heavy-armor/craftHeavyArmor.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/craftSplintArmor.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/craftSplintArmor.c",
    "/lib/instances/research/crafting/armor/heavy-armor/craftHeavyArmor.c");
}

/////////////////////////////////////////////////////////////////////////////
public void Techniques()
{
    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/bergons-tradition.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/bergons-tradition.c",
    "/lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/bergons-way.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/bergons-way.c",
    "/lib/instances/research/crafting/armor/heavy-armor/bergons-tradition.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/bergons-legacy.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/bergons-legacy.c",
    "/lib/instances/research/crafting/armor/heavy-armor/bergons-way.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/bergons-aegis.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/bergons-aegis.c",
    "/lib/instances/research/crafting/armor/heavy-armor/bergons-way.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/maeliths-tradition.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/maeliths-tradition.c",
    "/lib/instances/research/crafting/armor/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/maeliths-way.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/maeliths-way.c",
    "/lib/instances/research/crafting/armor/heavy-armor/maeliths-tradition.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/maeliths-legacy.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/maeliths-legacy.c",
    "/lib/instances/research/crafting/armor/heavy-armor/maeliths-way.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/khazuraths-tradition.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/khazuraths-tradition.c",
    "/lib/instances/research/crafting/armor/heavy-armor/maeliths-legacy.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/khazuraths-way.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/khazuraths-way.c",
    "/lib/instances/research/crafting/armor/heavy-armor/khazuraths-tradition.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/khazuraths-legacy.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/khazuraths-legacy.c",
    "/lib/instances/research/crafting/armor/heavy-armor/khazuraths-way.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/khed-arun.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/khed-arun.c",
    "/lib/instances/research/crafting/armor/heavy-armor/khazuraths-legacy.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/khuz-no-dai.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/khuz-no-dai.c",
    "/lib/instances/research/crafting/armor/heavy-armor/khed-arun.c");

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/khazuraths-gift.c");
    addChild("/lib/instances/research/crafting/armor/heavy-armor/khazuraths-gift.c",
    "/lib/instances/research/crafting/armor/heavy-armor/khuz-no-dai.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Chainmail Crafting");
    Description("This research tree tracks the knowledge required to craft "
        "heavy-armor");
    Source("crafting");
    addPrerequisite("weapon smithing", 
        (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/crafting/armor/craftArmor.c",
        (["type":"research"]));

    addResearchElement("/lib/instances/research/crafting/armor/heavy-armor/craftHeavyArmor.c");
    TreeRoot("/lib/instances/research/crafting/armor/heavy-armor/craftHeavyArmor.c");

    CommonResearch();
    Techniques();
}
