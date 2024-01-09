//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
public void CommonResearch()
{
    addResearchElement("/lib/instances/research/crafting/weapons/common/annealing.c");
    addChild("/lib/instances/research/crafting/weapons/common/annealing.c",
        "/lib/instances/research/crafting/weapons/maces/craftBasicMace.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/slack-quenching.c");
    addChild("/lib/instances/research/crafting/weapons/common/slack-quenching.c",
        "/lib/instances/research/crafting/weapons/common/annealing.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/quenching.c");
    addChild("/lib/instances/research/crafting/weapons/common/quenching.c",
        "/lib/instances/research/crafting/weapons/common/slack-quenching.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/tempering.c");
    addChild("/lib/instances/research/crafting/weapons/common/tempering.c",
        "/lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/stepped-tempering.c");
    addChild("/lib/instances/research/crafting/weapons/common/stepped-tempering.c",
        "/lib/instances/research/crafting/weapons/common/tempering.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/austempering.c");
    addChild("/lib/instances/research/crafting/weapons/common/austempering.c",
        "/lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/stepped-quenching.c");
    addChild("/lib/instances/research/crafting/weapons/common/stepped-quenching.c",
        "/lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/case-hardening.c");
    addChild("/lib/instances/research/crafting/weapons/common/case-hardening.c",
        "/lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/differential-hardening.c");
    addChild("/lib/instances/research/crafting/weapons/common/differential-hardening.c",
        "/lib/instances/research/crafting/weapons/common/stepped-tempering.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/folding.c");
    addChild("/lib/instances/research/crafting/weapons/common/folding.c",
        "/lib/instances/research/crafting/weapons/common/annealing.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/pattern-welding.c");
    addChild("/lib/instances/research/crafting/weapons/common/pattern-welding.c",
        "/lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/wrapping.c");
    addChild("/lib/instances/research/crafting/weapons/common/wrapping.c",
        "/lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/forge-welding.c");
    addChild("/lib/instances/research/crafting/weapons/common/forge-welding.c",
        "/lib/instances/research/crafting/weapons/common/annealing.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/mystic-folding.c");
    addChild("/lib/instances/research/crafting/weapons/common/mystic-folding.c",
        "/lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/mystic-quenching.c");
    addChild("/lib/instances/research/crafting/weapons/common/mystic-quenching.c",
        "/lib/instances/research/crafting/weapons/common/quenching.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/mystic-wrapping.c");
    addChild("/lib/instances/research/crafting/weapons/common/mystic-wrapping.c",
        "/lib/instances/research/crafting/weapons/common/mystic-folding.c");

    addResearchElement("/lib/instances/research/crafting/weapons/common/mystic-welding.c");
    addChild("/lib/instances/research/crafting/weapons/common/mystic-welding.c",
        "/lib/instances/research/crafting/weapons/common/mystic-wrapping.c");
}

/////////////////////////////////////////////////////////////////////////////
public void CraftMaceResearch()
{
    addResearchElement("/lib/instances/research/crafting/weapons/maces/craftComplexMace.c");
    addChild("/lib/instances/research/crafting/weapons/maces/craftComplexMace.c",
        "/lib/instances/research/crafting/weapons/maces/craftBasicMace.c");
}

/////////////////////////////////////////////////////////////////////////////
public void Techniques()
{
    addResearchElement("/lib/instances/research/crafting/weapons/maces/beregors-tradition.c");
    addChild("/lib/instances/research/crafting/weapons/maces/beregors-tradition.c",
        "/lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/beregors-way.c");
    addChild("/lib/instances/research/crafting/weapons/maces/beregors-way.c",
        "/lib/instances/research/crafting/weapons/maces/beregors-tradition.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/beregors-legacy.c");
    addChild("/lib/instances/research/crafting/weapons/maces/beregors-legacy.c",
        "/lib/instances/research/crafting/weapons/maces/beregors-way.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/beregors-fury.c");
    addChild("/lib/instances/research/crafting/weapons/maces/beregors-fury.c",
        "/lib/instances/research/crafting/weapons/maces/beregors-way.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/ardurens-tradition.c");
    addChild("/lib/instances/research/crafting/weapons/maces/ardurens-tradition.c",
        "/lib/instances/research/crafting/weapons/common/folding.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/ardurens-way.c");
    addChild("/lib/instances/research/crafting/weapons/maces/ardurens-way.c",
        "/lib/instances/research/crafting/weapons/maces/ardurens-tradition.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/ardurens-legacy.c");
    addChild("/lib/instances/research/crafting/weapons/maces/ardurens-legacy.c",
        "/lib/instances/research/crafting/weapons/maces/ardurens-way.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/serachs-tradition.c");
    addChild("/lib/instances/research/crafting/weapons/maces/serachs-tradition.c",
        "/lib/instances/research/crafting/weapons/maces/ardurens-legacy.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/serachs-way.c");
    addChild("/lib/instances/research/crafting/weapons/maces/serachs-way.c",
        "/lib/instances/research/crafting/weapons/maces/serachs-tradition.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/serachs-legacy.c");
    addChild("/lib/instances/research/crafting/weapons/maces/serachs-legacy.c",
        "/lib/instances/research/crafting/weapons/maces/serachs-way.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/maegyr-din.c");
    addChild("/lib/instances/research/crafting/weapons/maces/maegyr-din.c",
        "/lib/instances/research/crafting/weapons/maces/serachs-legacy.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/awakening.c");
    addChild("/lib/instances/research/crafting/weapons/maces/awakening.c",
        "/lib/instances/research/crafting/weapons/maces/maegyr-din.c");

    addResearchElement("/lib/instances/research/crafting/weapons/maces/serachs-gift.c");
    addChild("/lib/instances/research/crafting/weapons/maces/serachs-gift.c",
        "/lib/instances/research/crafting/weapons/maces/awakening.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Axe Forging");
    Description("This research tree tracks the knowledge required to craft maces");
    Source("crafting");
    addPrerequisite("weapon smithing", 
        (["type":"skill", "value" : 3]));
    addPrerequisite("/lib/instances/research/crafting/weapons/craftWeapons.c",
        (["type":"research"]));
    addResearchElement("/lib/instances/research/crafting/weapons/maces/craftBasicMace.c");
    TreeRoot("/lib/instances/research/crafting/weapons/maces/craftBasicMace.c");

    CommonResearch();
    CraftMaceResearch();
    Techniques();
}
