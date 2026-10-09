//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-focus.c");

    addChild("/guilds/mage/arcane-theory/arcane-focus.c",
        "/guilds/mage/arcane-theory/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/magical-attunement.c");

    addChild("/guilds/mage/arcane-theory/magical-attunement.c",
        "/guilds/mage/arcane-theory/arcane-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-mind.c");
    addResearchElement("/guilds/mage/arcane-theory/unified-theory.c");

    addChild("/guilds/mage/arcane-theory/arcane-mind.c",
        "/guilds/mage/arcane-theory/magical-attunement.c");
    addChild("/guilds/mage/arcane-theory/unified-theory.c",
        "/guilds/mage/arcane-theory/magical-attunement.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/mage-constitution.c");

    addChild("/guilds/mage/arcane-theory/mage-constitution.c",
        "/guilds/mage/arcane-theory/arcane-mind.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/theoretical-mastery.c");

    addChild("/guilds/mage/arcane-theory/theoretical-mastery.c",
        "/guilds/mage/arcane-theory/mage-constitution.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/spell-memory.c");

    addChild("/guilds/mage/arcane-theory/spell-memory.c",
        "/guilds/mage/arcane-theory/theoretical-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-resilience.c");
    addResearchElement("/guilds/mage/arcane-theory/arcane-synergy.c");

    addChild("/guilds/mage/arcane-theory/arcane-resilience.c",
        "/guilds/mage/arcane-theory/spell-memory.c");
    addChild("/guilds/mage/arcane-theory/arcane-synergy.c",
        "/guilds/mage/arcane-theory/spell-memory.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-vitality.c");

    addChild("/guilds/mage/arcane-theory/arcane-vitality.c",
        "/guilds/mage/arcane-theory/arcane-resilience.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/expanded-reservoir.c");

    addChild("/guilds/mage/arcane-theory/expanded-reservoir.c",
        "/guilds/mage/arcane-theory/arcane-vitality.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-endurance.c");

    addChild("/guilds/mage/arcane-theory/arcane-endurance.c",
        "/guilds/mage/arcane-theory/expanded-reservoir.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/deep-focus.c");
    addResearchElement("/guilds/mage/arcane-theory/cross-school-mastery.c");

    addChild("/guilds/mage/arcane-theory/deep-focus.c",
        "/guilds/mage/arcane-theory/arcane-endurance.c");
    addChild("/guilds/mage/arcane-theory/cross-school-mastery.c",
        "/guilds/mage/arcane-theory/arcane-endurance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/keen-intellect.c");

    addChild("/guilds/mage/arcane-theory/keen-intellect.c",
        "/guilds/mage/arcane-theory/deep-focus.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-mind-ii.c");

    addChild("/guilds/mage/arcane-theory/arcane-mind-ii.c",
        "/guilds/mage/arcane-theory/keen-intellect.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/greater-reservoir.c");

    addChild("/guilds/mage/arcane-theory/greater-reservoir.c",
        "/guilds/mage/arcane-theory/arcane-mind-ii.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/superior-attunement.c");
    addResearchElement("/guilds/mage/arcane-theory/arcane-confluence.c");

    addChild("/guilds/mage/arcane-theory/superior-attunement.c",
        "/guilds/mage/arcane-theory/greater-reservoir.c");
    addChild("/guilds/mage/arcane-theory/arcane-confluence.c",
        "/guilds/mage/arcane-theory/greater-reservoir.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-fortitude.c");

    addChild("/guilds/mage/arcane-theory/arcane-fortitude.c",
        "/guilds/mage/arcane-theory/superior-attunement.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/master-spellcraft.c");

    addChild("/guilds/mage/arcane-theory/master-spellcraft.c",
        "/guilds/mage/arcane-theory/arcane-fortitude.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-recovery.c");

    addChild("/guilds/mage/arcane-theory/arcane-recovery.c",
        "/guilds/mage/arcane-theory/master-spellcraft.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-stamina.c");
    addResearchElement("/guilds/mage/arcane-theory/unified-mastery.c");

    addChild("/guilds/mage/arcane-theory/arcane-stamina.c",
        "/guilds/mage/arcane-theory/arcane-recovery.c");
    addChild("/guilds/mage/arcane-theory/unified-mastery.c",
        "/guilds/mage/arcane-theory/arcane-recovery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/vast-reservoir.c");

    addChild("/guilds/mage/arcane-theory/vast-reservoir.c",
        "/guilds/mage/arcane-theory/arcane-stamina.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-brilliance.c");

    addChild("/guilds/mage/arcane-theory/arcane-brilliance.c",
        "/guilds/mage/arcane-theory/vast-reservoir.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-wisdom.c");

    addChild("/guilds/mage/arcane-theory/arcane-wisdom.c",
        "/guilds/mage/arcane-theory/arcane-brilliance.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/supreme-attunement.c");
    addResearchElement("/guilds/mage/arcane-theory/arcane-enlightenment.c");

    addChild("/guilds/mage/arcane-theory/supreme-attunement.c",
        "/guilds/mage/arcane-theory/arcane-wisdom.c");
    addChild("/guilds/mage/arcane-theory/arcane-enlightenment.c",
        "/guilds/mage/arcane-theory/arcane-wisdom.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortySeventhLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/grand-reservoir.c");

    addChild("/guilds/mage/arcane-theory/grand-reservoir.c",
        "/guilds/mage/arcane-theory/supreme-attunement.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-renewal.c");

    addChild("/guilds/mage/arcane-theory/arcane-renewal.c",
        "/guilds/mage/arcane-theory/grand-reservoir.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/ultimate-spellcraft.c");

    addChild("/guilds/mage/arcane-theory/ultimate-spellcraft.c",
        "/guilds/mage/arcane-theory/arcane-renewal.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyThirdLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-transcendence.c");
    addResearchElement("/guilds/mage/arcane-theory/transcendent-theory.c");

    addChild("/guilds/mage/arcane-theory/arcane-transcendence.c",
        "/guilds/mage/arcane-theory/ultimate-spellcraft.c");
    addChild("/guilds/mage/arcane-theory/transcendent-theory.c",
        "/guilds/mage/arcane-theory/ultimate-spellcraft.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/boundless-reservoir.c");

    addChild("/guilds/mage/arcane-theory/boundless-reservoir.c",
        "/guilds/mage/arcane-theory/arcane-transcendence.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/arcane-perfection.c");

    addChild("/guilds/mage/arcane-theory/arcane-perfection.c",
        "/guilds/mage/arcane-theory/boundless-reservoir.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyNinthLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/archmage-constitution.c");

    addChild("/guilds/mage/arcane-theory/archmage-constitution.c",
        "/guilds/mage/arcane-theory/arcane-perfection.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/mage/arcane-theory/absolute-arcana.c");

    addChild("/guilds/mage/arcane-theory/absolute-arcana.c",
        "/guilds/mage/arcane-theory/archmage-constitution.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Arcane Theory");
    Description("Arcane theory is the foundational study of magical "
        "principles that underlies all schools of the mage's art. "
        "Mastery of this knowledge enhances the precision and potency "
        "of every spell the mage commands.");
    Source("mage");
    addResearchElement("/guilds/mage/arcane-theory/root.c");
    TreeRoot("/guilds/mage/arcane-theory/root.c");

    FirstLevel();
    ThirdLevel();
    FifthLevel();
    SeventhLevel();
    NinthLevel();
    EleventhLevel();
    ThirteenthLevel();
    FifteenthLevel();
    SeventeenthLevel();
    NineteenthLevel();
    TwentyFirstLevel();
    TwentyThirdLevel();
    TwentyFifthLevel();
    TwentySeventhLevel();
    TwentyNinthLevel();
    ThirtyFirstLevel();
    ThirtyThirdLevel();
    ThirtyFifthLevel();
    ThirtySeventhLevel();
    ThirtyNinthLevel();
    FortyFirstLevel();
    FortyThirdLevel();
    FortyFifthLevel();
    FortySeventhLevel();
    FortyNinthLevel();
    FiftyFirstLevel();
    FiftyThirdLevel();
    FiftyFifthLevel();
    FiftySeventhLevel();
    FiftyNinthLevel();
    SixtyFirstLevel();
}
