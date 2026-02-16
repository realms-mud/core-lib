//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/scales-of-the-serpent.c");
    addResearchElement("/guilds/therianthrope/serpent/serpent-strike.c");

    addChild("/guilds/therianthrope/serpent/scales-of-the-serpent.c",
        "/guilds/therianthrope/serpent/serpent-root.c");
    addChild("/guilds/therianthrope/serpent/serpent-strike.c",
        "/guilds/therianthrope/serpent/serpent-root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/serpent-agility.c");
    addResearchElement("/guilds/therianthrope/serpent/fanged-bite.c");

    addChild("/guilds/therianthrope/serpent/serpent-agility.c",
        "/guilds/therianthrope/serpent/scales-of-the-serpent.c");
    addChild("/guilds/therianthrope/serpent/fanged-bite.c",
        "/guilds/therianthrope/serpent/serpent-strike.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/constrict.c");
    addResearchElement("/guilds/therianthrope/serpent/venom-potency.c");

    addChild("/guilds/therianthrope/serpent/constrict.c",
        "/guilds/therianthrope/serpent/serpent-agility.c");
    addChild("/guilds/therianthrope/serpent/venom-potency.c",
        "/guilds/therianthrope/serpent/fanged-bite.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/shed-skin.c");
    addResearchElement("/guilds/therianthrope/serpent/serpentine-fury.c");

    addChild("/guilds/therianthrope/serpent/shed-skin.c",
        "/guilds/therianthrope/serpent/serpent-agility.c");
    addChild("/guilds/therianthrope/serpent/serpentine-fury.c",
        "/guilds/therianthrope/serpent/venom-potency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/coils-of-the-python.c");
    addResearchElement("/guilds/therianthrope/serpent/viper-reflexes.c");

    addChild("/guilds/therianthrope/serpent/coils-of-the-python.c",
        "/guilds/therianthrope/serpent/constrict.c");
    addChild("/guilds/therianthrope/serpent/viper-reflexes.c",
        "/guilds/therianthrope/serpent/serpentine-fury.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/death-roll.c");
    addResearchElement("/guilds/therianthrope/serpent/strike-efficiency.c");

    addChild("/guilds/therianthrope/serpent/death-roll.c",
        "/guilds/therianthrope/serpent/coils-of-the-python.c");
    addChild("/guilds/therianthrope/serpent/strike-efficiency.c",
        "/guilds/therianthrope/serpent/shed-skin.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/hypnotic-gaze.c");
    addResearchElement("/guilds/therianthrope/serpent/venomous-mastery.c");

    addChild("/guilds/therianthrope/serpent/hypnotic-gaze.c",
        "/guilds/therianthrope/serpent/viper-reflexes.c");
    addChild("/guilds/therianthrope/serpent/venomous-mastery.c",
        "/guilds/therianthrope/serpent/death-roll.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/spit-venom.c");
    addResearchElement("/guilds/therianthrope/serpent/serpent-communion.c");

    addChild("/guilds/therianthrope/serpent/spit-venom.c",
        "/guilds/therianthrope/serpent/hypnotic-gaze.c");
    addChild("/guilds/therianthrope/serpent/serpent-communion.c",
        "/guilds/therianthrope/serpent/venomous-mastery.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/strike-speed.c");

    addChild("/guilds/therianthrope/serpent/strike-speed.c",
        "/guilds/therianthrope/serpent/strike-efficiency.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/naga-form.c");
    addResearchElement("/guilds/therianthrope/serpent/toxic-blood.c");

    addChild("/guilds/therianthrope/serpent/naga-form.c",
        "/guilds/therianthrope/serpent/spit-venom.c");
    addChild("/guilds/therianthrope/serpent/toxic-blood.c",
        "/guilds/therianthrope/serpent/serpent-communion.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/world-serpent.c");
    addResearchElement("/guilds/therianthrope/serpent/primordial-scales.c");

    addChild("/guilds/therianthrope/serpent/world-serpent.c",
        "/guilds/therianthrope/serpent/naga-form.c");
    addChild("/guilds/therianthrope/serpent/primordial-scales.c",
        "/guilds/therianthrope/serpent/toxic-blood.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/ophidian-swiftness.c");
    addResearchElement("/guilds/therianthrope/serpent/miasma.c");

    addChild("/guilds/therianthrope/serpent/ophidian-swiftness.c",
        "/guilds/therianthrope/serpent/world-serpent.c");
    addChild("/guilds/therianthrope/serpent/miasma.c",
        "/guilds/therianthrope/serpent/primordial-scales.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/serpent-apotheosis.c");
    addResearchElement("/guilds/therianthrope/serpent/necrotic-venom.c");

    addChild("/guilds/therianthrope/serpent/serpent-apotheosis.c",
        "/guilds/therianthrope/serpent/ophidian-swiftness.c");
    addChild("/guilds/therianthrope/serpent/necrotic-venom.c",
        "/guilds/therianthrope/serpent/miasma.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/leviathan-coil.c");
    addResearchElement("/guilds/therianthrope/serpent/basilisk-gaze.c");

    addChild("/guilds/therianthrope/serpent/leviathan-coil.c",
        "/guilds/therianthrope/serpent/serpent-apotheosis.c");
    addChild("/guilds/therianthrope/serpent/basilisk-gaze.c",
        "/guilds/therianthrope/serpent/necrotic-venom.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FortyNinthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/jormungandr.c");
    addResearchElement("/guilds/therianthrope/serpent/ouroboros.c");

    addChild("/guilds/therianthrope/serpent/jormungandr.c",
        "/guilds/therianthrope/serpent/leviathan-coil.c");
    addChild("/guilds/therianthrope/serpent/ouroboros.c",
        "/guilds/therianthrope/serpent/basilisk-gaze.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFifthLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/eternal-serpent.c");

    addChild("/guilds/therianthrope/serpent/eternal-serpent.c",
        "/guilds/therianthrope/serpent/jormungandr.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyFirstLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/serpent-ascendant.c");

    addChild("/guilds/therianthrope/serpent/serpent-ascendant.c",
        "/guilds/therianthrope/serpent/eternal-serpent.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SixtySeventhLevel()
{
    addResearchElement("/guilds/therianthrope/serpent/world-devourer.c");

    addChild("/guilds/therianthrope/serpent/world-devourer.c",
        "/guilds/therianthrope/serpent/serpent-ascendant.c");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Serpent Form");
    Description("This research tree provides knowledge of transforming into "
        "a sinuous serpent. The serpent form excels at venomous strikes, "
        "constriction, and evasion. Progressive mastery unlocks deadlier "
        "toxins, mesmerizing abilities, and eventually the power of the "
        "mythical world serpent itself.");
    Source("therianthrope");
    addResearchElement("/guilds/therianthrope/serpent/serpent-root.c");
    TreeRoot("/guilds/therianthrope/serpent/serpent-root.c");

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
    ThirtyFirstLevel();
    ThirtyFifthLevel();
    ThirtyNinthLevel();
    FortyThirdLevel();
    FortyNinthLevel();
    FiftyFifthLevel();
    SixtyFirstLevel();
    SixtySeventhLevel();
}
